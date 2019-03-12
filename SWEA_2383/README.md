# [2383. [모의 SW 역량테스트] 점심 식사시간](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5-BEE6AK0DFAVl&categoryId=AV5-BEE6AK0DFAVl&categoryType=CODE)


## How to solve
* DFS와 시뮬레이션이 합쳐져있는 문제
* DFS를 통해 사람들이 계단을 선택할 모든 경우의 수를 만든뒤, solve함수를 통해 각 경우의 이동 시간을 계산
* 먼저 도착하는 사람을 우선순위로 내려가기 시작해야하므로, 문제를 풀때 deque에 저장되어있는 변수들을 오름차순으로 정렬후 풀이함.
* 32번째 줄과 같이 임시 queue를 하나 더 만들어서 푸는 이유는, 원본 큐를 정렬해서 풀어버리면, dfs 호출때 넣었던 entry의 순서가 꼬여서 제대로 push & pop이 안됨
* solve()함수 만드는 부분이 시간이 꽤 오래 걸렸는데, 42, 47번째 줄 조건 만드는 부분을 얼마나 효율적으로 하냐가 관건인듯.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


