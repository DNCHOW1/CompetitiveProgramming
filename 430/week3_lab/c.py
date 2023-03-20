from sys import stdin

def toUnix(time):
    h, m, s = time.split(':')
    return int(h) * 3600 + int(m) * 60 + int(s)

def toTime(unix):
    # 3660
    h = unix//3600
    m = (unix%3600)//60
    s = (unix%(3600))%60
    return f"{h:02}:{m:02}:{s:02}"

prev = "00:00:01"
prevSpeed = 0
dist = 0
out = []
for line in stdin:
    line = line.strip("\n").split(" ")
    time = line[0]

    delta = toUnix(time) - toUnix(prev) # in seconds
    dist += prevSpeed * delta / 3600

    if len(line) == 2:
        prevSpeed = int(line[1])

    else: # Need to print stuff
        # print(f"{time} {dist} km")
        out.append(f"{time} {dist:.2f} km")
    
    prev = time

for o in out: print(o)