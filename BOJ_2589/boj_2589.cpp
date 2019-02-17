// https://www.acmicpc.net/problem/2589

/*
 * boj_2589.cpp
 *
 *  Created on: 2019. 1. 31.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
char input[51];
bool a[51][51];
bool visit[51][51];
int a_dist[51][51];
int result = 0;

// 0: >
// 1: V
// 2: <
// 3: ^
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct q_entry {
  int x, y;
};
queue<q_entry> q;

void bfs(int i, int j) {
  q.push({j, i});
  visit[i][j] = true;
  int temp_x;
  int temp_y;
  while (!q.empty()) {
    temp_x = q.front().x;
    temp_y = q.front().y;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int n_x = temp_x + dx[i];
      int n_y = temp_y + dy[i];

      // 가려는 곳이 육지이고, 방문한적이 없었던 곳
      if (a[n_y][n_x] == true && visit[n_y][n_x] == false) {
        visit[n_y][n_x] = true;
        q.push({n_x, n_y});
        // depth증가. 이부분을 queue에 넣어서 진행했었는데, 메모리 초과를
        // 발생했고, BFS특성상 굳이 안넣어도. 원하는 목표점에 도달했을 때의
        // 현상태의 depth가 최단 거리이므로, 필요없음.
        a_dist[n_y][n_x] = a_dist[temp_y][temp_x] + 1;
        // 지금까지 구한 최단거리중 가장 큰값을 result로 대체.
        if (result < a_dist[n_y][n_x]) result = a_dist[n_y][n_x];
      }
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  memset(a, 0, sizeof(a));
  std::cin >> N >> M;
  for (int i = 0; i < N; i++) {
    scanf("%s", input);
    for (int j = 0; j < M; j++) {
      if (input[j] == 'L')
        a[i][j] = true;
      else if (input[j] == 'W')
        a[i][j] = false;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] == true) {
        memset(visit, 0, sizeof(visit));
        memset(a_dist, 0, sizeof(a_dist));
        bfs(i, j);
      }
    }
  }

  printf("%d\n", result);
  return 0;
}