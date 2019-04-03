// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRDL1aeugDFAUo&categoryId=AWXRDL1aeugDFAUo&categoryType=CODE
/*
 * swea_5644.cpp
 *
 *  Created on: 2019. 4. 2.
 *      Author: Chulho Kang
 */
#include <algorithm>
#include <iostream>
#include <vector>

#define MAX_WIDTH 10
struct ap_entry {
  int idx, p;
};

// 0: 0
// 1: ^
// 2: >
// 3: V
// 4: <
int d_x[5] = {0, 0, 1, 0, -1};
int d_y[5] = {0, -1, 0, 1, 0};

int main(void) {
  int T;
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    std::vector<ap_entry> a[12][12];
    int M, A;
    int cmd[2][101];
    int ap[8][2];
    int c[8];
    int p[8];

    cmd[0][0] = 0;
    cmd[1][0] = 0;

    scanf("%d %d", &M, &A);
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= M; j++) {
        scanf("%d", &cmd[i][j]);
      }
    }
    for (int i = 0; i < A; i++) {
      scanf("%d %d %d %d", &ap[i][0], &ap[i][1], &c[i], &p[i]);
    }

    for (int i = 0; i < A; i++) {
      for (int j = 1; j <= c[i]; j++) {
        for (int k = 0; k < (c[i] * 2 + 1) - 2 * j; k++) {
          int temp_x, temp_y;
          temp_x = ap[i][0] - c[i] + j + k;
          temp_y = ap[i][1] - j;
          if (temp_x > 0 && temp_x <= MAX_WIDTH && temp_y > 0 &&
              temp_y <= MAX_WIDTH)
            a[temp_y][temp_x].push_back({i, p[i]});
          temp_y = ap[i][1] + j;
          if (temp_x > 0 && temp_x <= MAX_WIDTH && temp_y > 0 &&
              temp_y <= MAX_WIDTH)
            a[temp_y][temp_x].push_back({i, p[i]});
        }
      }
      for (int j = 0; j < c[i] * 2 + 1; j++) {
        int temp_y = ap[i][1];
        int temp_x = ap[i][0] - c[i] + j;
        if (temp_x > 0 && temp_x <= MAX_WIDTH)
          a[temp_y][temp_x].push_back({i, p[i]});
      }
    }

    int cur_time = 0;
    int total = 0;
    int a_x = 1;
    int a_y = 1;
    int b_x = 10;
    int b_y = 10;
    while (cur_time <= M) {
      a_x += d_x[cmd[0][cur_time]];
      a_y += d_y[cmd[0][cur_time]];
      b_x += d_x[cmd[1][cur_time]];
      b_y += d_y[cmd[1][cur_time]];
      int bak_total = total;
      if (!a[a_y][a_x].empty() && !a[b_y][b_x].empty()) {
        for (int i = 0; i < (int)a[a_y][a_x].size(); i++) {
          for (int j = 0; j < (int)a[b_y][b_x].size(); j++) {
            int temp_total = bak_total + a[a_y][a_x][i].p;
            if (a[a_y][a_x][i].idx != a[b_y][b_x][j].idx) {
              temp_total += a[b_y][b_x][j].p;
            }
            total = total < temp_total ? temp_total : total;
          }
        }
      } else if (!a[a_y][a_x].empty()) {
        for (int i = 0; i < (int)a[a_y][a_x].size(); i++) {
          int temp_total = bak_total + a[a_y][a_x][i].p;
          total = total < temp_total ? temp_total : total;
        }
      } else if (!a[b_y][b_x].empty()) {
        for (int i = 0; i < (int)a[b_y][b_x].size(); i++) {
          int temp_total = bak_total + a[b_y][b_x][i].p;
          total = total < temp_total ? temp_total : total;
        }
      }
      cur_time++;
    }
    printf("#%d %d\n", tc, total);
  }
  return 0;
}