n = int(input())
mp = {}
mx = 0
for i in range(n):
    nums = tuple(sorted(map(int ,input().split(" "))))
    val = mp.get(nums, 0)
    mp[nums] = val+1
    mx = max(mx, val+1)

tot = 0
for k, v in mp.items():
    if v == mx: tot += mx

print(tot)