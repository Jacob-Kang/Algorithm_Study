# [SWEA 5650. [모의 SW 역량테스트] 핀볼 게임](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo)


## How to solve
* 시뮬레이션 문제
* 벽돌에 부딪힐 때 방향을 쉽게 바꾸기 위해서 35번째 줄과 같이 반사된 방향을 미리 선언해둠
* 웜홀을 좀더 쉽게 관리하기 위해 vector를 통해 짝을 이루도록 구현함(102,103번째 줄)
* 공이 지도 테두리에 부딪혔을때 되돌아오는 과정에서 많은 디버깅이 있었음
* 웜홀을 통해 이동한 곳이 바로 벽옆일 경우 next_x, next_y를 조정하는 것이 아닌 현재 위치만 조정하여 다음 이동할 때 벽에 정상적으로 튕길 수 있도록 함 (67,68번째줄)
* 벽에 튕겨나가는 경우를 가장 우선순위로 두어 예외상황이 발생하지 않도록 함.(46~52번째줄)

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


