from itertools import permutations
from copy import deepcopy

def power(x, y, m):
    if (y == 0):
        return 1
    p = power(x, y // 2, m) % m
    p = (p * p) % m
    return p if (y % 2 == 0) else (x * p) % m

def fermat_little(a, m):
    return power(a, m-2, m)

def reduced_fraction_as_fermat(a, b):
    # a / b === a * b^(m-2) mod m
    m = 1000000007
    return (a * fermat_little(b, m)) % m

def main():
    T = int(input())
    for t in range(1, T+1):
        n = int(input())
        string = input()
        order = [i for i in range(n)]
        permute = permutations(order)
        candies = 0
        for p in permute:
            real_str = deepcopy(string)
            real_p = list(deepcopy(p))
            for i in range(n):
                real_str = real_str[:real_p[i]] + real_str[real_p[i] + 1:]
                for j in range(i + 1, n):
                    if real_p[j] > real_p[i]:
                        real_p[j] -= 1
                if len(real_str) == 0 or real_str == real_str[::-1]:
                    candies += 1
        fact = 1
        for i in range(1, n + 1):
            fact *= i
        candy_fermat = reduced_fraction_as_fermat(candies, fact)
        print(f'Case #{t}: {candy_fermat}')

if __name__ == '__main__':
    main()
