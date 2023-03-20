n, m = map(int, input().split(" "))

strings = set(input().split(' '))
output = []

for i in range(m):
    inp = input().split(' ')
    num, strs = int(inp[0]), inp[1:]
    strings.difference_update(set(strs))
    output.extend(strs)

output.extend(list(strings))
print(' '.join(output))