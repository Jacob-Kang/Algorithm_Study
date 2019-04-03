// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV6c6bgaIuoDFAXy&categoryId=AV6c6bgaIuoDFAXy&categoryType=CODE
/*
 * swea_2477.cpp
 *
 *  Created on: 2019. 4. 3.
 *      Author: Chulho Kang
 */

#include <math.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int T, N, M, K, A, B;
int a_time[10], b_time[10];
int visiter[1001][2];
int result;

struct q_entry {
  int visit_time, idx;
};

struct cmp {
  bool operator()(q_entry a, q_entry b) {
    if (a.visit_time == b.visit_time) return a.idx > b.idx;
    return a.visit_time > b.visit_time;
  }
};

struct qb_entry {
  int visit_time, a_idx, idx;
};

struct b_cmp {
  bool operator()(qb_entry a, qb_entry b) {
    if (a.visit_time == b.visit_time) return a.a_idx > b.a_idx;
    return a.visit_time > b.visit_time;
  }
};

int main(void) {
  int T;
  freopen("input.txt", "r", stdin);
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    std::priority_queue<q_entry, std::vector<q_entry>, cmp> a_waiting;
    std::priority_queue<qb_entry, std::vector<qb_entry>, b_cmp> b_waiting;

    // 0: expire_time
    // 1: idx
    int a_desk[10][2], b_desk[10][2];
    memset(a_desk, 0, sizeof(a_desk));
    memset(b_desk, 0, sizeof(b_desk));

    int a_desk_size = 0, b_desk_size = 0;
    result = 0;
    memset(a_time, 0, sizeof(a_time));
    memset(b_time, 0, sizeof(b_time));
    memset(visiter, 0, sizeof(visiter));

    scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
    for (int i = 1; i <= N; i++) scanf("%d", &a_time[i]);
    for (int i = 1; i <= M; i++) scanf("%d", &b_time[i]);

    int temp_time;
    for (int i = 1; i <= K; i++) {
      scanf("%d", &temp_time);
      a_waiting.push({temp_time, i});
    }

    int cur_time = 0;
    int finish_count = 0;
    while (finish_count != K) {
      if (a_desk_size > 0) {
        for (int i = 1; i <= N; i++) {
          if (a_desk[i][0] == cur_time) {
            b_waiting.push({cur_time, i, a_desk[i][1]});
            a_desk_size--;
            a_desk[i][0] = 0;
            a_desk[i][1] = 0;
          }
        }
      }

      if (a_desk_size < N && a_waiting.size() > 0) {
        for (int i = 1; i <= N; i++) {
          if (a_desk[i][0] == 0 && a_waiting.size() > 0 &&
              a_waiting.top().visit_time <= cur_time) {
            a_desk[i][0] = cur_time + a_time[i];
            a_desk[i][1] = a_waiting.top().idx;
            visiter[a_waiting.top().idx][0] = i;
            a_waiting.pop();
            a_desk_size++;
          }
        }
      }

      if (b_desk_size > 0) {
        for (int i = 1; i <= M; i++) {
          if (b_desk[i][0] == cur_time) {
            b_desk_size--;
            b_desk[i][0] = 0;
            b_desk[i][1] = 0;
            finish_count++;
          }
        }
      }
      if (b_desk_size < M && b_waiting.size() > 0) {
        for (int i = 1; i <= M; i++) {
          if (b_desk[i][0] == 0 && b_waiting.size() > 0) {
            b_desk[i][0] = cur_time + b_time[i];
            b_desk[i][1] = b_waiting.top().idx;
            visiter[b_waiting.top().idx][1] = i;
            b_waiting.pop();
            b_desk_size++;
          }
        }
      }
      cur_time++;
    }

    for (int i = 1; i <= K; i++) {
      if (visiter[i][0] == A && visiter[i][1] == B) result += i;
    }
    if (result == 0)
      printf("#%d -1\n", tc);
    else
      printf("#%d %d\n", tc, result);
  }
  return 0;
}