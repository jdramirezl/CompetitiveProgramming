n, a, b = map(int, input().split())
people = tuple(map(int, input().split()))

extras = 0

denied = 0

for i in range(n):
    person = people[i]
    if person == 1:
        if a > 0:
            a -= 1
        elif b > 0:
            b -= 1
            extras += 1
        elif extras > 0:
            extras -= 1
        else:
            denied += 1
    else:
        if b > 0:
            b -= 1
        else:
            denied += 2

print(denied)
