// https://www.acmicpc.net/problem/1012

/*
 * boj_1012.cc
 *
 *  Created on: 2019. 1. 31.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;

int T, N, M, K;
bool a[50][50];

bool visit[50][50];
int result;

struct q_entry {
  int x, y;
};
std::queue<q_entry> q;

// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

void bfs() {
  while (!q.empty()) {
    int x = q.front().x;
    int y = q.front().y;
    q.pop();
    int temp_x;
    int temp_y;
    for (int i = 0; i < 4; i++) {
      temp_x = x + d_x[i];
      temp_y = y + d_y[i];
      if (temp_x >= 0 && temp_x < M && temp_y >= 0 && temp_y < N &&
          a[temp_y][temp_x] == true && visit[temp_y][temp_x] == false) {
        visit[temp_y][temp_x] = true;
        q.push({temp_x, temp_y});
      }
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    memset(a, 0, sizeof(a));
    memset(visit, 0, sizeof(visit));
    result = 0;
    scanf("%d %d %d", &M, &N, &K);
    int x, y;
    for (int j = 0; j < K; j++) {
      scanf("%d %d", &x, &y);
      a[y][x] = true;
    }
    for (int k = 0; k < N; k++) {
      for (int l = 0; l < M; l++) {
        if (a[k][l] == true && visit[k][l] == false) {
          visit[k][l] = true;
          q.push({l, k});
          bfs();
          result++;
        }
      }
    }
    printf("%d\n", result);
  }
  return 0;
}