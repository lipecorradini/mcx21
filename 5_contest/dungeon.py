def minimal(a, b, c):
    if(a <= b and a <= c):
        return a
    if(b <= c):
        return b
    else:
        return c

def evaluate(min, max, a, b, c):
    
    s = a + b + c;
    x = (min + max) // 2
    k = x // 7

    if(s <= 3):
        print("NO")
        return

    if(x % 7 == 0):
        print("YES")
        return
        
    if(abs(min - max)/2) < 1:
        print("NO")
        return

    elif(k >= minimal(a, b, c)):
        return evaluate(min, x, a, b, c)

    else:
        return evaluate(x, max, a, b, c)

def main():

    n = int(input())

    for _ in range(n):
        a, b, c = [int(x) for x in input().split()]
        s = a + b + c;
        min = 0
        evaluate(min, s, a, b, c)

main()