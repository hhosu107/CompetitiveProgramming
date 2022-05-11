v6_short = input().split(':')
v6_len = len(v6_short)
empty_idx = v6_len
for i in range(v6_len-2, 0, -1):
    if not v6_short[i]:
        empty_idx = i
        break
v6_short_left = v6_short[:empty_idx]
v6_short_right = [] if empty_idx == v6_len else v6_short[empty_idx+1:]
v6_empty_center = ['0000'] * (8 - (len(v6_short_left) + len(v6_short_right)))
v6_left = ['0' * (4 - len(v)) + v for v in v6_short_left]
v6_right = ['0' * (4 - len(v)) + v for v in v6_short_right]
v6 = v6_left + v6_empty_center + v6_right
print(':'.join(v6))
