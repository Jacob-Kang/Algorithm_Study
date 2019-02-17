// https://www.acmicpc.net/problem/1697

/*
 * boj_1697.cpp
 *
 *  Created on: 2019. 1. 31.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;

int X, X2;
bool visit[200000];
int result;

struct q_entry {
  int x, total;
};

std::queue<q_entry> q;

void bfs() {
  while (!q.empty()) {
    int x = q.front().x;
    int total = q.front().total;
    q.pop();
    if (x == X2) {
      result = total;
      return;
    }
    if (x < X2) {
      if (!visit[x + 1]) {
        visit[x + 1] = true;
        q.push({x + 1, total + 1});
      }
      if (!visit[x * 2]) {
        visit[x * 2] = true;
        q.push({x * 2, total + 1});
      }
      if (x > 0) {
        if (!visit[x - 1]) {
          visit[x - 1] = true;
          q.push({x - 1, total + 1});
        }
      }
    } else {
      if (!visit[x - 1]) {
        visit[x - 1] = true;
        q.push({x - 1, total + 1});
      }
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  std::cin >> X >> X2;
  memset(visit, 0, sizeof(visit));
  visit[X] = true;
  q.push({X, 0});
  bfs();
  printf("%d\n", result);
  return 0;
}