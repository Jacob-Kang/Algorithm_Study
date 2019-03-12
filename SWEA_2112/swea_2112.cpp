// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu&categoryId=AV5V1SYKAaUDFAWu&categoryType=CODE

/*
 * swea_2112.cc
 *
 *  Created on: 2019. 3. 11.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <algorithm>
#include <deque>
#include <iostream>

int T, D, W, K;
int result;
bool a[13][20];
bool visit[13];

bool check() {
  int check_counter = 0;
  for (int line = 0; line < W; line++) {
    bool is_skip = false;
    for (int i = 1; i < D && check_counter != K - 1 && !is_skip; i++) {
      if (a[i][line] == a[i - 1][line])
        check_counter++;
      else
        check_counter = 0;
      if (D - i < K && check_counter == 0) is_skip = true;
    }
    if (check_counter < K - 1) return false;
    check_counter = 0;
  }
  return true;
}

void change(int chang_Y, int color) {
  if (color == 2) return;
  for (int i = 0; i < W; i++) {
    a[chang_Y][i] = color;
  }
}

void print_map() {
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < W; j++) {
      std::cout << a[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
void dfs(int depth, int count, bool is_orig) {
  if (!is_orig && check()) {
    result = result > count ? count : result;
    return;
  }
  if (depth == D) return;
  if (count == result) return;

  int temp_line[20];
  for (int j = 0; j < W; j++) temp_line[j] = a[depth][j];
  for (int color = 2; color >= 0; color--) {
    change(depth, color);
    // print_map();
    if (color < 2)
      dfs(depth + 1, count + 1, false);
    else
      dfs(depth + 1, count, true);
  }
  for (int j = 0; j < W; j++) a[depth][j] = temp_line[j];
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d\n", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 9999;
    memset(a, 0, sizeof(a));
    memset(visit, 0, sizeof(visit));
    scanf("%d %d %d\n", &D, &W, &K);
    for (int i = 0; i < D; i++) {
      for (int j = 0; j < W; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    if (K > 1)
      dfs(0, 0, false);
    else
      result = 0;
    printf("#%d %d\n", tc, result);
  }
  return 0;
}
