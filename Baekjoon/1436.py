def doom_nums(n: int) -> list:
    doom_string = '666'
    doom_set = set([666])
    for x in range(1, n+1):
        for y in range(0, pow(10, x)):
            z = str(y)
            if (y < pow(10, x - 1)):
                doom_set.add(int('666' + z.zfill(x)))
            else:
                for pos in range(len(z) + 1):
                    doom_set.add(int(z[:pos] + doom_string + z[pos:]))
    return sorted(doom_set)

def main():
    doom_set = doom_nums(4)
    x = int(input())
    print(doom_set[x - 1])

if __name__ == '__main__':
    main()
