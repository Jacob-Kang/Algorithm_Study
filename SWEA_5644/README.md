# [SWEA 5644. [모의 SW 역량테스트] 무선 충전](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRDL1aeugDFAUo&categoryId=AWXRDL1aeugDFAUo&categoryType=CODE)


## How to solve
* 시뮬레이션 문제
* 영역이 중복되는 부분을 고려하기 위해, 지도를 vector 타입으로 하였음.
* 따라서 51~73번째줄은 다이아몬드 모양의 AP 영역을 지도로 그리는 부분이며, 충전 범위에 해당하는 좌표에 있는 vector.push를 통해 추가함.
* 가운데 줄을 제외하고 상하를 번갈아가며 우선적으로 영역을 그린뒤, 
* 마지막에 가운제둘을 한번에 칠하는 식으로 함, 이때, 가운데 줄을 색칠하되, 지도를 벗어가는 영역을 확실히 처리해줘야함. 이부분에서 계속 오류가 났었음(65~70번째줄)
* 나머지는 전형적인 시뮬레이션 방식으로 입력받은 cmd대로 움직이면서, 최대 성능값을 구함.
* flag를 하나 만들어서 A와 B가 동일한 충전범위에 있는지 체크하고, 만약 같은 영역에 있을 경우 A한테만 성능값을 몰아주도록 함.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


