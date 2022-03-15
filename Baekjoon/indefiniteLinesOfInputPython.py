from sys import stdin
lines = stdin.read().splitlines()

dp = [0] * 251
dp[0] = 1
dp[1] = 1
for n in range(2, 251, 1):
    dp[n] = dp[n-1] + 2 * dp[n-2]
for line in lines:
    n = int(line)
    print(dp[n])
