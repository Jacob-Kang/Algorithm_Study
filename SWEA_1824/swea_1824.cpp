// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4yLUiKDUoDFAUx&categoryId=AV4yLUiKDUoDFAUx&categoryType=CODE

/*
 * swea_1824.cpp
 *
 *  Created on: 2019. 1. 29.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>
using namespace std;

int t, tc, n, m;
char a[21][21];
int visit[21][21][4][16];

// 1: >
// 2: V
// 3: <
// 0: ^
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct p {
  int x, y, w, mem;
};
queue<p> q;

int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &t);
  for (tc = 1; tc <= t; tc++) {
    scanf("%d %d", &n, &m);
    bool able = false;
    for (int i = 0; i < n; i++) {
      scanf("%s", a[i]);
      if (!able) {
        for (int j = 0; j < m; j++)
          if (a[i][j] == '@') able = true;
      }
    }
    if (able) q.push({0, 0, 1, 0});
    visit[0][0][1][0] = tc;
    bool f = false;
    while (q.size()) {
      int x = q.front().x;
      int y = q.front().y;
      int w = q.front().w;
      int mem = q.front().mem;
      q.pop();
      if (a[y][x] == '<')
        w = 3;
      else if (a[y][x] == '>')
        w = 1;
      else if (a[y][x] == '^')
        w = 0;
      else if (a[y][x] == 'v')
        w = 2;
      else if (a[y][x] == '_')
        if (mem == 0)
          w = 1;
        else
          w = 3;
      else if (a[y][x] == '|')
        if (mem == 0)
          w = 2;
        else
          w = 0;
      else if (a[y][x] == '?') {
        for (int i = 0; i < 4; i++) {
          int nx = (x + dx[i] + m) % m;
          int ny = (y + dy[i] + n) % n;
          if (visit[nx][ny][i][mem] == tc) continue;
          visit[nx][ny][i][mem] = tc;
          q.push({nx, ny, i, mem});
        }
        continue;
      } else if (a[y][x] == '@') {
        f = true;
        while (q.size()) q.pop();
        break;
      } else if (a[y][x] >= '0' && a[y][x] <= '9')
        mem = a[y][x] - '0';
      else if (a[y][x] == '+')
        mem = (mem + 1) % 16;
      else if (a[y][x] == '-')
        mem = (mem + 15) % 16;
      x = (x + dx[w] + m) % m;
      y = (y + dy[w] + n) % n;
      if (visit[x][y][w][mem] == tc) continue;
      visit[x][y][w][mem] = tc;
      q.push({x, y, w, mem});
    }
    printf("#%d ", tc);
    if (f)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}