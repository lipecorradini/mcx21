
def main():
    t = int(input())

    for _ in range(t):
        isdone = [False, False]
        b, t1, a1, t2, a2 = [int(x) for x in input().split()]
        times = [0, 0]

        # 1 parte
        if (t1 < t2):
            if a1 > b * (t2 - t1):
                a1 -= b * (t2 - t1)
                times[0] += (t2 - t1)
            else:
                times[0] = float(a1/b)
                a1 = 0
                isdone[0] = True

        # 2 parte: intersecao
        if (isdone[0] == False and isdone[1] == False):
            amenor = min(a1, a2)
            times[0] += (amenor * 2) / b
            times[1] += (amenor * 2) / b

            a1 -= amenor
            a2 -= amenor

            if a1 == 0:
                isdone[0] = True
            if a2 == 0:
                isdone[1] = True

        # 3 o sozinho
        if a1 != a2:  # acabaram juntos

            if isdone[0] == False:  # ele falta
                times[0] += float(a1/b)

            elif isdone[1] == False:
                times[1] += float(a2/b)

        print(f"{times[0]:.10f}", end=" ")
        print(f"{times[1]:.10f}")


main()
