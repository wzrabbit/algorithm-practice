def is_valid_isbn(isbn):
    total = 0

    for i in range(13):
        if i % 2 == 0:
            total += int(isbn[i])
        else:
            total += int(isbn[i]) * 3
    
    return total % 10 == 0

isbn = input()

for i in range(10):
    cur_isbn = isbn.replace('*', str(i))

    if is_valid_isbn(cur_isbn):
        print(i)
        break
