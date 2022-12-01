name = "input.txt"

def reverse(s):
    n = ""
    for i in s:
        if i == "0": n += "1"
        else: n += "0"
    return n

with open(name, "r") as f:
    d = f.read().splitlines()
    h = ""
    width = len(d[0])
    for i in range(width):
        vals = {0: 0, 1: 0}
        for j in d:
            if j[i] == "0":
                vals[0] += 1
            else:
                vals[1] += 1
        if vals[0] > vals[1]:
            h += "0"
        else:
            h += "1"
    print(h)
    print(reverse(h))
    print(int(h, 2) * int(reverse(h), 2))