import numpy as np

print(
    np.poly([-1, 1, 1, 10])
)  # [1 -1 9 11 -10]. Coefficient of a polynomial with the given sequence of roots
print(
    np.roots([1, 0, -1])
)  # [-1, 1]. Roots of a polynomial with the given coefficients.
print(
    np.polyint([1, 1, 1])
)  # [1/3, 1/2, 1/1, 0]. Antiderivative (indefinite integral) of a polynomial with given coefficients.
print(
    np.polyder([1, 1, 1, 1])
)  # [3, 2, 1]. Derivative of a polynomial with given coefficients.
print(np.polyval([1, -2, 0, 2], 4))  # 34. Evaluates a polynomial at specific value.
print(
    np.polyfit([0, 1, -1, 2, -2], [0, 1, 1, 4, 4], 2)
)  # [1, 0, -3.97205465e-16]. Fits a polynomial of a specified order to a set of data using a least squares approach.
# np.polyadd/polysub/polymul/polydiv.
