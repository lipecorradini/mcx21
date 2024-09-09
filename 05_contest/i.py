a, b, c, d = [int(x) for x in input().split()]

smalr = a/b
zano = c/d

razao = (1 - smalr)*(1 - zano)

print(smalr / (1 - razao))