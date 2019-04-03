# [SWEA 4014. [모의 SW 역량테스트] 활주로 건설](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeW7FakkUDFAVH&categoryId=AWIeW7FakkUDFAVH&categoryType=CODE)


## How to solve
* 전형적인 시뮬레이션 문제
* 내리막길을 만들기 위해선, 앞으로 걸어갈 길이 X만큼 동일한 높이어야만 만들 수 있음.
* 내리막길을 만들기위해 앞으로 걸어갈 길을 체크를 한 영역은 이미 검증되었으므로 시간 효율을 높이기위해 그만큼 앞으로 검사할 위치를 건너뛰도록 함. (54번째줄)
* 오르막길을 만들기 위해선, 지금까지 걸어온 길이 X만큼 동일한 높이어야만 오르막길을 만들 수 있음.
* 오르막길 만드는 과정에서 과거 동일 높이 길 갯수를 파악할 때 조건을 잘 설정해줘야함. (46, 50번째 줄)


## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


