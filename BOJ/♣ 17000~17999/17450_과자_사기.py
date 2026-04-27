s1, s2 = map(int, input().split())
n1, n2 = map(int, input().split())
u1, u2 = map(int, input().split())

s1 *= 10
n1 *= 10
u1 *= 10
s2 *= 10
n2 *= 10
u2 *= 10

if s1 >= 5000:
    s1 -= 500
if n1 >= 5000:
    n1 -= 500
if u1 >= 5000:
    u1 -= 500

s_result = s2 / s1
n_result = n2 / n1
u_result = u2 / u1

if s_result > n_result and s_result > u_result:
    print("S")
elif n_result > s_result and n_result > u_result:
    print("N")
elif u_result > s_result and u_result > n_result:
    print("U")
