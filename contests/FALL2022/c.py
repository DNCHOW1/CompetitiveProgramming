n, k, r = input().split(" ")
n, k = int(n), int(k)
r = float(r)
cuts = list(map(float, input().split(" ")))

def func(r, angle):
    import math
    return math.pi*(r**2)*(angle/360.0)

cutsN = len(cuts)
for i in range(2*cutsN):
    cuts.append(cuts[i]+180.0)

# go up till cutsN
windowSum = sum([cuts[i+1]-cuts[i] for i in range(k)])
sums = [windowSum]
for i in range(k, len(cuts)-1):
    windowSum += cuts[i+1]-cuts[i]
    windowSum -= cuts[i-k+1]-cuts[i-k]
    sums.append(windowSum)

angleMax = max(sums)

# print(cuts)
# print(sums)

print(func(r, angleMax))