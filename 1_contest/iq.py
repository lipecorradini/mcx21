def main():
    n = int(input())

    seq = input().split()

    for i in range(n):
        seq[i] = int(seq[i])

    l_even = -1
    l_odd = -1

    even = 0
    odd = 0
    for i in range(n):
        if seq[i] % 2 == 0:
            even += 1
            l_even = i
        elif seq[i] % 2 == 1:
            odd += 1
            l_odd = i
        if even > 1 and odd > 0:
            print(l_odd + 1)
            return
        if odd > 1 and even > 0:
            print(l_even + 1)
            return
main()