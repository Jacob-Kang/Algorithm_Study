// https://www.acmicpc.net/problem/3190

/*
 * boj_3190.cc
 *
 *  Created on: 2019. 2. 06.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
bool a[101][101];
int X;
char C, way[10001];

bool visit[101][101];
int result = 0;

// 0: >
// 1: V
// 2: <
// 3: ^
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};

struct q_entry {
  int x, y;
};
queue<q_entry> q;

int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &N);
  scanf("%d", &K);
  int a_x, a_y;
  memset(way, 0, sizeof(way));
  for (int i = 0; i < K; i++) {
    scanf("%d %d", &a_y, &a_x);
    a[a_y][a_x] = true;
  }
  scanf("%d", &L);
  for (int i = 0; i < L; i++) {
    scanf("%d %c", &X, &C);
    way[X] = C;
  }

  int c_x = 1;
  int c_y = 1;
  int c_way = 0;
  q.push({c_x, c_y});
  visit[c_y][c_y] = true;
  while (1) {
    c_x = c_x + d_x[c_way];
    c_y = c_y + d_y[c_way];
    q.push({c_x, c_y});
    result++;

    if (visit[c_y][c_x] || c_x < 1 || c_x > N || c_y < 1 ||
        c_y > N)  // 꼬리에 밟히거나, 지도를 벗어남
      break;
    else if (!a[c_y][c_x]) {  // 사과가 없음. 꼬리 다시 줄여야함.
      visit[c_y][c_x] = true;
      visit[q.front().y][q.front().x] = false;
      q.pop();
    } else {
      visit[c_y][c_x] = true;
    }

    if (way[result] != 0) {
      if (way[result] == 'L')
        c_way = (c_way - 1 + 4) % 4;
      else if (way[result] == 'D')
        c_way = (c_way + 1) % 4;
    }
  }
  printf("%d\n", result);
  return 0;
}