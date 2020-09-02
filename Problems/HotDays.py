import math

total = 0
n, m = map(int, input().split())
for _ in range(n):
    t, T, x, cost = map(int, input().split())

    if T >= (t+m):
        total += cost
    else:

        mini = cost + (m*x)

        if(T-t <= 0):
            temp = mini
        else:
            if m % (T-t) > 0:
                maxi = min(cost * (math.ceil(m / (T - t))), cost *
                           math.floor(m / (T - t)) + x * ((m % (T - t)) + (T - t)))
            else:
                maxi = cost * math.floor((m / (T - t)))

            temp = min(maxi, mini)

        total += temp

print(total)
