
def main():
    first = str(input())
    target = str(input())

    first = first.upper()
    target = target.upper()

    for i in range(len(first)):
        if first[i] > target[i]:
            print("1")
            return
        elif target[i] > first[i]:
            print("-1")
            return

    print("0")
    return


main()
