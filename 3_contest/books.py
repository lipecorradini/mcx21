def main():

    q = int(input())

    for i in range(q):
        n = int(input())
        arr = [int(x) for x in input().split()]
        for j in range(n):
            cont = 1
            prox = arr[j]
            while (prox != j+1):
                cont += 1
                prox = arr[prox - 1]
            print(cont, end=' ')
        print()


main()
