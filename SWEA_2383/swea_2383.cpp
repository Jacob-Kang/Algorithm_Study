// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5-BEE6AK0DFAVl&categoryId=AV5-BEE6AK0DFAVl&categoryType=CODE

/*
 * swea_2383.cpp
 *
 *  Created on: 2019. 3. 07.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <algorithm>
#include <deque>
#include <iostream>

int t, N;
int result;
int a[10][10];

int num_person, num_stair;
int a_person[10][2];
int a_stair[2][3];
struct p {
  int length, count;
};

std::deque<p> q_list[2];
std::deque<p> q_b;

bool cmp(p a, p b) { return a.length < b.length; }

int solve() {
  std::deque<p> temp_q[2];
  for (int i = 0; i < 2; i++) {
    temp_q[i] = q_list[i];
    std::sort(temp_q[i].begin(), temp_q[i].end(), cmp);
  }
  int time = 0;
  while (!temp_q[0].empty() || !temp_q[1].empty()) {
    for (int i = 0; i < 2; i++) {
      if (temp_q[i].empty()) continue;
      if (temp_q[i].front().length >= time) continue;
      for (int j = 0; j < 3 && temp_q[i].size() - j > 0; j++) {
        if (temp_q[i][j].length < time) {
          temp_q[i][j].count++;
        }
      }
      while (temp_q[i].front().count == a_stair[i][2] && !temp_q[i].empty()) {
        temp_q[i].pop_front();
      }
    }
    time++;
  }
  return time;
}
void dfs(int depth) {
  if (depth == num_person) {
    int temp_result = solve();
    result = result < temp_result ? result : temp_result;
    return;
  }
  for (int i = 0; i < 2; i++) {
    int a_path = abs(a_stair[i][0] - a_person[depth][0]) +
                 abs(a_stair[i][1] - a_person[depth][1]);
    q_list[i].push_back({a_path, 0});
    dfs(depth + 1);
    q_list[i].pop_back();
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    result = 9999;
    num_person = 0;
    num_stair = 0;
    memset(a, 0, sizeof(a));
    memset(a_person, 0, sizeof(a_person));
    memset(a_stair, 0, sizeof(a_stair));
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &a[i][j]);
        if (a[i][j] == 1) {
          a_person[num_person][0] = j;
          a_person[num_person][1] = i;
          num_person++;
        } else if (a[i][j] > 1) {
          a_stair[num_stair][0] = j;
          a_stair[num_stair][1] = i;
          a_stair[num_stair][2] = a[i][j];
          num_stair++;
        }
      }
    }
    dfs(0);
    printf("#%d %d\n", tc, result);
  }
  return 0;
}