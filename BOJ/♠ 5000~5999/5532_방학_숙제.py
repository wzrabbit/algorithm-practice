import math

days = int(input())
korean_goal = int(input())
math_goal = int(input())
korean_daily = int(input())
math_daily = int(input())

print(days - max(math.ceil(korean_goal / korean_daily), math.ceil(math_goal / math_daily)))
