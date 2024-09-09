def main():
    n, m = [int(x) for x in input().split()]

    mat = []
    for i in range(n):
        mat.append(["."] * m)

    cont = 0

    for i in range(n):
        if (i % 2 == 1):
            if (cont % 2 == 1):
                mat[i][0] = "#"
            else:
                mat[i][m - 1] = "#"
            cont += 1
        for j in range(m):
            if (i % 2 == 0):
                mat[i][j] = "#"

    for i in range(n):
        for j in range(m):
            print(mat[i][j], end='')
        print()


main()
