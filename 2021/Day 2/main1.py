name = "input.txt"

with open(name, "r") as f:
    d = f.read().splitlines()
    depth = 0
    horizontal = 0
    for i in d:
        i = i.split(" ")
        v = int(i[1])
        if i[0] == "forward":
            horizontal += v
        elif i[0] == "down":
            depth += v
        elif i[0] == "up":
            depth -= v
print(depth*horizontal)
