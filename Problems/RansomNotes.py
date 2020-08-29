m, n = map(int, input().split())
mag = input().split()
note = input().split()

magazine = dict()

for n in mag:
    if n in magazine:
        magazine[n] += 1
    else:
        magazine[n] = 1

ans = "No"

for n in note:
    if n in magazine and magazine[n] > 0:
        ans = "Yes"
        magazine[n] -= 1
    else:
        ans = "No"
        break

print(ans)