t = int(input())

dic = dict()

for _ in range(t):
    dic.clear()

    m = int(input())
    nums = map(int, input().split())

    for n in nums:
        if n in dic:
            continue
        else:
            dic[n] = 1
            print(n, end=' ')

    print()
