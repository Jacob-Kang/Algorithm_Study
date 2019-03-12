# [SWEA 2112. [모의 SW 역량테스트] 보호 필름](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu&categoryId=AV5V1SYKAaUDFAWu&categoryType=CODE)

## How to solve
* DFS 문제
* 시간 복잡도 최적화가 핵심인 문제임.
* 62번째 줄의  for문에서 기존에는 depth~line끝 까지 모두 순회하면서 색깔도 변경시켜서 3중 for문이 되어 시간 초과가 크게 나왔으며, 이를 제거함
* 59번째 줄: 현재 구한 최소값 이상의 depth는 탐색하지 않도록 하여 최적화함
* 31번째 줄: check함수에서 체크해야할 남은 line 수가 체크해야할 depth D보다 작을땐 이미 틀린 경우이므로 체크하지않도록 함.
* 86번째 줄: K가 1일때에는 검사할 필요없이 바로 통과이므로 dfs를 하지 않도록 함.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))