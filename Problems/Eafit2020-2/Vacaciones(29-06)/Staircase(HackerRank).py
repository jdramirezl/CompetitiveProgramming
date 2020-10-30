n = int(input())
spc = n - 1

for x in range(n):
    line = ""

    # spaces
    for l in range(spc):
        line += " "

    # tags
    for a in range(n-spc):
        line += "#"

    spc -= 1
    print(line)