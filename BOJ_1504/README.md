# [BOJ 1504. 특정한 최단 경로](https://www.acmicpc.net/problem/1504)


## How to solve
* 1->N 으로 가는 경로를 구할 때, a와 b를 반드시 거쳐야한다면 아래와 같은 두가지 경로가 존재
* (1->a->b->N), (1->b->a->N) 
* 따라서 1의 다익스트라, a의 다익스트라, b의 다익스트라를 구한뒤

  (1->a 최단 경로) + (a->b) + (b->N)

  (1->b 최단 경로) + (b->a) + (a->N)

* 이 두개를 구하여 그중 작은 것을 출력하게 하면 됨.


## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


