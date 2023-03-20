def can_type_string(s):
    # Initialize the prefix function to 0
    prefix = [0] * len(s)

    # Calculate the prefix function using the KMP algorithm
    j = 0
    for i in range(1, len(s)):
        while j > 0 and s[i] != s[j]:
            j = prefix[j - 1]
        if s[i] == s[j]:
            j += 1
        prefix[i] = j

    # Check if there exists a proper prefix-suffix of s
    return prefix[-1] > 0

# Read input
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()

    # Check if it is possible to type s using strictly less than n operations
    if can_type_string(s):
        print("YES")
    else:
        print("NO")
