from sys import stdin

ops = set(["intersection", "union", "difference"])

mp = {}
for line in stdin:
    inp = line.strip("\n").split(" ")
    if inp[0] == "group":
        name = inp[1]
        mp[name] = set(inp[3:])
    elif inp[0] in ops:
        stack = []
        for i in range(len(inp)-1, -1, -1):
            if inp[i] in ops:
                s1 = stack.pop()
                s2 = stack.pop()
                if inp[i] == "intersection":
                    stack.append(s1.intersection(s2))
                elif inp[i] == "union":
                    stack.append(s1.union(s2))
                elif inp[i] == "difference":
                    stack.append(s1.difference(s2))
            else:
                stack.append(mp[inp[i]])
        
        print(" ".join(sorted(stack.pop())))
    else:
        print(" ".join(sorted(mp[inp[0]])))