while True:
    first = list(map(int, input().split()))[1:]

    if first == []:
        break

    second = list(map(int, input().split()))[1:]
    occured = [0] * 20001
    N = len(first)
    M = len(second)

    for i in first + second:
        occured[i + 10000] += 1

    cost = 0
    first_index = 0
    second_index = 0

    while first_index < N or second_index < M:
        first_cost = 0
        second_cost = 0

        while first_index < N:
            value = first[first_index]
            first_cost += value
            first_index += 1

            if occured[value + 10000] == 2:
                break

        while second_index < M:
            value = second[second_index]
            second_cost += value
            second_index += 1

            if occured[value + 10000] == 2:
                break

        cost += max(first_cost, second_cost)

    print(cost)
