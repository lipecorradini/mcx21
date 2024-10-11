a = str()

def recursion(l, r):
    if(l > r): return 0
    elif (l == r): return 1

    if a[l] == a[r]:
        return 2 + recursion(l + 1, r - 1)
    else:
        return max(recursion(l, r - 1), recursion(l + 1, r))

def main():
    t = int(input())
    global a
    for i in range(t):
        a = str(input())
        print(recursion(0 , len(a) - 1))

main()

