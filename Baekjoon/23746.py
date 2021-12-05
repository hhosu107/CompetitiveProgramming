n = int(input())

comp = {}
for i in range(n):
    pat, key = input().split()
    comp[key] = pat
compstr = input()
s, e = map(lambda x: int(x), input().split())
decompstr = ''.join(map(lambda x: comp[x], compstr))
print(decompstr[s-1:e])
