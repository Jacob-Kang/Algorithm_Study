// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu&categoryId=AV5V4A46AdIDFAWu&categoryType=CODE

/*
 * swea_2115.cc
 *
 *  Created on: 2019. 2. 22.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <algorithm>
#include <iostream>

int T, N, M, C;
int a[10][10];
int report[10][10];
bool visit[10][10];
int basket[5];

int result;

void solve_sum(int start, int c_x, int c_y, int sum, int count) {
  if (count > C) {
    sum -= (basket[start - 1] * basket[start - 1]);
    report[c_y][c_x] = report[c_y][c_x] < sum ? sum : report[c_y][c_x];
    return;
  } else if (start == M) {
    report[c_y][c_x] = report[c_y][c_x] < sum ? sum : report[c_y][c_x];
    return;
  }
  for (int i = start; i < M && count <= C; i++) {
    if (count <= C)
      solve_sum(i + 1, c_x, c_y, sum + basket[i] * basket[i],
                count + basket[i]);
  }
}

void dfs(int c_x, int c_y, int sum, int depth) {
  if (depth == 2) {
    if (result < sum) {
      result = sum;
    }
    return;
  }

  for (int i = c_y; i < N; i++) {
    for (int j = c_x; j <= N - M; j++) {
      if (visit[i][j]) continue;
      if (report[i][j] == -1) {
        for (int k = 0; k < M; k++) {
          basket[k] = a[i][j + k];
        }
        std::sort(basket, basket + M, std::greater<int>());
        solve_sum(0, j, i, 0, 0);
      }
      for (int k = 0; k < M; k++) {
        visit[i][j + k] = true;
      }
      if (c_x + M == N) {
        dfs(0, i + 1, sum + report[i][j], depth + 1);
      } else {
        dfs(j + M, i, sum + report[i][j], depth + 1);
      }
      for (int k = 0; k < M; k++) {
        visit[i][j + k] = false;
      }
    }
    c_x = 0;
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d %d %d", &N, &M, &C);
    memset(a, 0, sizeof(a));
    memset(report, -1, sizeof(report));
    memset(visit, 0, sizeof(visit));
    memset(basket, 0, sizeof(basket));
    result = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    dfs(0, 0, 0, 0);

    printf("#%d %d\n", tc, result);
  }
}