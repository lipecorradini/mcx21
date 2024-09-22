def generate():
    cont = 0
    ans = 0
    lista = []
    while(cont < 100):
        ans = 0
        for i in range(1, cont + 1):
            ans += i ** i
        cont += 1

        lista.append(ans % 10)
    return lista

def main():

    while True:
        n = int(input())
        if(n == 0): break
        sequence = generate()
        print(sequence[n%100])
    
    return

main()