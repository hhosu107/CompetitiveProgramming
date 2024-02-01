s = input()
e = input()


def find(t: str):
    if len(t) == len(s):
        return t == s
    if t[0] == "B" and find(
        t[:0:-1]
    ):  # B is put at the last and then flipped; thus B must be located at 0.
        return True
    if t[-1] == "A" and find(t[:-1]):  # A can only be put in the back.
        return True


print(f"{1 if find(e) else 0}")
