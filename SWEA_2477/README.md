# [SWEA 2477. [모의 SW 역량테스트] 차량 정비소](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV6c6bgaIuoDFAXy&categoryId=AV6c6bgaIuoDFAXy&categoryType=CODE)

## How to solve
* 완벽한 시뮬레이션문제
* A와 B 데스크를 움직이는 과정을 모두 손수 시뮬레이션 방식으로 구현함.
* 대기와 들어가는 순서의 우선순위 규칙이 있으므로, 대기열 큐를 priority_queue로 구현함.
* 데스크 업무 완료후 다음 장소로 이동하는 시간이 0이므로, 각 데스크별로 우선적으로 비우는 작업을 완료후 다음 대기자를 채워야 함.
* A대기열은 도착시간을 미리 알고있는 상태로 모두 넣어져있기 때문에 A데스크가 비어있다고 해서 무조건 대기열 큐를 pop하면 안되고, 도착 시간과 현재 시간이 일치할때만 꺼내도록 해야함.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


