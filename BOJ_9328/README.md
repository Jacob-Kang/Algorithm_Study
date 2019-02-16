# [BOJ 9328. 열쇠](https://www.acmicpc.net/problem/9328)


## How to solve
* BFS로 문제를 풀때, DFS랑 달리 BFS를 통해 경로를 만들어가면서 탐색한다고 생각하지 말자. BFS를 통해 움직인 모든 자취를 다 합친게 최종적인 이동 경로이지, 순차적으로 길을 탐색한다고 생각하지 않아야함.

* 문을 찾았을 때 아직 들어가지 못하는 부분은 새로운 queue에 임시 대기를 할 수 있도록 하고, 열쇠를 비로소 찾았을 때 대기열에 있던 해당 좌표를 불러와서 그때부터 탐색하도록 한다는 점이 차이점임.
* visit은 단순히 x, y 좌표만으로 체크.
* 범위 체크 잘하기,  if (inputs[i] - 'a' >= 0 이 부분에서 ‘=’ 안 넣어줘서 계속 틀렸음

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


