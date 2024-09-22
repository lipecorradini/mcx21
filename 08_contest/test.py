n = 10000000000000000000000

cont = 0
ans = 0

while(cont < 201):
    ans = 0
    for i in range(1, cont + 1):
        ans += i ** i

    print(cont, ": ", ans % 10)
    cont += 1