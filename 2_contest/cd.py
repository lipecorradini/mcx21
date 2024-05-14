def main():
    n, m = [int(c) for c in input().split()]
    cds = set()

    for i in range(n):
        value = int(input())
        cds.add(value)
    
    cont = 0
    for j in range(m):
        value = int(input())
        if(value in cds):
            cont += 1
    


main()
