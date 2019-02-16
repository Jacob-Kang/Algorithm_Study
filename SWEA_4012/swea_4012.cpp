// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeUtVakTMDFAVH&categoryId=AWIeUtVakTMDFAVH&categoryType=CODE

/*
 * swea_4012.cc
 *
 *  Created on: 2019. 2. 15.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <deque>
#include <iostream>

using namespace std;

int T, N, S[50][50];
bool visit[50];
int result;

// 0: >
// 1: V
// 2: <
// 3: ^

int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

struct q_entry {
  int x, y;
  unsigned int max, min;
};

void dfs(int start, int num_N) {
  if (num_N == N / 2) {
    int a1 = 0, a2 = 0;
    std::deque<int> q1;
    std::deque<int> q2;
    for (int i = 0; i < N; i++) {
      if (visit[i]) {
        q1.push_back(i);
      } else {
        q2.push_back(i);
      }
    }
    for (int i = 0; i < (int)q1.size(); i++) {
      for (int j = 0; j < (int)q1.size(); j++) {
        a1 += S[q1[i]][q1[j]];
      }
    }
    for (int i = 0; i < (int)q2.size(); i++) {
      for (int j = 0; j < (int)q2.size(); j++) {
        a2 += S[q2[i]][q2[j]];
      }
    }
    result = result > abs(a1 - a2) ? abs(a1 - a2) : result;
    return;
  }
  for (int i = start; i < N; i++) {
    if (!visit[i]) {
      visit[i] = true;
      num_N++;
      dfs(i + 1, num_N);
      num_N--;
      visit[i] = false;
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);

  for (int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    result = 999999;
    memset(S, 0, sizeof(S));
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &S[i][j]);
      }
    }
    dfs(0, 0);
    printf("#%d %d\n", tc, result);
  }
  return 0;
}
