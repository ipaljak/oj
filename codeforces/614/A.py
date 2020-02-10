l, r, k = map(int, input().split())

sol = []
x = 1
while x <= r:
    if x >= l: sol.append(x)
    x *= k

if len(sol) == 0:
    print(-1)
else:
    print(' '.join(list(map(str, sol))))
