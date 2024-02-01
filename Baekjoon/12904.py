s = input()
e = input()
valid = True
while len(e) > len(s):
    if e[-1] == "B":
        e = e[:-1]
        e = e[::-1]
    else:
        e = e[:-1]
print(f"{0 if e != s else 1}")
