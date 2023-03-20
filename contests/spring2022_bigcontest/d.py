n = int(input())
seen = dict()
while n:
    temp = input().split(" ")
    if(temp[0] not in seen): seen[temp[0]] = set()
    seen[temp[0]].add(temp[-1])
    n -= 1

been = set()
stack = ["cats"]

flag = False
while len(stack) != 0:
    key = stack.pop()
    if(key == "great"):
        flag = True
        break
    if (key in been) or (key not in seen):
        continue
    been.add(key)
    for k in seen[key]: stack.append(k)

if flag:
    print("Cats are great! :D")
else:
    print("Cats are not great :(")