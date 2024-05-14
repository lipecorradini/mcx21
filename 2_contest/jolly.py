def main():
    check = True
    while (check):

        try:

            arr = [int(c) for c in input().split()]
            n = arr[0]
            arr.pop(0)

            isjolly = True
            ini_diff = n - 1

            diff_list = []

            for i in range(0, n - 1):
                diff = abs(arr[i+1] - arr[i])
                diff_list.append(diff)

            diff_list.sort(reverse = True)


            for i in range(n - 1):
                if (diff_list[i] != ini_diff):
                    isjolly = False
                    break
                ini_diff -= 1

            cont = 0
            for i in range(n):
                if (arr[i] == arr[0]):
                    cont += 1
                else:
                    break

            if (cont == n - 1):
                isjolly = True

            if (isjolly):
                print("Jolly")
            else:
                print("Not jolly")

        except:
            check = False


main()
