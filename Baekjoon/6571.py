fib = []

x = 1
y = 1
l, r = 0, 0
while True:
    t = x + y
    x = y
    y = t
    if x > 10e100:
        break
    fib.append(x)
a, b = list(map(int, input().split()))
while not (a == 0 and b == 0):
    cnt = 0
    for f in fib:
        if f >= a and f <= b:
            cnt += 1
        elif f > b:
            break

    print(cnt)
    a, b = list(map(int, input().split()))
