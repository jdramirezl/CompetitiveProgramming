p = int(input())

for n in range(p):
    str1 = input()
    str2 = input()

    dic = dict()

    for f in str2:
        if f in dic:
            dic[f] += 1
        else:
            dic[f] = 1

    ans = "NO"

    for c in str1:
        if c in dic:
            ans = "YES"
            break

    print(ans)