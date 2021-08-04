# Fibonacci number: f_0 = 0, f_1 = 1, f_n+2 = f_n+1 + f_n.
`f(n+2) = f(n+1) + f(n)` but too slow.

```
| f(n+2) | = | 1 1 | |f(n+1)| = | 1 1 |^(n+1).
| f(n+1) | = | 1 0 | |f(n)  |   | 1 0 |
```

```
F_2n-1 = F_n^2 + F_n-1^2
F_2n = (F_n-1 + F_n+1)F_n = (2F_n-1 + F_n)F_n
```

```
sum(i=1 to n) F_i = F_n+2 - 1
sum(i=1 to n) F_2i = F_2i+1 - 1
sum(i=0 to n) F_2i+1 = F_2(n+1)
sum(i=1 to n) F_i^2 = F_n * F_n+1
gcd(F_n, F_m) = F_(gcd(n, m))
```
