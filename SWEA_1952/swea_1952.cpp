// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq&categoryId=AV5PpFQaAQMDFAUq&categoryType=CODE&&&
/*
 * swea_1952.cc
 *
 *  Created on: 2019. 4. 2.
 *      Author: Chulho Kang
 */

#include <iostream>

int T, result;
int fee[4];
int plan[13];
int last_month;
int d_x[4] = {1, 1, 3, 12};
int min_fee;
void dfs(int start, int total) {
  if (start > last_month) {
    result = result > total ? total : result;
    return;
  }
  for (; start <= 12 && plan[start] != 0; start++) {
    if (plan[start] != 0) break;
  }
  for (int i = 0; i < 4; i++) {
    switch (i) {
      case 0:
        dfs(start + 1, total + fee[i] * plan[start]);
        break;
      case 1:
        dfs(start + 1, total + fee[i]);
        break;
      case 2:
        dfs(start + 3, total + fee[i]);
        break;
      case 3:
        dfs(start + 12, total + fee[i]);
        break;
      default:
        break;
    }
  }
}
int main(void) {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 99999;
    memset(fee, 0, sizeof(fee));
    memset(plan, 0, sizeof(plan));
    for (int i = 0; i < 4; i++) scanf("%d", &fee[i]);
    bool is_first = true;
    int start_month;
    for (int i = 1; i <= 12; i++) {
      scanf("%d", &plan[i]);
      if (is_first && plan[i] != 0) {
        start_month = i;
        is_first = false;
      }
    }
    for (last_month = 12; last_month > 0; last_month--) {
      if (plan[last_month] != 0) break;
    }
    dfs(start_month, 0);
    printf("#%d %d\n", tc, result);
  }
  return 0;
}