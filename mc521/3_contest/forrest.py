def main():

    n = int(input())


    for i in range(n):
        check = True
        graphs = dict()
        count = 1
        while (check):
            try:
                e = str(input())

            except:
                check = False

            if (e[0] == '*'):
                acorns = 0
                arr = str(input())
                new_arr = [0] * len(arr)

                # aqui, verifica se tem no sozinho
                for i in range(0, len(arr), 2):
                    for key in graphs:
                        if (arr[i] in graphs[key]):
                            new_arr[i] = 1
                            break

                for c in range(0, len(new_arr), 2):
                    if c == 0:
                        acorns += 1

                trees = len(graphs)

                print(f"There are {trees} trees and {acorns} acorn(s)")

                check = False

            if (check == True):
                # adiciona o vertice a uma arvore ou cria uma nova
                first = e[1]
                second = e[3]

                valid = False
                for key in graphs:
                    if first in graphs[key] or second in graphs[key]:
                        graphs[key].add(first)
                        graphs[key].add(second)
                        valid = True

                if (valid == False):
                    graphs[str(count)] = set()
                    graphs[str(count)].add(first)
                    graphs[str(count)].add(second)
                    count += 1


main()
