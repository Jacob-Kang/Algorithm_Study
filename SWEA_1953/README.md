# [SWEA_1953. [모의 SW 역량테스트] 탈주범 검거](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq&categoryId=AV5PpLlKAQ4DFAUq&categoryType=CODE)


## How to solve
* 약간의 하드코딩이 존재했던 풀이.
* 현재 위치에서 다음 위치로 갈 때, 그 길이 파이프로 연결되었는지 하드코딩으로 구분하여 있을 때에만 queue에 넣을 수 있도록 함.
* Queue에 넣을 때마다 result 를 1씩 증가시키고, L보다 1작은 depth일 때 까지만 bfs를 수행하도록 함.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


