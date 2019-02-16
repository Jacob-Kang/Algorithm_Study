// https://www.acmicpc.net/problem/1504

/*
 * boj_1504.cc
 *
 *  Created on: 2019. 2. 15.
 *      Author: Chulho Kang
 */

#include <memory.h>
#include <iostream>
#include <queue>
#include <vector>

#define INF 999999

using namespace std;

int N, E;
int result;

struct v_entry {
  int to, weight;
};
std::vector<v_entry> graph[802];
std::priority_queue<pair<int, int>, vector<pair<int, int>>,
                    greater<pair<int, int>>>
    pq;
int a_dist[3][802];
int must_a, must_b;

void solve(int start_v, int count) {
  int from, to, weight, dist;
  pq.push(make_pair(0, start_v));
  while (!pq.empty()) {
    dist = pq.top().first;
    from = pq.top().second;
    pq.pop();
    if (a_dist[count][from] >= dist) {
      a_dist[count][from] = dist;
      for (auto it = graph[from].begin(); it != graph[from].end(); it++) {
        to = it->to;
        weight = it->weight;
        if (a_dist[count][to] >= a_dist[count][from] + weight) {
          a_dist[count][to] = a_dist[count][from] + weight;
          pq.push(make_pair(a_dist[count][to], to));
        }
      }
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  int a, b, c;
  memset(a_dist, INF, sizeof(a_dist));
  scanf("%d %d", &N, &E);

  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &a, &b, &c);
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  scanf("%d %d", &must_a, &must_b);

  solve(1, 0);
  solve(must_a, 1);
  solve(must_b, 2);

  int root1 = -1;
  int root2 = -1;
  if (!(a_dist[0][must_a] >= INF || a_dist[1][must_b] >= INF ||
        a_dist[2][N] >= INF)) {
    root1 = a_dist[0][must_a] + a_dist[1][must_b] + a_dist[2][N];
  }
  if (!(a_dist[0][must_b] >= INF || a_dist[2][must_a] >= INF ||
        a_dist[1][N] >= INF)) {
    root2 = a_dist[0][must_b] + a_dist[2][must_a] + a_dist[1][N];
  }
  if (root1 == -1 && root2 == -1)
    cout << -1 << endl;
  else
    cout << min(root1, root2) << endl;

  return 0;
}
