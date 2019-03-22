// https://www.acmicpc.net/problem/17071

/*
 * boj_17071.cpp
 *
 *  Created on: 2019. 3. 22.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

#define MAX_LENGTH 500000
int N, K;
int result;
bool dist[2][500001];

int dp_K[700];
struct q_entry {
  int x, total;
};

std::queue<q_entry> q;

void bfs() {
  while (!q.empty()) {
    int x = q.front().x;
    int total = q.front().total;
    q.pop();
    if (dp_K[total + 1] == 0) {
      dp_K[total + 1] = total + 1 + dp_K[total];
    }
    if (dist[total % 2][dp_K[total]]) {
      result = total;
      return;
    }
    if (dp_K[total + 1] > MAX_LENGTH) continue;
    for (auto temp_x : {x - 1, x + 1, x * 2}) {
      if (temp_x < 0 || temp_x > MAX_LENGTH) continue;
      if (!dist[(total + 1) % 2][temp_x]) {
        dist[(total + 1) % 2][temp_x] = true;
        q.push({temp_x, total + 1});
      }
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d %d", &N, &K);
  memset(dp_K, 0, sizeof(dp_K));
  memset(dist, 0, sizeof(dist));
  result = -1;
  while (!q.empty()) {
    q.pop();
  }
  dp_K[0] = K;
  dist[0][N] = true;
  q.push({N, 0});
  bfs();
  printf("%d\n", result);
  return 0;
}
