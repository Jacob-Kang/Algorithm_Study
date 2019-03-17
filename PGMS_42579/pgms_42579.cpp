#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct genres_entry {
  int total;
  string genres;
};

struct value_entry {
  int idx;
  int plays;
};

struct pq_value_entry {
  int idx;
  int plays;
  string genres;
};

struct cmp_genres {
  bool operator()(genres_entry a, genres_entry b) { return a.total < b.total; }
};

struct cmp_value {
  bool operator()(pq_value_entry a, pq_value_entry b) {
    if (a.genres == b.genres) {
      if (a.plays == b.plays)
        return a.idx > b.idx;
      else
        return a.plays > b.plays;
    } else
      return false;
  }
};

bool compare(pq_value_entry a, pq_value_entry b) {
  if (a.plays == b.plays)
    return a.idx < b.idx;
  else
    return a.plays > b.plays;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;
  unordered_map<string, int> um_genres;
  unordered_multimap<string, value_entry> um_total;

  for (int i = 0; i < (int)genres.size(); i++) {
    um_genres[genres[i]] += plays[i];
    um_total.insert({genres[i], {i, plays[i]}});
  }

  priority_queue<genres_entry, vector<genres_entry>, cmp_genres> pq_rank;
  for (auto it = um_genres.begin(); it != um_genres.end(); it++) {
    pq_rank.push({it->second, it->first});
  }
  priority_queue<pq_value_entry, vector<pq_value_entry>, cmp_value> pq_value;

  vector<vector<pq_value_entry>> best_songs(pq_rank.size());
  int idx = 0;
  while (!pq_rank.empty()) {
    auto itr = um_total.find(pq_rank.top().genres);
    if (itr != um_total.end()) {
      best_songs[idx].push_back(
          {itr->second.idx, itr->second.plays, itr->first});
      um_total.erase(itr);
    } else {
      sort(best_songs[idx].begin(), best_songs[idx].end(), compare);
      pq_rank.pop();
      idx++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < (int)best_songs.size(); i++) {
    for (int j = 0; j < (int)best_songs[i].size() && cnt < 2; j++) {
      answer.push_back(best_songs[i][j].idx);
      cnt++;
    }
    cnt = 0;
  }

  return answer;
}

int main() {
  vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
  vector<int> plays = {500, 600, 150, 800, 2500};
  vector<int> ans = solution(genres, plays);

  for (auto it = ans.begin(); it != ans.end(); it++)
    std::cout << *it << std::endl;
  return 0;
}