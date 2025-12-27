ca, ba, pa = map(int, input().split())
cr, br, pr = map(int, input().split())

answer = max(0, cr - ca) + max(0, br - ba) + max(0, pr - pa)
print(answer)
