name = "input.txt"

with open(name, "r") as f:
    d = f.read()
    d = d.splitlines()
    p = 0
    c = 0
    n = []
    for i in range(len(d)):
        if(i+3>len(d)):
            continue
        n.append(int(d[i]) + int(d[i+1]) + int(d[i+2]))
    for i in n:
        if int(i) > p:
            c+=1
        p = int(i)
print(c-1)
