# [BOJ 17071. 숨바꼭질5](https://www.acmicpc.net/problem/17071)


## How to solve

* 이전[숨바꼭질](https://www.acmicpc.net/problem/1697)과 유사하지만, 술래가 움직일 수 있다는 점이 특이사항임.
* STL queue를 이용하여 BFS 방식으로 풀었음.
```
01| struct q_entry {
02|      int x, depth;
03| };
04| std::queue<q_entry> q;
05| q.push({N, 0});
06| while (!q.empty()) {
07|      int x = q.front().x;
08|      int depth = q.front().depth;
09|      q.pop();
10| 	
11| 	/* 
12| 	* 어떨때 q.push를 하고, 어떨때 while loop를 강제로 종료시킬지를 작성
13| 	*/
14| }
```

* 메모리 제약과 시간 문제를 해결하기 위해 bool visit 변수를 통해 중복 탐색을 피함
```
bool visit[2][500001];
```

* [기존 문제](https://www.acmicpc.net/problem/1697)와 달리, 술래가 움직일 수 있으므로 dynamic program 방식을 이용하여 술래의 위치를 구함
```
25| if (dp_K[depth + 1] == 0) {
26|      dp_K[depth + 1] = depth + 1 + dp_K[depth];
27| }
```

* 수빈이는 좌, 우로 움직일 수 있기 때문에 제자리로 돌아올 수가 있음. 
* 따라서 단순히 현재 수빈이의 위치와 동생의 위치가 같을 경우에만 답으로 간주하는 것이 아닌. 현재 동생의 위치와 과거의 수빈이가 이미 도달했던 위치이면 그것또한 답으로 체크해줘야함. (28, 36번째 줄)
* 무조건 방문했을 경우에만 답으로 체크하는 것이 아닌, 현재 시간과, 과거의 수빈이가 이미 현재 동생 위치에 도달했던 시간과의 차이가 2의 배수 만큼 차이가 났을 때에만 동일하도록 체크해줌(제자리 걸음을 하기위해서는 2초가 소요되기 때문)
```
28| if (visit[depth % 2][dp_K[depth]]) {
29|      result = depth;
30|      return;
31| }
```
* 같은 위치라도 수빈이는 짝수 시간일때, 홀수시간일 때 모두 도달하는 경우가 생길 수 있으므로 visit을 2차원 배열로 선언하여 홀수시간대와 짝수시간대를 따로 관리함.
   ```
35| if (!visit[(depth + 1) % 2][temp_x]) {
36|      visit[(depth + 1) % 2][temp_x] = true;
```
## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


