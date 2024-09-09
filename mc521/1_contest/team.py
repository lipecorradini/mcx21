def main():
    num = int(input())
    prog = []
    math = []
    pe = []
    lista = input().split()

    for i in range(1, num+1):
        alu = int(lista[i - 1])
        if alu == 1:
            prog.append(i)
        elif alu == 2:
            math.append(i)
        elif alu == 3:
            pe.append(i)

    if len(prog) <= len(math) and len(prog) <= len(pe):
        min = len(prog)

    elif len(math) <= len(pe):
        min = len(math)

    else:
        min = len(pe)
    print(min)

    for i in range(min):
        print(f"{prog[i]} {math[i]} {pe[i]}")
    return


main()
