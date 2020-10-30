import math

n, x = map(int, input().split())
founds = map(int, input().split())

total = sum(founds)
a = total * -1

if a < 0:
    divs = math.floor(a / 2)
else:
    divs = math.ceil(a / 2)

i = 2
cards = 0

if total != 0:
    cards = 1
    if abs(a) > abs(x):
        cards = 2
        while abs(divs) > abs(x):
            i += 1

            if a < 0:
                divs = math.floor(a / i)
            else:
                divs = math.ceil(a / i)

            cards += 1

print(cards)
