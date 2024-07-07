N = int(input())

for _ in range(N):
    points_info = input()
    points = 0
    ban_week_count = 0
    ban_status = ''

    for cur in points_info:
        before_points = points
        after_points = None

        if '0' <= cur <= '9':
            after_points = before_points + int(cur)
        else:
            after_points = before_points + ord(cur) - ord('A') + 10

        points = after_points
        before_quotient = before_points // 10
        after_quotient = after_points // 10

        if before_quotient != after_quotient:
            if after_quotient <= 3:
                ban_week_count += after_quotient
                continue

            if after_quotient == 4:
                ban_status = '(weapon)'
                break
            
            ban_status = '(09)'
            break

    print(f'{ban_week_count}{ban_status}')
    
                