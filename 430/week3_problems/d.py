from sys import stdin

ops = set(["intersection", "union", "difference"])

mp = {}
for line in stdin:
    inp = line.strip("\n").split(" ")
    if inp[0] == "group":
        name = inp[1]
        mp[name] = set(inp[3:])
    elif inp[0] in ops:
        stack = [inp[0]]
        res = []
        i = 1
        while (len(stack) != 1 or stack[-1] != "-"):
            S = inp[i]
            while(len(stack) > 0 and (S not in ops) and (stack[-1] not in ops)):
                B = stack.pop()
                OP = stack.pop()

                set2 = mp[S] if S != "-" else res.pop()
                set1 = mp[B] if B != "-" else res.pop()

                if OP == "union":
                    temp = set1.union(set2)
                elif OP == "intersection":
                    temp = set1.intersection(set2)
                else:
                    temp = set1.difference(set2)

                S = "-"
                res.append(temp)

            stack.append(S)
            i += 1
        if i != len(inp):
            raise Exception
        print(" ".join(sorted(res.pop())))
    else:
        print(" ".join(sorted(mp[inp[0]])))