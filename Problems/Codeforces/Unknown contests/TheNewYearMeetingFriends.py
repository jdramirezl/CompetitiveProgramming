list1 = list(map(int, input().split()))
list1.sort()
total = (list1[2]-list1[1])+(list1[1]-list1[0])
print(total)
