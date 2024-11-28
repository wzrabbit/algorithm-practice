def get_day_value(year, month, day):
    month -= 1
    day -= 1
    return year * 360 + month * 30 + day

def print_date_by_day_value(value):
    print(f'{value // 360} {value % 360 // 30 + 1} {value % 30 + 1}', end=" ")

year, month, day, latitude, longitude = input().split()
year2, month2, day2, latitude2, longitude2 = input().split()

year = int(year)
month = int(month)
day = int(day)
year2 = int(year2)
month2 = int(month2)
day2 = int(day2)

latitude = int(latitude.replace(".", ""))
longitude = int(longitude.replace(".", ""))
latitude2 = int(latitude2.replace(".", ""))
longitude2 = int(longitude2.replace(".", ""))

first_day_value = get_day_value(year, month, day)
second_day_value = get_day_value(year2, month2, day2)
gap = (second_day_value - first_day_value)

answer_day_value = first_day_value - gap
print_date_by_day_value(answer_day_value)

latitude_gap = latitude2 - latitude
longitude_gap = longitude2 - longitude

answer_latitude = latitude - latitude_gap
answer_longitutde = longitude - longitude_gap 

print(f'{answer_latitude // 1000}.{str(answer_latitude % 1000).zfill(3)}', end=" ")
print(f'{answer_longitutde // 1000}.{str(answer_longitutde % 1000).zfill(3)}', end=" ")
