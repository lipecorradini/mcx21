def main():

    n = int(input())
    arr = [int(x) for x in input().split()]

    arr.insert(0, -1)

    if (n == 2):
        print("NO")
        return

    for i in range(1, n + 1):

        prox1 = arr[i]
        prox2 = arr[prox1]
        prox3 = arr[prox2]
        if arr[prox3] == prox1:
            print("YES")
            return

    print("NO")
    return


main()
