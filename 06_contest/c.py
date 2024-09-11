from math import sqrt, ceil

n = int(input())

for i in range(n):
    x = int(input())
    cont = 0
    for j in range(1, ceil(sqrt(x) + 1)):
        if (x % j == 0): 
            cont += 2
            if(j == ceil(sqrt(x))): cont -= 1

    print(cont)