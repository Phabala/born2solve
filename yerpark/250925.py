**닉네임**: yerpark

**문제 플랫폼**: 백준

**문제 이름 또는 번호**: 18405 문제

**문제 링크**: https://www.acmicpc.net/problem/18405

**오늘의 메모(선택)**: 

**코드(선택)**:

```python3
#bfs?,, 레벨마다 전염이 되니까 
#1->2->3 순으로 전염이 되야 하는데 이걸 어떻게 관리할까
#다 탐색하면서 1부터 하고 다시 탐색해서 2부터 하고 이러면 너무 오래걸릴듯
#그럼 그냥 새로운 오염애들을 큐에 바이러스 종류가 낮은 순으로 넣고
#그다음 탐색에서 큐에서 순차적으로 빼서 탐색하는 방법으로 해봅시다 
#그럼 큐보다 우선순위큐를 사용해서 쉽게 빼면 초기화할때도 탐색 필요 X 
#우선순위큐에서 볼 애는 바이러스 종류, 그리고 추가관리정보는 Row, col
#그래서 힙에 들어가는 애는 (바이러스 종류, row, col)의 형식

import heapq
import sys

if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())
    arr = [ list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    s, x, y = map(int, sys.stdin.readline().split())

    heap = []
    for row in range(n):
        for col in range(n):
            if arr[row][col] > 0:
                heapq.heappush(heap, [arr[row][col], row, col])

    #상하좌우
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    for _ in range(s):
        prevHeapLen = len(heap)
        prevHeap = []
        for _ in range(prevHeapLen):
            prevHeap.append(heapq.heappop(heap))
        for curr in prevHeap:
            for i in range(4):
                nr = curr[1] + dr[i]
                nc = curr[2] + dc[i]
                if (n <= nr or nr < 0 or n <= nc or nc < 0 or arr[nr][nc] != 0):
                    continue
                arr[nr][nc] = curr[0]
                heapq.heappush(heap, [curr[0], nr, nc])

    print(arr[x - 1][y - 1])
\```
