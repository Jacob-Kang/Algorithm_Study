// https://www.welcomekakao.com/learn/courses/30/lessons/42888

#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define ENTER 1
#define LEAVE 2

vector<string> solution(vector<string> record) {
  vector<string> answer;
  queue<pair<int, string>> events;
  map<string, string> id_table;

  for (int i = 0; i < (int)record.size(); i++) {
    string token;
    vector<string> cmds;
    for (int j = 0; j < (int)record[i].size(); j++)
      if (record[i][j] == ' ') {
        cmds.push_back(token);
        token.clear();
      } else
        token.push_back(record[i][j]);
    cmds.push_back(token);
    if (cmds[0] == "Enter") {
      events.push(make_pair(ENTER, cmds[1]));
      id_table[cmds[1]] = cmds[2];
    } else if (cmds[0] == "Leave")
      events.push(make_pair(LEAVE, cmds[1]));
    else if (cmds[0] == "Change")
      id_table[cmds[1]] = cmds[2];
  }

  string tmp_ans;
  while (!events.empty()) {
    tmp_ans = id_table[events.front().second];
    if (events.front().first == ENTER)
      tmp_ans += "님이 들어왔습니다.";
    else if (events.front().first == LEAVE)
      tmp_ans += "님이 나갔습니다.";
    events.pop();
    answer.push_back(tmp_ans);
  }
  return answer;
}

int main() {
  vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo",
                           "Leave uid1234", "Enter uid1234 Prodo",
                           "Change uid4567 Ryan"};
  vector<string> ans = solution(record);

  for (auto it = ans.begin(); it != ans.end(); it++)
    std::cout << *it << std::endl;
  return 0;
}