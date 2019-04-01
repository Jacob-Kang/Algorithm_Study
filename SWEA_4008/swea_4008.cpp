// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeRZV6kBUDFAVH&categoryId=AWIeRZV6kBUDFAVH&categoryType=CODE
/*
 * swea_4008.cc
 *
 *  Created on: 2019. 4. 01.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <deque>
#include <iostream>

int T, N, result;
int op[4];
int a[12];
int min_result;
int max_result;
void dfs(int depth, int sum) {
  if (depth == N) {
    max_result = max_result < sum ? sum : max_result;
    min_result = min_result > sum ? sum : min_result;
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (op[i] != 0) {
      op[i]--;
      switch (i) {
        case 0:
          // +
          dfs(depth + 1, sum + a[depth]);
          break;
        case 1:
          // -
          dfs(depth + 1, sum - a[depth]);
          break;
        case 2:
          // *
          dfs(depth + 1, sum * a[depth]);
          break;
        case 3:
          // /
          dfs(depth + 1, sum / a[depth]);
          break;

        default:
          break;
      }
      op[i]++;
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    max_result = -99999;
    min_result = 99999;
    memset(op, 0, sizeof(op));
    scanf("%d", &N);
    scanf("%d %d %d %d", &op[0], &op[1], &op[2], &op[3]);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    dfs(1, a[0]);
    printf("#%d %d\n", tc, abs(max_result - min_result));
  }

  return 0;
}