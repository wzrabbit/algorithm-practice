import sys
heap = [-1]
cases = int(sys.stdin.readline())

for i in range(cases):
    command = int(sys.stdin.readline())
    if command == 0:
        # 힙 제거 연산
        if len(heap) == 1:
            print(0)
        else:
            print(heap[1])
            if len(heap) > 2:
                heap[1] = heap.pop()
            else:
                heap.pop()
            previous = 1
            compare = 2
            while len(heap) > compare:
                if heap[previous] > heap[compare] or (len(heap) > compare + 1 and heap[previous] > heap[compare + 1]):
                    if len(heap) > compare + 1 and heap[compare] > heap[compare + 1]:
                        temp = heap[previous]
                        heap[previous] = heap[compare + 1]
                        heap[compare + 1] = temp
                        previous = compare + 1
                        compare = (compare + 1) * 2
                    else:
                        temp = heap[previous]
                        heap[previous] = heap[compare]
                        heap[compare] = temp
                        previous = compare
                        compare *= 2
                else:
                    break
    else:
        # 힙 추가 연산
        heap.append(command)
        previous = len(heap) - 1
        compare = int(previous / 2)
        while compare:
            if heap[previous] < heap[compare]:
                temp = heap[previous]
                heap[previous] = heap[compare]
                heap[compare] = temp
                previous = compare
                compare = int(previous / 2)
            else:
                break