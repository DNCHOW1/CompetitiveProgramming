n = int(input())

binary = bin(n)
rev = ''.join(list(reversed(binary[2:])))
print(int(rev, 2))
# print(int())