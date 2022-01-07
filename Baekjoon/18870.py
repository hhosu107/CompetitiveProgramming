def main():
    points = {}
    n = int(input())
    values = list(map(int,input().split()))
    for idx, val in enumerate(values):
        if val not in points:
            points[val] = [idx]
        else:
            points[val].append(idx)
    points = sorted(points.items())
    zipped = [0] * n
    for idx, (_, val) in enumerate(points):
        for orig in val:
            zipped[orig] = idx
    print(' '.join(map(str, zipped)))

if __name__ == '__main__':
    main()
