// https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPkqBqAEsDFAUn&

/*
 * swea_3752.cpp
 *
 *  Created on: 2019. 1. 30.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>
#include <unordered_set>

// #include <ext/hash_map>

using namespace std;

int t, N;
int a[100];
bool visit[100000] = {
    false,
};
int result = 1;
int sum = 0;

void init() {
  memset(visit, 0, sizeof(visit));
  memset(a, 0, sizeof(a));
  result = 1;
  sum = 0;
  visit[0] = true;
}

int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    init();
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    for (int i = 0; i < N; i++) {
      for (int j = sum; j >= 0; j--) {
        if (visit[j] == true && visit[j + a[i]] == false) {
          visit[j + a[i]] = true;
          result++;
        }
      }
    }
    printf("#%d %d\n", tc, result);
  }
  return 0;
}