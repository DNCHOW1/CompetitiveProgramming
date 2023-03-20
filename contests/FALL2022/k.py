from collections import Counter
n = int(input())
nums = list(map(int, input().split(" ")))
N = len(nums) # SHOULD BE EVEN
mid = N//2
c = Counter(nums)

cond = True
for k in c.keys():
    if c[k]%2:
        cond = False
        print("NO")


# def sym(mid):
#     return nums[:mid] == nums[mid:][::-1]

def expand(s, low, high, k):
    while low >= 0 and high < len(s) and s[low] == s[high]:
        if high - low + 1 == k:
            return True
 
        low = low - 1
        high = high + 1
 
    return False

def longestPalindrome(arr, k):
    for i in range(len(arr) - 1):
        if expand(arr, i, i, k) or expand(arr, i, i + 1, k):
            return True
 
    return False

def longestPalindromeM(s, L):
        T = '#'.join('^{}$'.format(s))
        n = len(T)
        P = [0] * n
        C = R = 0
        for i in range (1, n-1):
            P[i] = (R > i) and min(R - i, P[2*C - i]) # equals to i' = C - (i-C)
            # Attempt to expand palindrome centered at i
            while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
                P[i] += 1
    
            # If palindrome centered at i expand past R,
            # adjust center based on expanded palindrome.
            if i + P[i] > R:
                C, R = i, i + P[i]
    
        # Find the maximum element in P.
        # maxLen, centerIndex = max((n, i) for i, n in enumerate(P))
        # return s[(centerIndex  - maxLen)//2: (centerIndex  + maxLen)//2]

        # Find the palindrome with length L if exists
        eq = [(n, i) for i, n in enumerate(P) if n == L]
        print(eq)
        if not eq:
            return None
        length, centerIndex = eq
        return s[(centerIndex  - length)//2: (centerIndex  + length)//2]


if cond:
    nums += nums[:] # add copy to current
    numsN = len(nums)
    nums = list(map(str, nums))
    nums = ''.join(nums)

    print("YES" if longestPalindromeM(nums, 0) else "NO")

    # print("YES" if cond else "NO")