city = ''
temp = 1000

while True:
    try:
        cur_city, cur_temp = input().split()
        cur_temp = int(cur_temp)

        if cur_temp < temp:
            city = cur_city
            temp = cur_temp
    except EOFError:
        break

print(city)
