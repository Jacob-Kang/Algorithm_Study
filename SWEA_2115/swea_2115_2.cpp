// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu&categoryId=AV5V4A46AdIDFAWu&categoryType=CODE
/*
 * swea_2115.cpp
 *
 *  Created on: 2019. 4. 5.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <algorithm>
#include <iostream>
// #include <queue>
#include <vector>
int T, N, M, C;
int result;
int map[10][10];
std::vector<int> basket;
int answer;

void solve_sum(int start, int limit, int total) {
  if (limit > C || start == basket.size()) {
    answer = answer < total ? total : answer;
    return;
  }
  for (int start_idx = start; start_idx < basket.size(); start_idx++) {
    if (limit + basket[start_idx] > C)
      solve_sum(start_idx + 1, limit + basket[start_idx], total);
    else
      solve_sum(start_idx + 1, limit + basket[start_idx],
                total + basket[start_idx] * basket[start_idx]);
  }
}
void dfs(int depth, int start_y, int start_x, int total) {
  if (depth == 2) {
    result = result < total ? total : result;
    return;
  }
  int j = start_x;
  for (int i = start_y; i < N; i++) {
    for (; j <= N - M; j++) {
      while (!basket.empty()) basket.pop_back();
      for (int k = 0; k < M; k++) {
        basket.push_back(map[i][j + k]);
      }
      answer = 0;
      std::sort(basket.begin(), basket.end(), std::greater<int>());
      solve_sum(0, 0, 0);

      if (j + M > N - M)
        dfs(depth + 1, i + 1, 0, total + answer);
      else
        dfs(depth + 1, i, j + M, total + answer);
    }
    j = 0;
  }
}
int main(void) {
  int T;
  freopen("input2.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    memset(map, 0, sizeof(map));
    scanf("%d %d %d", &N, &M, &C);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &map[i][j]);
      }
    }

    dfs(0, 0, 0, 0);
    printf("#%d %d\n", tc, result);
  }
  return 0;
}