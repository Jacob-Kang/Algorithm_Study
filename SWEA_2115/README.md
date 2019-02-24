# [SWEA 2115. [모의 SW 역량테스트] 벌꿀채취](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu&categoryId=AV5V4A46AdIDFAWu&categoryType=CODE)


## How to solve
* DFS와 DP를 합쳐서 풀었던 문제.
* DFS 순회를 통해 벌꿀 체취 조합을 선정하고, 각 조합으로 얻을 수 있는 최대값을 DP방식으로 배열에 저장하여 계산 시간을 줄임.
* 단순 DFS탐색과 달리 현재 위치에서 오른쪽으로만 움직일 수 있기 때문에 좌표를 인자값으로 넘겨줄 때 잘 해줘야함.
* 정렬 알고리즘을 통해 DP계산을 좀더 간략히 하고자했는데 인덱스 인자값을 N과 M이 햇갈리지 않도록 잘 넣어줄것 (여기서 디버깅이 오래걸림) 

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


