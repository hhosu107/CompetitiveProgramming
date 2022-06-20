import numpy as np
a = np.ones([2, 5, 3, 4]) # [2, 5] stack of [3, 4] shaped matrices
b = np.ones([2, 5, 4, 3]) # [2, 5] stack of [4, 3] shaped matrices
c = np.matmul(a, b)
print(c)
