a, b = map(int, input().split())

arr = [[0] * (a + 1) for _ in range(a + 1)]

for i in range(1, a + 1):
    for j in range(0, i + 1):
        if i == j or j == 0:
            arr[i][j] = 1
        else:
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]
print(arr[a][b])
