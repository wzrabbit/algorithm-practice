while True:
    try:
        coupon, cost = map(int, input().split())
        chicken = 0
        stamp = 0

        while coupon > 0:
            chicken += coupon
            stamp += coupon
            coupon = 0
            
            matched = stamp // cost
            coupon += matched
            stamp -= matched * cost

        print(chicken)
    except EOFError:
        break
