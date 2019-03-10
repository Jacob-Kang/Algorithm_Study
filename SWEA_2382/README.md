# [2382. [모의 SW 역량테스트] 미생물 격리](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl&categoryId=AV597vbqAH0DFAVl&categoryType=CODE)


## How to solve
* 시뮬레이션 문제
* 시뮬레이션 문제중 디버깅이 가장 오래걸렸던 문제
* 매 시간 번식을 위해서 temp_map을 생성하여 해당 시간에 움직일 세포의 위치를 저장함.
* temp_map은 움직일 세포의 idx 번호를, temp_map2는 해당 좌표를 대표할 가장 큰 세포수
* 번식을 위해 세포를 움직이고, 해당 자리가 temp_map에 기록된 곳일 경우, 기존 idx의 세포수를 증가시키고, 방향을 가장 큰 세포 군집의 방향으로 바꿈
* 해당 부분에서 temp_map == 0 일 경우에만 아직 이동하지 않았음으로 간주하였는데, idx 번호가 0인 세포가 해당 자리를 차지할 경우 해당 자리가 빈곳으로 오해하여 문제가 계속 발생함. (122번째 줄, idx 번호를 1부터 관리하므로서 해결함)
* 기존 세포보다 더 큰 세포가 해당 자리를 차지하고자 할때 방향만 바꾸는 것이 아니라 대표하는 전체 세포수도 업데이트해줘야하는데 이부분을 놓쳤음. (100번째 줄)

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


