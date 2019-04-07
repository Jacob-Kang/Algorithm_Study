# [BOJ 17136. 색종이 붙이기](https://www.acmicpc.net/problem/17136)

## How to solve

* DFS로 풀음
* 가장 큰 크기의 색종이부터 시작해서 해당 영역을 붙일 수 있는지 확인하고, DFS 방식으로 모두 붙여가면서 가장 최소값의 depth를 찾도록 함.
* 시간 복잡도를 낮추기 위해, 현재의 depth가 이미 구한 depth보다 높을경우는 더이상 진행하지 않도록 함(60번째 줄)

```
## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


