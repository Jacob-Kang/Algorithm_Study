# [PGMS_42579. 베스트 앨범](https://programmers.co.kr/learn/courses/30/lessons/42579)

## How to solve
* Unordered_map를 이용하여 풀었던 문제
* 베스트 장르를 구하기 위한 {장르-플레이횟수} unordered_map과, 모든 실제 정보를 저장하는 unordered_multimap 및 priority_queue를 이용하여 최고의 장르와 각 장르별 플레이수가 높고 idx가 빠른 노래들을 선별하였음.
* 각 장르별 두곡 혹은 두곡 이하만을 선택해야하므로, 우선순위를 선별한뒤 각 장르별 vector를 추가로 만들어서 이를 통해 보다 쉽게 구현하였음.(64번째 줄)

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


