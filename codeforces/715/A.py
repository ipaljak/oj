n = input()

last = 2
lvl = 1

for i in range(n):
    next = lvl ** 2 * (lvl + 1) ** 2;
    print (next - last) / lvl
    last = lvl * (lvl + 1)
    lvl += 1
