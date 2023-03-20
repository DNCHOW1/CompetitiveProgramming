n = int(input())

powers = [1]
for i in range(91):
    powers.append(powers[-1]*3)

while n != 0:
    n -= 1
    binary = bin(n)
    output = []
    for bit in range(len(binary) - 1, 1, -1):
        if binary[bit] == '1':
            output.append(str(powers[len(binary) - 1 - bit]))


    print("{", ', '.join(output), "}")
    n = int(input())