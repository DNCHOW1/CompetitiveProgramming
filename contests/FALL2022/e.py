n, m = map(int, input().split(" "))

points = [] # list of tuples: (x, type, add/remove)

'''
MISSED INSIGHTS
- 2nd elem in tuple should be operation(actually, this is debateable)
- max sprinkler reach needs to be min(n, x+r). This is because you wouldn't want to count past N
- For sprinkler remove operation, need to consider position+1.
    This is done because the sprinkler still affects that index, but 1 after it doesn't.
'''

# assume number line is 1 -> n
for i in range(m):
    x, r, type = input().split(" ")
    x = int(x)
    r = int(r)

    points.append((max(1, x-r), 1, type))
    points.append(((min(n, x+r)+1, -1, type)))

points.sort() # sort by the x coords

dank = 0
murky = 0
units = 0
count = 0

prev = None # Changes when conditions met
for curr, op, typ in points:
    if typ == 'murky':
        murky += op
    else:
        dank += op
    units += op
    
    if prev != None and not (units >= 4 and dank == murky):
        count += (curr-prev)
        prev = None

    elif units >= 4 and dank == murky:
        prev = curr

print(count)