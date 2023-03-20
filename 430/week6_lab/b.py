import heapq

n = int(input())

for index in range(n):
    s = int(input())
    arr = input().split(" ")

    rc = bc = 0
    reds = []
    blues = []
    for e in arr:
        if e[-1] == 'R':
            heapq.heappush(reds, -1*int(e[:-1]))
        else:
            heapq.heappush(blues, -1*int(e[:-1]))

    mx = min(len(reds), len(blues))
    sz = 0

    for i in range(mx):
        tpR = -1*heapq.heappop(reds)
        tpB = -1*heapq.heappop(blues)
        # sz += (tpR + tpB - 1)
        # if tpR == 1 or tpB == 1:
        #     if tpR != tpB:
        #         sz -= 1
        sz += tpR+tpB-2


    if mx != 0:
        print(f"Case #{index+1}: {sz}")
    else:
        print(f"Case #{index+1}: 0")