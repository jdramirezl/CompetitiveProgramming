n, m = map(int, input().split())

clicks = 0

if n == m:
    clicks = 0
    print(clicks)
elif n > m:
    clicks = n - m
    print(clicks)
else:
    while m > n:
        if m % 2 != 0:
            m += 1
            clicks += 1
        else:
            m //= 2
            clicks += 1

    if m == n:
        print(clicks)
    else:
        dif = n - m
        print(clicks+dif)
