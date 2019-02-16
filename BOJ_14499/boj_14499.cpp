// https://www.acmicpc.net/problem/14499

/*
 * boj_14499.cc
 *
 *  Created on: 2019. 2. 06.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <deque>
#include <iostream>

using namespace std;

int N, M, K;
int a[21][21];

int cmd[10000];
int num_front, num_back;
// 1: >
// 2: <
// 3: ^
// 4: V
int d_x[5] = {0, 1, -1, 0, 0};
int d_y[5] = {0, 0, 0, -1, 1};

deque<int> q_col;
deque<int> q_row;

int main() {
  freopen("input.txt", "r", stdin);
  int c_x, c_y;
  scanf("%d %d %d %d %d", &N, &M, &c_y, &c_x, &K);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < K; i++) {
    scanf("%d", &cmd[i]);
  }
  for (int i = 0; i < 4; i++) {
    q_col.push_back(0);
    q_row.push_back(0);
  }

  int temp_x, temp_y;
  for (int i = 0; i < K; i++) {
    temp_x = c_x;
    temp_y = c_y;
    c_x = c_x + d_x[cmd[i]];
    c_y = c_y + d_y[cmd[i]];

    int temp;
    if (c_x >= 0 && c_x < M && c_y >= 0 && c_y < N) {
      if (cmd[i] == 1) {
        // >
        temp = q_row.back();
        q_row.push_front(temp);
        q_row.pop_back();
        if (a[c_y][c_x] == 0)
          a[c_y][c_x] = q_row[3];
        else {
          q_row[3] = a[c_y][c_x];
          a[c_y][c_x] = 0;
        }
        q_col[1] = q_row[1];
        q_col[3] = q_row[3];
      } else if (cmd[i] == 2) {
        // <
        temp = q_row.front();
        q_row.push_back(temp);
        q_row.pop_front();

        if (a[c_y][c_x] == 0)
          a[c_y][c_x] = q_row[3];
        else {
          q_row[3] = a[c_y][c_x];
          a[c_y][c_x] = 0;
        }
        q_col[1] = q_row[1];
        q_col[3] = q_row[3];
      } else if (cmd[i] == 3) {
        // ^
        temp = q_col.back();
        q_col.push_front(temp);
        q_col.pop_back();
        if (a[c_y][c_x] == 0)
          a[c_y][c_x] = q_col[3];
        else {
          q_col[3] = a[c_y][c_x];
          a[c_y][c_x] = 0;
        }
        q_row[1] = q_col[1];
        q_row[3] = q_col[3];
      } else if (cmd[i] == 4) {
        // V
        temp = q_col.front();
        q_col.push_back(temp);
        q_col.pop_front();
        if (a[c_y][c_x] == 0)
          a[c_y][c_x] = q_col[3];
        else {
          q_col[3] = a[c_y][c_x];
          a[c_y][c_x] = 0;
        }
        q_row[1] = q_col[1];
        q_row[3] = q_col[3];
      }
      printf("%d\n", q_col[1]);
    } else {
      // 지도를 벗어나는 경우 출력하지 않고, 이전 좌표로 원상복귀
      c_x = temp_x;
      c_y = temp_y;
    }
  }
  return 0;
}