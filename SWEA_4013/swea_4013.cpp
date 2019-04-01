// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeV9sKkcoDFAVH&categoryId=AWIeV9sKkcoDFAVH&categoryType=CODE
/*
 * swea_4013.cc
 *
 *  Created on: 2019. 4. 01.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <deque>
#include <iostream>

#define N_sign 0
#define S_sign 1

int T, K;
int result;
int cmd_set[5] = {
    0,
};

int dir_x[2] = {1, -1};
struct q_entry {
  int idx, dir;
};
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    std::deque<int> wheel[5];
    memset(cmd_set, 0, sizeof(cmd_set));
    scanf("%d", &K);
    int temp = 0;
    for (int i = 1; i <= 4; i++) {
      for (int j = 0; j < 8; j++) {
        scanf("%d", &temp);
        wheel[i].push_back(temp);
      }
    }

    int in_wheel_num, in_wheel_dir;
    for (int i = 0; i < K; i++) {
      scanf("%d %d", &in_wheel_num, &in_wheel_dir);
      cmd_set[in_wheel_num] = in_wheel_dir;
      for (int j = 0; j < 2; j++) {
        int next_idx, curr_idx = in_wheel_num;
        for (next_idx = curr_idx + dir_x[j]; next_idx <= 4 && next_idx > 0;
             next_idx += dir_x[j]) {
          if (j == 0) {
            if (wheel[curr_idx][2] != wheel[next_idx][6]) {
              cmd_set[next_idx] = cmd_set[curr_idx] * -1;
            } else
              break;
          } else {
            if (wheel[curr_idx][6] != wheel[next_idx][2]) {
              cmd_set[next_idx] = cmd_set[curr_idx] * -1;
            } else
              break;
          }
          curr_idx = next_idx;
        }
      }
      for (int j = 1; j <= 4; j++) {
        if (cmd_set[j] != 0) {
          if (cmd_set[j] == 1) {
            int temp = wheel[j].back();
            wheel[j].pop_back();
            wheel[j].push_front(temp);
            cmd_set[j] = 0;
          } else if (cmd_set[j] == -1) {
            int temp = wheel[j].front();
            wheel[j].pop_front();
            wheel[j].push_back(temp);
            cmd_set[j] = 0;
          } else {
            std::cout << "error [" << cmd_set[j] << "]\n";
          }
        }
      }
    }

    for (int j = 1; j <= 4; j++) {
      if (wheel[j][0] == S_sign) {
        result += (1 << (j - 1));
      }
    }
    printf("#%d %d\n", tc, result);
  }

  return 0;
}