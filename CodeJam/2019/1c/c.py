def gcd(a, b):
    while b != 0:
        temp = a % b
        a = b
        b = temp
    return abs(a)


"""problem: if ABA pattern has been inserted at the first 3 characters, for instance,
then two numbers are the same, so it cannot be splitted into two primes."""


def main():
    T = int(input())
    for t in range(T):
        [N, L] = [int(x) for x in input().split(" ")]
        crypt = [int(x) for x in input().split(" ")]
        print("Case #" + str(t + 1) + ": ", end="")
        original = [0] * (L + 1)
        for i in range(1, L + 1):
            original[i] = gcd(crypt[i - 1], crypt[i])
            if original[i] < crypt[i - 1]:
                break
        for j in range(i - 1, -1, -1):
            original[j] = crypt[j] // original[j + 1]
        for j in range(i + 1, L + 1):
            original[j] = crypt[j - 1] // original[j - 1]
        primes = []
        for i in range(L + 1):
            if original[i] not in primes:
                primes.append(original[i])
        primes.sort()
        cipherdict = {}
        character = ord("A")
        for p in primes:
            cipherdict[p] = chr(character)
            character += 1
        for o in original:
            print(cipherdict[o], end="")
        print("")


if __name__ == "__main__":
    main()
