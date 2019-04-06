// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu&categoryId=AV5V1SYKAaUDFAWu&categoryType=CODE
/* swea_2112_2.cpp
 *
 *  Created on: 2019. 4. 5.
 *      Author: Chulho Kang
 */

#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
int T, D, W, K;
int result;

int map[13][20];
int bak_map[13][20];

bool check() {
  int check_counter = 0;
  for (int line = 0; line < W; line++) {
    for (int i = 1; i < D && check_counter != K - 1; i++) {
      if (map[i][line] == map[i - 1][line])
        check_counter++;
      else
        check_counter = 0;
      if (D - i < K && check_counter == 0) return false;
    }
    if (check_counter < K - 1) return false;
    check_counter = 0;
  }
  return true;
}
struct q_entry {
  int comb[13];
  int size_;
};

int comb_set[15];
bool already_pass = false;

void dfs(int idx, int depth) {
  // 1개짜리 조합은 특별한 조치없이 바로 변경시키고 검사
  if (depth == 1) {
    for (int color = 0; color < 2; color++) {
      for (int j = 0; j < W; j++) map[comb_set[idx]][j] = color;
      if (check()) {
        already_pass = true;
        memcpy(map[comb_set[idx]], bak_map[comb_set[idx]], sizeof(int) * W);
        return;
      }
    }
    memcpy(map[comb_set[idx]], bak_map[comb_set[idx]], sizeof(int) * W);
    return;
  } else {
    // 2개 이상짜리 조합에서는 끝부분만 순차적으로 idx 증가시키면서 염색 후
    // 검사, 이로인해 색칠하기 overhead로 최소로 줄임, ex: {0, 1, 2}를
    // 입력받았다면 {0, 1, (2~6)}의 조합으로 늘려서 모두 검사. 염색한 0,1을
    // 최대한 reuse하도록함
    if (already_pass) return;
    if (idx == depth) {
      if (check()) {
        already_pass = true;
      }
      return;
    }
    // 조합중 끝부분일때 해당 idx부터 depth 최대값까지 모두 순환
    if (idx == depth - 1) {
      for (int i = comb_set[idx]; i < D; i++) {
        for (int j = 0; j < W; j++) map[i][j] = 0;
        dfs(idx + 1, depth);
        for (int j = 0; j < W; j++) map[i][j] = 1;
        dfs(idx + 1, depth);
        memcpy(map[i], bak_map[i], sizeof(int) * W);
      }
    } else {
      // 조합중 아직 앞부분일때, 해당 idx 부분만 염색
      for (int j = 0; j < W; j++) map[comb_set[idx]][j] = 0;
      dfs(idx + 1, depth);
      for (int j = 0; j < W; j++) map[comb_set[idx]][j] = 1;
      dfs(idx + 1, depth);
      memcpy(map[comb_set[idx]], bak_map[comb_set[idx]], sizeof(int) * W);
    }
  }
}

int main(void) {
  int T;
  freopen("input2.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    result = 0;
    memset(map, 0, sizeof(map));
    std::queue<q_entry> q_bfs;
    scanf("%d %d %d", &D, &W, &K);
    for (int i = 0; i < D; i++) {
      for (int j = 0; j < W; j++) {
        scanf("%d", &map[i][j]);
      }
    }
    memcpy(bak_map, map, sizeof(bak_map));
    q_entry temp_entry;
    if (check()) {
      // 합격, 종료
      printf("#%d %d\n", tc, result);
      continue;
    } else {
      for (int i = 0; i < D; i++) {
        temp_entry.comb[0] = i;
        temp_entry.size_ = 1;
        q_bfs.push(temp_entry);
      }
    }
    while (!q_bfs.empty()) {
      temp_entry = q_bfs.front();
      q_bfs.pop();
      // q에 있는 조합대로 색칠하기
      int idx = 0;
      for (int i = 0; i < temp_entry.size_; i++) {
        comb_set[idx] = temp_entry.comb[i];
        idx++;
      }
      already_pass = false;
      dfs(0, temp_entry.size_);
      if (already_pass) {
        // 합격, 종료
        result = temp_entry.size_;
        break;
      } else {
        //불합격
        temp_entry.size_++;
        if (temp_entry.size_ > 2) {
          // {0, 1} -> {0, 1, 2}, {0, 2, 3} {0, 3, 4} ...
          for (int i = temp_entry.comb[temp_entry.size_ - 2]; i < D; i++) {
            temp_entry.comb[temp_entry.size_ - 2] = i;
            temp_entry.comb[temp_entry.size_ - 1] = i + 1;
            q_bfs.push(temp_entry);
          }
        } else {
          // {0} -> {0, 1}
          temp_entry.comb[temp_entry.size_ - 1] =
              temp_entry.comb[temp_entry.size_ - 2] + 1;
          q_bfs.push(temp_entry);
        }
      }
    }
    printf("#%d %d\n", tc, result);
  }
  return 0;
}