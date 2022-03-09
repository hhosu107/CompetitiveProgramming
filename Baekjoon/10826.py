n = int(input())

x = 0
y = 1
for i in range(n):
    t = x + y
    x = y
    y = t
print(x)
