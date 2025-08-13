while True:
    route_no, max_size = input().split()

    if route_no == '#':
        break

    max_size = int(max_size)
    cur_size = int(input())
    queries = int(input())

    for _ in range(queries):
        off_count, on_count = map(int, input().split())
        cur_size = min(max_size, cur_size + on_count - off_count)
    
    print(f'{route_no} {cur_size}')
