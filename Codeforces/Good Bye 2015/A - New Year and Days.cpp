#!/usr/bin/python

inp = input().split()

if inp[2] == "week":
    week = int(inp[0]) - 1
    table = [52, 52, 52, 52, 53, 53, 52]
    ans = table[week]
else:
    month = int(inp[0]) - 1
    table = [12] * 29 + [11, 7]
    ans = table[month]

print(ans)
