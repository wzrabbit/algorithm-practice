# 세그먼트 트리 생성
def makeSegtree(start, end, index):
    # 리프 노드라면, 더 탐색할 수 없으므로 자기 자신을 값으로 반환
    if start == end:
        segTree[index] = raw[start]
        return segTree[index]

    # 리프 노드가 아니라면, 재귀적으로 하위 노드에 접근해 얻은 두 노드의 합을 더한다
    mid = (start + end) // 2
    segTree[index] = makeSegtree(start, mid, index * 2 + 1) + makeSegtree(mid + 1, end, index * 2 + 2)
    return segTree[index]

# 세그먼트 트리 구간 합 구하기
def getSum(start, end, index, left, right):
    # 구간 내에 합을 구하고자 하는 원소가 하나도 없으면, 탐색 중단
    if left > end or right < start:
        return 0

    # 구간 내의 모든 원소가 합을 구하고자 하는 원소라면, 그대로 반환
    if left <= start and right >= end:
        return segTree[index]

    # 여기까지 왔으면 불순물이 섞여 있는 경우이므로, 둘로 나누어 다시 탐색
    mid = (start + end) // 2
    return getSum(start, mid, index * 2 + 1, left, right) + getSum(mid + 1, end, index * 2 + 2, left, right)

# 세그먼트 트리 값 갱신
def updateValue(start, end, index, target, value):
    # 갱신하고자 하는 값이 범위 내에 없다면, 탐색 중단
    if target < start or target > end:
        return

    # 범위 내에 조금이라도 걸쳐 있다면, 해당 구간의 값 갱신
    segTree[index] += value

    # 리프 노드라면 더 탐색할 필요가 없으므로 탐색 중단
    if start == end:
        return

    # 하위 노드의 값도 갱신하기 위해 재귀
    mid = (start + end) // 2
    updateValue(start, mid, index * 2 + 1, target, value)
    updateValue(mid + 1, end, index * 2 + 2, target, value)

import sys
input = sys.stdin.readline
print = sys.stdout.write

n, m, k = list(map(int, input().split()))
raw = []
segTree = [0] * (n * 4)

for _ in range(n):
    raw.append(int(input()))
    
makeSegtree(0, n - 1, 0)

for _ in range(m + k):
    q, a, b = list(map(int, input().split()))
    if q == 1:
        a -= 1
        gap = b - raw[a]
        raw[a] = b
        updateValue(0, n - 1, 0, a, gap)
    else:
        a -= 1
        b -= 1
        print(str(getSum(0, n - 1, 0, a, b)) + '\n')