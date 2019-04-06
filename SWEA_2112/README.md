# [SWEA 2112. [모의 SW 역량테스트] 보호 필름](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu&categoryId=AV5V1SYKAaUDFAWu&categoryType=CODE)

## How to solve
* DFS 문제
* [swea_2112.cpp]
* 시간 복잡도 최적화가 핵심인 문제임.
* 62번째 줄의  for문에서 기존에는 depth~line끝 까지 모두 순회하면서 색깔도 변경시켜서 3중 for문이 되어 시간 초과가 크게 나왔으며, 이를 제거함
* 59번째 줄: 현재 구한 최소값 이상의 depth는 탐색하지 않도록 하여 최적화함
* 31번째 줄: check함수에서 체크해야할 남은 line 수가 체크해야할 depth D보다 작을땐 이미 틀린 경우이므로 체크하지않도록 함.
* 86번째 줄: K가 1일때에는 검사할 필요없이 바로 통과이므로 dfs를 하지 않도록 함.
* 
* [swea_2112_2.cpp]
* 단순 dfs 방식으로 풀면, 염색해야할 최소값을 구하는 문제인데, 정답을 찾기위해 항상 최대 깊이까지 염색을 모두 해가야하는 비효율적인 면을 개선한 버전임
* bfs를 통해 염색해야할 line_number 조합을 생성함으로써 낮은 깊이부터 순차적으로 찾아감.
* 염색할 줄의 조합이 생성되더라도, 그 안에서 A로 할지 B로할지에 대한 조합이 또 파생되기때문에 해당 부분은 DFS 방식으로 구현함.
* 염색한 줄을 최대한 reuse 하기위해 특별한 조합 방식을 사용
* ex. {0, 1}의 조합을 받으면 {0, (1~D)}로 조합을 생성시켜, 0 줄을 최대한 reuse하도록 함. 
* 즉 (0,1)은 (0, 1) (0, 2) (0, 3) ... 의 묶음을 뜻함.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))