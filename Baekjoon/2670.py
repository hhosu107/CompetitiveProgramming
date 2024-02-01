from decimal import *

n = int(input())
values = []
for i in range(n):
    x = Decimal(input())
    values.append(x)
best = Decimal(1)
curr = Decimal(1)
all_low = True
low_max = 0.0
for x in values:
    curr = max(Decimal(1), curr * x)
    best = max(best, curr)
    if x >= Decimal(1):
        all_low = False
    low_max = max(low_max, x)
if all_low:
    print("{:.3f}".format(low_max))
else:
    print("{:.3f}".format(best))
