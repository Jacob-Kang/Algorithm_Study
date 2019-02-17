# [SWEA 3752. 가능한 시험 점수](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPkqBqAEsDFAUn&)


## How to solve
* DP 문제
* 각 testcase가 만들 수 있는 최대 점수를 사전에 계산하여 for loop 순환 범위를 정함
* 입력받은 각 점수를 하나씩 순차적으로 순환하며, 해당 점수를 통해 만들 수 있는 점수를 체크하는데, 중복을 피하고 최대 점수 범위 초과를 방지하기 위해, 만들 수 있는 최대 점수부터 순차적으로 탐색하며 아직 확인하지 못한 점수 조합을 찾는다. 
* 해당 방식으로 순환하며 이전 탐색을 통해 만들 수 있는 점수 조합을 발견하면, (사전에 찾은 점수 조합+순환하고 있는 입력받은 점수)를 새로운 조합으로 체크.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


