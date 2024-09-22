
numeros = []
operadores = []
mod = 0

def f(x):
    stack = []
    resultado = 0

    for token in numeros:
        # print("stack: ", stack)
        if token in operadores:
            b = (stack.pop())
            a = (stack.pop())
            if token == "+":
                resultado = a + b
                # print(f"{a} + {b} = {a + b}")
            elif token == "*":
                resultado = a * b
                # print(f"{a} + {b} = {a * b}")

            stack.append(resultado)
        else:
            if(token == 'x'): stack.append(x)
            elif token == 'N': stack.append(mod)
            else: stack.append(int(token))
    
    # print("resultado: ", stack[0])
    return stack[0] % mod

# o codigo abaixo foi extensamente baseado nos slides da disciplina
def floyd_cycle_finding(x0):

    tortoise = f(x0)
    hare = f(f(x0))
    while tortoise != hare:
        tortoise = f(tortoise)
        hare = f(f(hare))

    mu = 0
    hare = x0
    while tortoise != hare:
        tortoise = f(tortoise)
        hare = f(hare)
        mu += 1

    lam = 1  
    hare = f(tortoise)
    while tortoise != hare:
        # print("hare: ", hare)
        hare = f(hare)
        lam += 1

    return mu, lam 


def main():
    while True:
        entrada = input().split(" ")
        if(entrada[0] == '0'): return

        global numeros, operadores
        global mod
        mod = int(entrada[0])
        n = int(entrada[1])

        for coisa in entrada[2:-2]:
            if(coisa in ['+', '*', "%"]):
                operadores.append(coisa)
            
            numeros.append(coisa)

        # print(entrada[2:-2])
        # print("numeros: ",numeros)
        # print("operadores: ", operadores)

        mu, lam = floyd_cycle_finding(n)
        numeros = []
        operadores = []
        print(lam)

main()

        

    