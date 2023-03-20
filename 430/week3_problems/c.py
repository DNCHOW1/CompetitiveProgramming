# from sortedcontainers import SortedList
import btree

n = int(input())
for i in range(n):
    input()

# sl = SortedList([(3, 25), (5, 6), (8, 10)])
# print(sl.bisect_left((7, 1e9)))

# n = int(input())
# sl = SortedList()
# out = []
# for i in range(n):
#     inp = input().split(" ")
#     op = inp[0]
#     E = int(inp[1])
#     if op == "add": 
#         G = int(inp[2])
#         sl.add((E, G))
#     else:
#         # E less than all in list, ind = 0
#         # E > all in list, ind = len(sl)
#         # E somewhat within list, ind -> [1, len(sl)]
#         tot_gold = 0
#         while E > 0 and len(sl) >= 1:
#             ind = sl.bisect_left((E, 1e9)) - 1
#             if ind < 0: break

#             energy, gold = sl.pop(ind) # Erase from within the sorted list
#             E -= energy
#             tot_gold += gold

#         out.append(tot_gold)
        
# for g in out:
#     print(g)