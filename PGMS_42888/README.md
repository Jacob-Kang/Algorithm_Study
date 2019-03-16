# [PGMS_42888. [2018 kakao blind recruitment] 오픈채팅방](https://www.welcomekakao.com/learn/courses/30/lessons/42888)

## How to solve
* String tokenize와 map을 적절히 사용하여 풀었던 쉬운 문제
* 채팅방 입장, 퇴장에 관련된 이벤트들은 vector 구조체 저장하여 기록해둠
* 사용자의 unique id와 닉네임을 key-value로 하는 map을 생성하여 닉네임을 관리함.
* 최종 출력때 event vector에서 꺼내면서 string을 생성할 때, 해당 ID의 최종 닉네임을 map에서 가져옴으로써 출렴함.


## Build

```
$ make
```

## Contact
Chulho Kang ([chkang0912@snu.ac.kr](mailto:chkang0912@snu.ac.kr))


