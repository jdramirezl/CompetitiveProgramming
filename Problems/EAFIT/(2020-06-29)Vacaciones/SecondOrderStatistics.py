n = int(input())
first = map(int, input().split())
un_set = set()
rand_num = 0
enter = True

for ele in first:
    if enter:
        rand_num = ele
        enter = False
    un_set.add(ele)

# Iterate and find smallest
for x in un_set:
    if x < rand_num:
        rand_num = x

# Remove the smallest and find the smallest again
un_set.remove(rand_num)

if len(un_set) < 1:
    print("NO")
else:
    for rand in un_set:
        rand_num = rand
        break

    for y in un_set:
        if y < rand_num:
            rand_num = y

    print(rand_num)