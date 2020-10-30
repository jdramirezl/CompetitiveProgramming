t = int(input())

for _ in range(t):
    case = list(map(int, input().split()))

    if case[0] == case[1] == case[2]:
        print("YES")
        print(case[0], case[1], case[2])
    elif (case[0] == case[1] and case[1] > case[2]) or (case[0] == case[2] and case[2] > case[1]) or (case[1] == case[2] and case[2] > case[0]):
        print("YES")
        print(max(case[0], case[1], case[2]),
              1, min(case[0], case[1], case[2]))
    else:
        print("NO")
