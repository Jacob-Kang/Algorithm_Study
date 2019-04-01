# [SWEA 4013. [모의 SW 역량테스트] 특이한 자석](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeV9sKkcoDFAVH&categoryId=AWIeV9sKkcoDFAVH&categoryType=CODE)


## How to solve
* 전형적인 시뮬레이션 문제
* deque일 이용하여 보다 효율적으로 톱니바퀴를 회전시키고 관리하였음
* 회전 명령을 받았을 때, 해당 톱니바퀴를 기준으로 오른쪽방향으로 모두 검사하여 어떤 톱니바퀴를 회전시켜야할지 cmd_set 배열에 저장하고, 반대로 똑같이 왼쪽방향도 검사를 완료한뒤 한번에 회전시키도록 함.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


