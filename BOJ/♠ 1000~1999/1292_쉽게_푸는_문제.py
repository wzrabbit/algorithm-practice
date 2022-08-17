prefix = [0]


def fill_array():
    for i in range(1, 100):
        for _ in range(i):
            if len(prefix) == 1001:
                return
            prefix.append(prefix[-1] + i)


fill_array()
A, B = map(int, input().split())
print(prefix[B] - prefix[A - 1])
