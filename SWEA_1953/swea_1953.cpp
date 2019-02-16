// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq&categoryId=AV5PpLlKAQ4DFAUq&categoryType=CODE

/*
 * swea_1953.cc
 *
 *  Created on: 2019. 2. 16.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, N, M, S_X, S_Y, L;
int a[52][52];
bool visit[52][52];
int result;

// 0: > 1
// 1: V 2
// 2: < 0
// 3: ^ 3

int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

struct q_entry {
  int x, y, depth;
};
std::queue<q_entry> q;

// 1: +  (1 3 6 7)   (1 2 4 7)   (1 3 4 5)   (1 2 5 6)
// 2: I  ()          (1 2 4 7)   ()          (1 2 5 6)
// 3: -  (1 3 6 7)   ()          (1 3 4 5)   ()
// 4: ㄴ  (1 3 6 7)   ()          ()          (1 2 5 6)
// 5: r  (1 3 6 7)   (1 2 4 7)   ()          ()
// 6: ㄱ  ()          (1 2 4 7)   (1 3 4 5)   ()
// 7: L/  ()          ()          (1 3 4 5)  (1 2 5 6)
bool check_path(int x, int y, int way) {
  if (a[y][x] == 1) {
    switch (way) {
      case 0:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 3 &&
            a[y + d_y[way]][x + d_x[way]] != 6 &&
            a[y + d_y[way]][x + d_x[way]] != 7)
          return false;
        else
          return true;
      case 1:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 2 &&
            a[y + d_y[way]][x + d_x[way]] != 4 &&
            a[y + d_y[way]][x + d_x[way]] != 7)
          return false;
        else
          return true;
      case 2:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 3 &&
            a[y + d_y[way]][x + d_x[way]] != 4 &&
            a[y + d_y[way]][x + d_x[way]] != 5)
          return false;
        else
          return true;
      case 3:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 2 &&
            a[y + d_y[way]][x + d_x[way]] != 5 &&
            a[y + d_y[way]][x + d_x[way]] != 6)
          return false;
        else
          return true;
      default:
        break;
    }
  } else if (a[y][x] == 2) {
    switch (way) {
      case 0:
        return false;
      case 1:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 2 &&
            a[y + d_y[way]][x + d_x[way]] != 4 &&
            a[y + d_y[way]][x + d_x[way]] != 7)
          return false;
        else
          return true;
      case 2:
        return false;
      case 3:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 2 &&
            a[y + d_y[way]][x + d_x[way]] != 5 &&
            a[y + d_y[way]][x + d_x[way]] != 6)
          return false;
        else
          return true;
      default:
        break;
    }
  } else if (a[y][x] == 3) {
    switch (way) {
      case 0:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 3 &&
            a[y + d_y[way]][x + d_x[way]] != 6 &&
            a[y + d_y[way]][x + d_x[way]] != 7)
          return false;
        else
          return true;
      case 1:
        return false;
      case 2:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 3 &&
            a[y + d_y[way]][x + d_x[way]] != 4 &&
            a[y + d_y[way]][x + d_x[way]] != 5)
          return false;
        else
          return true;
      case 3:
        return false;
      default:
        break;
    }
  }
  if (a[y][x] == 4) {
    switch (way) {
      case 0:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 3 &&
            a[y + d_y[way]][x + d_x[way]] != 6 &&
            a[y + d_y[way]][x + d_x[way]] != 7)
          return false;
        else
          return true;
      case 1:
        return false;
      case 2:
        return false;
      case 3:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 2 &&
            a[y + d_y[way]][x + d_x[way]] != 5 &&
            a[y + d_y[way]][x + d_x[way]] != 6)
          return false;
        else
          return true;
      default:
        break;
    }
  } else if (a[y][x] == 5) {
    switch (way) {
      case 0:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 3 &&
            a[y + d_y[way]][x + d_x[way]] != 6 &&
            a[y + d_y[way]][x + d_x[way]] != 7)
          return false;
        else
          return true;
      case 1:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 2 &&
            a[y + d_y[way]][x + d_x[way]] != 4 &&
            a[y + d_y[way]][x + d_x[way]] != 7)
          return false;
        else
          return true;
      case 2:
        return false;
      case 3:
        return false;
      default:
        break;
    }
  } else if (a[y][x] == 6) {
    switch (way) {
      case 0:
        return false;
      case 1:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 2 &&
            a[y + d_y[way]][x + d_x[way]] != 4 &&
            a[y + d_y[way]][x + d_x[way]] != 7)
          return false;
        else
          return true;
      case 2:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 3 &&
            a[y + d_y[way]][x + d_x[way]] != 4 &&
            a[y + d_y[way]][x + d_x[way]] != 5)
          return false;
        else
          return true;
      case 3:
        return false;
      default:
        break;
    }
  } else if (a[y][x] == 7) {
    switch (way) {
      case 0:
        return false;
      case 1:
        return false;
      case 2:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 3 &&
            a[y + d_y[way]][x + d_x[way]] != 4 &&
            a[y + d_y[way]][x + d_x[way]] != 5)
          return false;
        else
          return true;
      case 3:
        if (a[y + d_y[way]][x + d_x[way]] != 1 &&
            a[y + d_y[way]][x + d_x[way]] != 2 &&
            a[y + d_y[way]][x + d_x[way]] != 5 &&
            a[y + d_y[way]][x + d_x[way]] != 6)
          return false;
        else
          return true;
      default:
        break;
    }
  }
  return false;
}
void bfs(int depth) {
  int c_x, c_y, c_depth;
  int temp_x, temp_y;
  while (!q.empty()) {
    c_x = q.front().x;
    c_y = q.front().y;
    c_depth = q.front().depth;
    q.pop();
    if (c_depth == depth - 1) {
      continue;
    }
    for (int i = 0; i < 4; i++) {
      temp_x = c_x + d_x[i];
      temp_y = c_y + d_y[i];
      if (temp_x >= 0 && temp_x < M && temp_y >= 0 && temp_y < N &&
          !visit[temp_y][temp_x] && a[temp_y][temp_x] > 0 &&
          a[temp_y][temp_x] < 8) {
        if (check_path(c_x, c_y, i)) {
          visit[temp_y][temp_x] = true;
          result++;
          q.push({temp_x, temp_y, c_depth + 1});
        }
      }
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    memset(a, 0, sizeof(a));
    memset(visit, 0, sizeof(visit));
    result = 0;
    scanf("%d %d %d %d %d", &N, &M, &S_Y, &S_X, &L);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    if (a[S_Y][S_X] != 0) {
      visit[S_Y][S_X] = true;
      result = 1;
      q.push({S_X, S_Y, 0});
      bfs(L);
    }
    printf("#%d %d\n", tc, result);
  }
  return 0;
}