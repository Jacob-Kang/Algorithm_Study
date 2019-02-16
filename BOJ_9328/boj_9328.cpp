// https://www.acmicpc.net/problem/9328

/*
 * boj_9328.cc
 *
 *  Created on: 2019. 2. 12.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;

int T, h, w;
char map[102][102];
bool keys[26];
char inputs[26];
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

void bfs() {
  int c_x, c_y;
  int temp_x, temp_y;
  bool visit[102][102];
  memset(visit, 0, sizeof(visit));
  queue<q_entry> q;
  queue<q_entry> door_q[26];
  while (!q.empty()) q.pop();
  for (int i = 0; i < 26; i++)
    while (!door_q[i].empty()) door_q[i].pop();
  q.push({0, 0});
  visit[0][0] = true;

  while (!q.empty()) {
    c_x = q.front().x;
    c_y = q.front().y;
    q.pop();

    for (int i = 0; i < 4; i++) {
      temp_x = c_x + d_x[i];
      temp_y = c_y + d_y[i];

      if (temp_x >= 0 && temp_x < w + 2 && temp_y >= 0 && temp_y < h + 2) {
        if (map[temp_y][temp_x] == '*' || visit[temp_y][temp_x]) continue;
        // 정상적인 길
        if (map[temp_y][temp_x] == '.') {
          visit[temp_y][temp_x] = true;
          q.push({temp_x, temp_y});
          // 잠긴 문
        } else if (map[temp_y][temp_x] - 'A' >= 0 &&
                   map[temp_y][temp_x] - 'A' < 26) {
          // 열쇠가 있는 문
          if (keys[(map[temp_y][temp_x] - 'A')]) {
            visit[temp_y][temp_x] = true;
            q.push({temp_x, temp_y});
            // 열쇠가 없어서 열 수 없는 문
          } else {
            door_q[(map[temp_y][temp_x] - 'A')].push({temp_x, temp_y});
          }
          // 열쇠
        } else if (map[temp_y][temp_x] - 'a' >= 0 &&
                   map[temp_y][temp_x] - 'a' < 26) {
          keys[(map[temp_y][temp_x] - 'a')] = true;
          visit[temp_y][temp_x] = true;
          q.push({temp_x, temp_y});
          while (!door_q[map[temp_y][temp_x] - 'a'].empty()) {
            int door_x = door_q[map[temp_y][temp_x] - 'a'].front().x;
            int door_y = door_q[map[temp_y][temp_x] - 'a'].front().y;
            door_q[map[temp_y][temp_x] - 'a'].pop();
            visit[door_y][door_x] = true;
            q.push({door_x, door_y});
          }
          map[temp_y][temp_x] = '.';
          // 훔칠 문서
        } else if (map[temp_y][temp_x] == '$') {
          map[temp_y][temp_x] = '.';
          result++;
          visit[temp_y][temp_x] = true;
          q.push({temp_x, temp_y});
        }
      }
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    scanf("%d %d", &h, &w);
    memset(map, '.', sizeof(map));
    memset(keys, 0, sizeof(keys));
    memset(inputs, 0, sizeof(inputs));
    result = 0;
    for (int i = 1; i <= h; i++) {
      scanf("%s", map[i] + 1);
      map[i][w + 1] = '.';
    }
    scanf("%s", inputs);
    for (int i = 0; i < (int)strlen(inputs); i++)
      if (inputs[i] - 'a' >= 0 && inputs[i] - 'a' < 26) {
        keys[inputs[i] - 'a'] = true;
      }
    bfs();
    printf("%d\n", result);
  }
  return 0;
}
