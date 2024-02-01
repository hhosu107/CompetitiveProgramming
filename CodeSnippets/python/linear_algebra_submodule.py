import numpy as np

print(np.linalg.det([[1, 2], [3, 2]]))  # -3.0, determinant.
vals, vecs = np.linalg.eig(
    [[1, 2], [2, 1]]
)  # eigenvalues and eigenvectors. vals: [3, -1], vecs: ...
print(np.linalg.inv([[1, 2], [2, 1]]))  # multiplicative inverse of a matrix
