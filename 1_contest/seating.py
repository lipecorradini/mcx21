def main():
    n, m = [int(x) for x in input().split()]

    bus = [-1 for x in range(4 * n)]
    prev = 2 * n + 1
    cont = 1

    for i in range(1, 2*n + 1):
        if m >= i:
            bus[2 * i - 1] = cont
            cont += 1
        else:
            break

    if m > 2 * n:
        m -= 2 * n
        for i in range(0, m):
            bus[2*i] = prev
            prev += 1

    for i in bus:
        if i > 0:
            print(i, end=' ')
    return


main()
