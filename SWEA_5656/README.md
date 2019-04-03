# [SWEA 5656. [모의 SW 역량테스트] 벽돌 깨기](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo)


## How to solve
* DFS와 simulation 문제.
* DFS를 통해 쏘아내릴 구슬의 위치 조합을 각각 구하여 그중 벽돌을 최대로 많이 깬 경우를 확인.
* 구슬을 한번 쏠때마다 최종적으로 부서진 후의 벽돌 상태를 만드는 것이 제일 어려웠음.
* 벽돌 하나가 부서질때마다 queue에 넣고, 그 entry를 꺼내면서 해당 숫자만큼 상하좌우를 순회하며 해당 과정을 반복한다. 부서진 벽돌은 0으로 마킹하고 해당 queue가 모두 비워질때까지 반복하여 끝낸후 한번에 0이 된 벽돌들을 지운다.
* 0이된 벽돌을 지우면서 외에있는 벽돌을 내리는 과정은 여러 방법이 있겠으니 시간상 효율을 위해, 임시 배열을 하나 생성하여 맨 아래층부터 세로 방향으로 순환하며 0이 아닌 값들로만 새로 채워서 다시 원래 map에 복사하는 방식으로 하였음.
* dfs 순환할때마다 재귀호출하기 전 벽돌의 상태를 다시 복원 시켜야하므로 memcpy를 통해 백업해둔 map을 다시 원상복귀하여 처리하도록 함.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))

