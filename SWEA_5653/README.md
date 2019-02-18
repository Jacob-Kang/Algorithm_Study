# [SWEA 5653. [모의 SW 역량테스트] 줄기세포배양](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo&categoryId=AWXRJ8EKe48DFAUo&categoryType=CODE)


## How to solve
* 우선순위 큐를 통해 활성화 및 비활성화 세포를 보관하고, 이 큐에 저장되어있는 갯수를 반환하도록 설계
* 세포가 번식할 때 한곳에 여러 세포들에 의해 동시에 번식되는 경우, 생명이 더 큰 애가 번식된다는 조건이 있음.
* 이에 본 코드는, 우선순위 큐의 comp operator를 오버로딩하여 활성화될 시간을 오름차순으로 정렬하는게 1순위 정렬 기준이지만, 만약 활성화 시간이 같을 경우, 세포의 생명 크기를 2순위로 내림차순 정렬하도록 하여 해당 부분을 해결함. 
* 한가지 계속 안풀렸던 문제는, 문제를 잘 이해해야하는데, 활성화되어 세포를 번식한 후 바로 죽는 것이 아니라 해당 세포의 생명 길이 만큼 더 산 후에 죽기 때문에 이부분을 잘 처리해줘야함. 본 코드에서는 is_active 원소를 하나 더 추가하여 활성화될 때 pop을 하지만 is_active를 true로 표시하여 큐에 다시 삽입함. 

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))

