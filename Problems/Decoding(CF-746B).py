n = int(input())
s = list(input())
new = ""
val = n - 2

while val >= 0:
    new += s[val]
    val -= 2

if n % 2 == 0:
    val = 1
else:
    val = 0

while val < n:
    new += s[val]
    val += 2


print(new)