vowels = ['a', 'e', 'i', 'o', 'u', 'y']
n = int(input())
while n != 0:
    res = None
    mx = 0
    for i in range(n):
        w = input()
        if res == None:
            res = w
        cnt = 0
        for vow in vowels:
            cnt += w.count(vow*2)
        if cnt > mx:
            mx = cnt
            res = w

    print(res)
    n = int(input())