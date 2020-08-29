n, k = map(int, input().split())
arr = set(map(int, input().split()))

count = 0

for x in arr:
    if (x+k) in arr: count += 1

print(count)