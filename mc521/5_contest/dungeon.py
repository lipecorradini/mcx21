

def main():

    n = int(input())

    for _ in range(n):
        a, b, c = [int(x) for x in input().split()]
        s = a + b + c;
        k = s/9
        if(s % 9 == 0 and a >= k and b >= k and c >= k):
            print("YES")
        else:
            print("NO")

main()