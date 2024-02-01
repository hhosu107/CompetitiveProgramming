import numpy as np

np_arr = np.array([list(map(int, input().split())) for _ in range(5)])
print(
    f"{np.std(np_arr, axis=None):.11f}"
)  # :xf means formatting float with x digits after the decimal point
