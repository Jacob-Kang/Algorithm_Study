// https://www.acmicpc.net/problem/17135

/*
 * boj_17135.cpp
 *
 *  Created on: 2019. 4. 5.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>

int T, W, H, D;
int result;

int map[15][15];

// x, y, dead
#define LIVE 1
#define DEAD 2
int baba[256][3];
int num_baba;

int archer[16][2];
int num_archer;

std::vector<int> v_archer(15);

struct baba_entry {
  int dist, x, idx;
};
bool cmp(baba_entry a, baba_entry b) {
  if (a.dist == b.dist) return a.x < b.x;
  return a.dist < b.dist;
}

baba_entry baba_dist[4][256];

int solve() {
  int cur_time = 0;
  int temp_result = 0;
  int num_baba_dist[3] = {0, 0, 0};
  do {
    memset(num_baba_dist, 0, sizeof(num_baba_dist));
    for (int i = 0; i < num_archer; i++) {
      for (int j = 1; j < num_baba; j++) {
        if (baba[j][1] + cur_time >= H || baba[j][2] == DEAD) continue;
        baba_dist[i][num_baba_dist[i]].dist =
            abs(baba[j][0] - archer[i][0]) +
            abs(baba[j][1] + cur_time - archer[i][1]);
        baba_dist[i][num_baba_dist[i]].x = baba[j][0];
        baba_dist[i][num_baba_dist[i]++].idx = j;
      }
      std::sort(baba_dist[i], baba_dist[i] + num_baba_dist[i], cmp);
    }
    for (int i = 0; i < num_archer; i++) {
      for (int j = 0; j < num_baba_dist[j]; j++) {
        if (baba_dist[i][j].dist <= D) {
          if (baba[baba_dist[i][j].idx][2] == LIVE) {
            temp_result++;
          }
          baba[baba_dist[i][j].idx][2] = DEAD;
          break;
        } else {
          break;
        }
      }
    }
    cur_time++;
  } while (num_baba_dist[0] > 0);
  return temp_result;
}
int main(void) {
  int T;
  freopen("input.txt", "r", stdin);
  // scanf("%d", &T);
  // for (int tc = 1; tc <= T; tc++) {
  result = 0;
  num_baba = 1;
  memset(baba, 0, sizeof(baba));
  memset(archer, 0, sizeof(archer));
  memset(baba_dist, 0, sizeof(baba_dist));
  scanf("%d %d %d", &H, &W, &D);
  v_archer.resize(W);
  v_archer[0] = 1;
  v_archer[1] = 1;
  v_archer[2] = 1;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j] == 1) {
        baba[num_baba][0] = j;
        baba[num_baba][1] = i;
        baba[num_baba++][2] = LIVE;
      }
    }
  }

  do {
    num_archer = 0;
    for (int i = 0; i < v_archer.size(); i++) {
      if (v_archer[i] == 1) {
        archer[num_archer][0] = i;
        archer[num_archer++][1] = H;
      }
    }
    int temp_baba[256];
    for (int i = 1; i <= num_baba; i++) temp_baba[i] = baba[i][2];
    int temp_result = solve();
    result = result < temp_result ? temp_result : result;
    for (int i = 1; i <= num_baba; i++) baba[i][2] = temp_baba[i];
  } while (std::prev_permutation(v_archer.begin(), v_archer.end()));
  // printf("#%d %d\n", tc, result);
  // }
  printf("%d\n", result);
  return 0;
}