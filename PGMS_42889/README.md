# [PGMS_42889. [2018 kakao blind recruitment] 실패율](https://www.welcomekakao.com/learn/courses/30/lessons/42889)

## How to solve
* 효율성 계선을 위한 알고리즘 개선 및 Priority queue를 사용하여 품.
* 실패율을 계산할 때 최대한 효율적으로 구하기 위해 무작위로 입력받은 현재 도전중인 스테이지 vector 구조체를 오름차순으로 정렬함.
* 실패한 플레이어 수는 벡터를 하나씩 순회하면서 해당 스테이지보다 높은 곳을 도전하는 사용자를 모두 카운트함.
* 다음 계산의 효율을 위해 해당 index를 저장하여, 해당 위치부터 다음 스테이지의 실패한 플레이어 수를 체크하도록함.
* 전체 플레이어수는 백터의 원소 수에서 해당 스테이지의 인덱스 길이만큼 뺀 값을 취하도록 하여 효율을 높임.
* 실패율과 index 번호 순으로 정렬하여 출력해야하므로, compare 함수를 수정한 priority queue에 결과값과 index를 저장하여 출력을 용이하게 함.

## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


