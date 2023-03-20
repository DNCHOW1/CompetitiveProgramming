n = int(input())
cnt = 0
for i in range(n):
    inp = input()
    cnt += inp.find("CD") == -1

print(cnt)