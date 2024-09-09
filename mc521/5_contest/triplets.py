def main():

    n = int(input())

    ratios = []
    for i in range(n):
        a, b = [int(x) for x in input().split()]
        if(a != 0):
            ratios[i] = b / a
        elif(a == 0 and b == 0):
            ratios[i] = -1 
        elif(a == 0):
            ratios[i] = b
        else:
            ratios = a
main()