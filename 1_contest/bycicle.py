def main():
    n = int(input())
    an = [int(x) for x in input().split()]
    m = int(input())
    bn = [int(x) for x in input().split()]

    great = 0
    great_count = 0

    for i in range(n):
        for j in range(m):
            if (bn[j] >= an[i]):
                gear = bn[j]/an[i]
                if (gear % 1 == 0):
                    if (gear > great):
                        great = gear
                        great_count = 1
                    elif (gear == great):
                        great_count += 1
    print(great_count)
    return


main()
