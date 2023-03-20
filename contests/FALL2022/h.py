from collections import defaultdict
n, k = map(int, input().split(" "))
arr = list(map(int, input().split(" ")))

windowMap = defaultdict(int) # store the counts for numbers less than k
lower = k # the amount of numbers that must be lower than k
l = r = 0 # pointers
total = 0

# Forgot that total should only increment if windowMap[k] is 0
# In the main function forgot to have l != n

