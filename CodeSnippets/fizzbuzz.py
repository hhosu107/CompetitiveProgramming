def fizz_buzz(limit):
    for i in range(1, limit + 1):
        if i % 3 == 0 and i % 5 == 0:
            print('fizzbuzz')
        elif i % 3 == 0:
            print('fizz')
        elif i % 5 == 0:
            print('buzz')
        else:
            print(i)

def main():
    lim = int(input())
    fizz_buzz(lim)


if __name__ == '__main__':
    main()