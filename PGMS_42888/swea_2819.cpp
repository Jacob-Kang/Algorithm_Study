// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7I5fgqEogDFAXB&

/*
 * swea_2819.cpp
 *
 *  Created on: 2019. 1. 30.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;

int t, tc, n, m;
int result;
int a[4][4];
bool visit[10000000];

// 1: >
// 2: V
// 3: <
// 0: ^
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct p {
  int x, y, w, mem, count;
};
queue<p> q;

int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &t);
  for (tc = 1; tc <= t; tc++) {
    memset(visit, 0, sizeof(visit));
    result = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        scanf("%d", &a[i][j]);
        for (int k = 0; k < 4; k++) {
          q.push({j, i, k, a[i][j], 1});
        }
      }
    }
    while (q.size()) {
      int x = q.front().x;
      int y = q.front().y;
      int w = q.front().w;
      int mem = q.front().mem;
      int cnt = q.front().count;
      q.pop();
      x = x + dx[w];
      y = y + dy[w];
      if ((x < 0 || x > 3 || y < 0 || y > 3)) continue;
      mem = mem * 10 + a[y][x];
      if (cnt == 6) {
        if (visit[mem] == false) {
          result++;
          visit[mem] = true;
        }
        continue;
      }
      for (int i = 0; i < 4; i++) {
        q.push({x, y, i, mem, cnt + 1});
      }
    }
    printf("#%d %d\n", tc, result);
  }
  return 0;
}