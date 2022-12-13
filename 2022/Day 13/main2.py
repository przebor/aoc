import ast, sys
from functools import cmp_to_key

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

idx1, idx2 = 0,0

with open(sys.argv[1], 'r') as f:
    content_raw = f.readlines()
    content = []

    for line in content_raw:
        if line.strip() != '':
            content.append(ast.literal_eval(line.strip()))

    content.append([[2]])
    content.append([[6]])
    content.sort(key=cmp_to_key(compare))

    for i in range(len(content)):
        c = content[i]
        if c == [[2]]:
            idx1 = i+1
        elif c == [[6]]:
            idx2 = i+1
    print(idx2*idx1)

