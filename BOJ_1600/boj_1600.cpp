// https://www.acmicpc.net/problem/1600

/*
 * boj_1600.cc
 *
 *  Created on: 2019. 2. 11.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;

int K, W, H;
bool a[200][200];
bool visit[200][200][30];
int result;

// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

int d_hx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int d_hy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

struct q_entry {
  int x, y, k_, depth;
};
queue<q_entry> q;
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &K);
  scanf("%d %d", &W, &H);
  memset(a, 0, sizeof(a));
  memset(visit, 0, sizeof(visit));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      std::cin >> a[i][j];
    }
  }
  int c_x = 0, c_y = 0, c_k, c_depth;
  int temp_x = 0, temp_y = 0;
  visit[c_y][c_x][K] = true;
  q.push({c_x, c_y, K, 0});
  bool able = false;
  while (!q.empty()) {
    c_x = q.front().x;
    c_y = q.front().y;
    c_k = q.front().k_;
    c_depth = q.front().depth;
    q.pop();
    if (c_x == W - 1 && c_y == H - 1) {
      able = true;
      result = c_depth;
      break;
    }
    if (c_k > 0) {
      for (int i = 0; i < 8; i++) {
        temp_x = c_x + d_hx[i];
        temp_y = c_y + d_hy[i];
        if (temp_x >= 0 && temp_x < W && temp_y >= 0 && temp_y < H &&
            a[temp_y][temp_x] == false &&
            visit[temp_y][temp_x][c_k - 1] == false) {
          visit[temp_y][temp_x][c_k - 1] = true;
          q.push({temp_x, temp_y, c_k - 1, c_depth + 1});
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      temp_x = c_x + d_x[i];
      temp_y = c_y + d_y[i];
      if (temp_x >= 0 && temp_x < W && temp_y >= 0 && temp_y < H &&
          a[temp_y][temp_x] == false && visit[temp_y][temp_x][c_k] == false) {
        visit[temp_y][temp_x][c_k] = true;
        q.push({temp_x, temp_y, c_k, c_depth + 1});
      }
    }
  }
  if (able)
    printf("%d\n", result);
  else
    printf("-1\n");

  return 0;
}
