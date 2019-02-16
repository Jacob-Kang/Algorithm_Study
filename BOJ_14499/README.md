# [BOJ 14499. 주사위 굴리기](https://www.acmicpc.net/problem/14499)


## How to solve
* 규칙만 잘 세운다면 매우 쉬운 문제.
* 주사위 도면의 가로 부분과 세로 부분을 각각 별도의 deque으로 저장해서 굴릴 때마다 pop & push를 하고 주사위의 윗면과 아랫면은 별도로 개별 수정하여 풀었음.
* 지도 밖으로 나가려고 할 때 해당 명령을 무시하고 주사위도 돌리기전 상태로 복귀시켜야함.
* 우리가 흔히 아는 개념의 x, y 좌표가 문제에서 말하는 x,y 개념과 서로 다르므로 속지않도록 주의


## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


