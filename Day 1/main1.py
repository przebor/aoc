name = "input.txt"

with open(name, "r") as f:
    d = f.read()
    d = d.splitlines()
    p = 0
    c = 0
    for i in d:
        if int(i) > p:
            c+=1
        p = int(i)
print(c-1)
