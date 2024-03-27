import itertools


def calculate(operation_order):
    result = A[0]

    for i in range(N - 1):
        operator = operation_order[i]

        if operator == "+":
            result += A[i + 1]
        elif operator == "-":
            result -= A[i + 1]
        elif operator == "*":
            result *= A[i + 1]
        elif result >= 0:
            result //= A[i + 1]
        else:
            result = -result // A[i + 1] * -1

    return result


N = int(input())
A = list(map(int, input().split()))
plus, minus, mul, div = list(map(int, input().split()))
operators = ["+"] * plus + ["-"] * minus + ["*"] * mul + ["//"] * div
permutations = itertools.permutations(operators)

max_value = -(10**18)
min_value = 10**18

for operation_order in permutations:
    cur_value = calculate(operation_order)
    max_value = max(max_value, cur_value)
    min_value = min(min_value, cur_value)

print(max_value)
print(min_value)
