import math

def divisors(a):
    div = []
    max = []
    for i in range(1, int(math.sqrt(a)) + 1):
        if a % i == 0:
            div.append(i)
            max.append(int(a/i))
    for i in range(len(max) - 1, -1 , -1):
        div.append(int(max[i]))

    return div

def main():
    n, m = input().split()
    n = int(n)
    m = int(m)

    div = divisors(m)
    min_value = m / n

    while(div[-1] > min_value):
        div.pop()

    print(div[-1])

main()
