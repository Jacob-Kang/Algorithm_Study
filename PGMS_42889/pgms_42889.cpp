
// https://www.welcomekakao.com/learn/courses/30/lessons/42889

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct pq_entry {
  int idx;
  float rate;
};

struct cmp {
  bool operator()(pq_entry a, pq_entry b) {
    if (a.rate == b.rate)
      return a.idx > b.idx;
    else
      return a.rate < b.rate;
  }
};

vector<int> solution(int N, vector<int> record) {
  vector<int> answer;
  priority_queue<pq_entry, vector<pq_entry>, cmp> pq;

  sort(record.begin(), record.end());
  // for (int j = 0; j < record.size(); j++) std::cout << record[j] << " ";
  // std::cout << std::endl;
  int index = 0;
  float rate = 0;
  // for (int i = N; i > 0; i--) {
  for (int i = 1; i <= N; i++) {
    int playing = 0, total = 0;
    total = record.size() - index;
    for (int j = index; j < (int)record.size(); j++) {
      if (i < record[j]) {
        index = j;
        break;
      } else if (i == record[j])
        playing++;
    }
    if (playing == 0)
      rate = 0;
    else
      rate = (float)playing / (float)total;

    // std::cout << i << ": " << playing << "/" << total << ", " << rate
    //           << std::endl;
    pq.push({i, rate});
  }

  while (!pq.empty()) {
    answer.push_back(pq.top().idx);
    // std::cout << pq.top().idx << ": " << pq.top().rate << std::endl;
    pq.pop();
  }
  return answer;
}

int main() {
  // vector<int> record = {2, 1, 2, 6, 2, 4, 3, 3};
  vector<int> record = {1, 1, 1, 1, 1, 2};
  vector<int> ans = solution(5, record);

  for (auto it = ans.begin(); it != ans.end(); it++)
    std::cout << *it << std::endl;
  return 0;
}