n, m = map(int, input().split(" "))
count = 0
cond = True
for i in range(n):
    inp = input()
    count += inp[len(inp)//2] == '#'
    cond = cond and (sum(char=="#" for char in inp) == 1)


if m%2 == 0:
    print("NO")
else:
    if count == n and cond:
        print("YES")
    else: print("NO")