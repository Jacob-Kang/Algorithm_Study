// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu&categoryId=AV5V61LqAf8DFAWu&categoryType=CODE
/*
 * swea_2117.cc
 *
 *  Created on: 2019. 4. 3.
 *      Author: Chulho Kang
 */

#include <math.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

int T, N, M;
int result;
int map[20][20];

struct q_entry {
  int x, y;
};
std::vector<q_entry> house;

int solve(int K) {
  int protect_count = 0;
  int cost = K * K + (K - 1) * (K - 1);
  int result = 0;
  for (int cur_y = 0; cur_y < N; cur_y++) {
    for (int cur_x = 0; cur_x < N; cur_x++) {
      protect_count = 0;
      // std::cout << "### [" << cur_x << ", " << cur_y << "] ### " <<
      // std::endl;
      for (int k = 0; k < (int)house.size(); k++) {
        if (abs(cur_x - house[k].x) + abs(cur_y - house[k].y) <= K - 1) {
          protect_count++;
          // std::cout << house[k].x << ", " << house[k].y << std::endl;
        }
      }
      if (M * protect_count - cost >= 0)
        result = result < protect_count ? protect_count : result;
    }
  }
  return result;
}
int main(void) {
  int T;
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    memset(map, 0, sizeof(map));
    while (!house.empty()) house.pop_back();
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &map[i][j]);
        if (map[i][j] != 0) house.push_back({j, i});
      }
    }
    result = 1;
    int i = 2;
    while (i < 22) {
      int temp_result = solve(i);
      result = result < temp_result ? temp_result : result;
      // if (temp_result < 1) break;
      i++;
    }
    printf("#%d %d\n", tc, result);
  }
  return 0;
}