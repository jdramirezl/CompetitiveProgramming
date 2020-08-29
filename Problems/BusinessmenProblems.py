n = int(input())

total = dict()

for i in range(n):
    a, b = map(int, input().split())
    total[a] = b

m = int(input())

for i in range(m):
    a, b = map(int, input().split())

    if a in total:
        if b > total[a]:
            total[a] = b
    else:
        total[a] = b

print(sum(total.values()))
