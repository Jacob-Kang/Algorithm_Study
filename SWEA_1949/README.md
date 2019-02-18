# [SWEA 1949. [모의 SW 역량테스트] 등산로 조성](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq&categoryId=AV5PoOKKAPIDFAUq&categoryType=CODE)


## How to solve
* 최장 거리를 구하는 문제이므로 bfs보단 dfs가 더 쉬울 것이라 생각
* 가장 높은 곳에서만 출발할 수 있으므로 처음 입력받을 때, 최고 높이를 우선적으로 구함.
* 각 출발점들을 모두 DFS로 네방향을 움직이며 탐색하도록 함.
* K만큼 높이를 낮추는 건, 현재 가려고 하는 위치가 현재 위치보다 높고, K만큼 뺐을 때 현재 높이보다 충분히 낮아질 경우에만 딱한번 진행하도록 하고, 높이는 (현재 높이-1) 만큼만 되도록 수정함.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


