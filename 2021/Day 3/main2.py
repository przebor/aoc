from typing import Literal

name = "input.txt"

def reverse(s):
    n = ""
    for i in s:
        if i == "0": n += "1"
        else: n += "0"
    return n

def count_raw(s, p, m) -> Literal[0, 1]:
    vals = {0: 0, 1: 0}
    for j in s:
        if j[p] == "0":
            vals[0] += 1
        else:
            vals[1] += 1
    if vals[0] > vals[1]:
        return 0 + m
    else:
        return 1 - m

def count_dominant_on_position(s, p) -> Literal[0, 1]:
    return count_raw(s, p, 0)

def count_lesser_on_position(s, p) -> Literal[0, 1]:
    return count_raw(s, p, 1)

with open(name, "r") as f:
    ox = f.read().splitlines()
    co = ox.copy()
    i = 0
    while len(ox) > 1:
        val = count_dominant_on_position(ox, i)
        n = ox.copy()
        for j in ox:
            if j[i] != str(val):
                n.remove(j)
        i += 1
        ox = n.copy()
    i = 0
    while len(co) > 1:
        val = count_lesser_on_position(co, i)
        n = co.copy()
        for j in co:
            if j[i] != str(val):
                n.remove(j)
        i += 1
        co = n.copy()
    print(ox)
    print(co)
    print(int(ox[0], 2) * int(co[0], 2))