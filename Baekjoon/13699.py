n = int(input())
bino = [[1]]
for i in range(1, 2 * n + 1):
    bino.append([])
    for j in range(i + 1):
        if j == 0:
            bino[i].append(1)
        elif j == i:
            bino[i].append(bino[i-1][j-1])
        else:
            bino[i].append(bino[i-1][j-1] + bino[i-1][j])
print(bino[2*n][n] // (n + 1))
