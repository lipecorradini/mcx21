def main():
    pos = [2, 7, 2, 3, 3, 4, 2, 5, 1, 2]
    n = int(input())
    uni = n % 10
    dez = int((n - uni)/10)
    
    if(dez<0):dez=0
    
    tot = pos[uni] * pos[dez]
    print(tot)


main()