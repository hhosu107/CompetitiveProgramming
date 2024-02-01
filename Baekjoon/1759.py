from typing import List


def crypt_tracking(
    char_set: List[str],
    used: List[bool],
    aeiou: bool,
    bowel: int,
    idx: int,
    used_chars: int,
    needed_chars: int,
):
    if used_chars == needed_chars:
        if aeiou == True and bowel >= 2:
            for c, u in zip(char_set, used):
                if u:
                    print(c, end="")
            print("")
        return
    if idx == len(char_set):
        return
    used[idx] = True
    crypt_tracking(
        char_set,
        used,
        aeiou or (char_set[idx] in ["a", "e", "i", "o", "u"]),
        bowel + (1 if (char_set[idx] not in ["a", "e", "i", "o", "u"]) else 0),
        idx + 1,
        used_chars + 1,
        needed_chars,
    )
    used[idx] = False
    crypt_tracking(char_set, used, aeiou, bowel, idx + 1, used_chars, needed_chars)
    return


def main():
    l, c = list(map(int, input().split()))
    char_set = sorted(input().split())
    used = [False] * c
    crypt_tracking(char_set, used, False, 0, 0, 0, l)


if __name__ == "__main__":
    main()
