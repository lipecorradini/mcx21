def main():

    n = int(input())

    word = str(input())

    o = word.count('o')
    n = word.count('n')
    e = word.count('e')
   
    z = word.count('z')
    r = word.count('r')
    min1 = 0

    if o <= n and o <= e:
        min1 = o
    elif n <= e:
        min1 = n
    else:
        min1 = e

    o -= min1
    n -= min1
    e -= min1

    min2 = 0
    if o <= z and o <= r and o <= e :
        min2 = o
    elif e <= z and e <= r:
        min2 = e
    elif z <= r:
        min2 = z
    else:
        min2 = r

    for i in range(min1):
        print(1, end=" ")
    for j in range(min2):
        print(0, end=" ")


main()
    