// https://www.acmicpc.net/problem/17136

/*
 * boj_17136.cpp
 *
 *  Created on: 2019. 4. 5.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>

int result;
int map[10][10];
int total_area;
int remain_shape[6] = {0, 5, 5, 5, 5};
struct loc_entry {
  int x, y;
};

bool fill_shape(int start_x, int start_y, int shape, bool is_return) {
  for (int i = start_y; i < start_y + shape; i++) {
    for (int j = start_x; j < start_x + shape; j++) {
      if (is_return)
        map[i][j] = 1;
      else
        map[i][j] = 10 + shape;
    }
  }
}
bool check_able(int start_x, int start_y, int shape) {
  for (int i = start_y; i < start_y + shape; i++) {
    for (int j = start_x; j < start_x + shape; j++) {
      if (map[i][j] != 1) {
        return false;
      }
    }
  }
  return true;
}

loc_entry find_next() {
  loc_entry ret_val;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (map[i][j] == 1) {
        ret_val.x = j;
        ret_val.y = i;
        return ret_val;
      }
    }
  }
  return ret_val;
}

void dfs(int start_x, int start_y, int depth, int total) {
  if (result < depth) return;
  if (total == total_area) {
    result = depth;
    return;
  }
  for (int i = 5; i > 0; i--) {
    if (remain_shape[i] > 0 && check_able(start_x, start_y, i)) {
      fill_shape(start_x, start_y, i, false);
      remain_shape[i]--;
      loc_entry next_loc = find_next();
      dfs(next_loc.x, next_loc.y, depth + 1, total + i * i);
      remain_shape[i]++;
      fill_shape(start_x, start_y, i, true);
    }
  }
}
int main(void) {
  int T;
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 99999;
    total_area = 0;
    for (int i = 1; i < 6; i++) remain_shape[i] = 5;
    bool is_first = true;
    loc_entry start_loc;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        scanf("%d", &map[i][j]);
        if (map[i][j] == 1) {
          if (is_first) {
            start_loc.x = j;
            start_loc.y = i;
            is_first = false;
          }
          total_area++;
        }
      }
    }

    dfs(start_loc.x, start_loc.y, 0, 0);
    if (result == 99999) result = -1;
    printf("#%d %d\n", tc, result);
  }
  // printf("%d\n", result);
  return 0;
}