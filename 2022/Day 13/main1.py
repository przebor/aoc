import ast, sys

cnt = 0

def compare(a, b):
    #print(a, b)
    if (isinstance(a, int) and isinstance(b, int)):
        if (a < b):
            return -1
        elif (a > b):
            return 1
        else:
            return 0
    elif (isinstance(a, list) and not isinstance(b, list)):
        return compare(a, [b])
    elif (isinstance(b, list) and not isinstance(a, list)):
        return compare([a], b)
    
    for i in range(min(len(a), len(b))):
        x, y = a[i], b[i]
        ott = compare(x, y)
        if ott != 0:
            return ott
    
    if (len(a) < len(b)):
        return -1
    elif (len(a) > len(b)):
        return 1
    else:
        # SHOULDNT HAPPEN
        return 0

with open(sys.argv[1], 'r') as f:
    content_raw = f.readlines()
    content = []

    for line in content_raw:
        if line.strip() != '':
            content.append(line)


    num = 1

    for l1, l2 in zip(content[0::2], content[1::2]):
        l1s = ast.literal_eval(l1)
        l2s = ast.literal_eval(l2)

        if (compare(l1s, l2s) < 0):
            cnt += num
        num += 1

print(cnt)
