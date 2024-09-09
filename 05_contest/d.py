from math import log2, ceil

n, k = [int(x) for x in input().split()]

soma = 0
for i in range(1, n + 1):
    if(k/i > 1): soma += (1/n) * ((1/2)**ceil(log2(k/i)))
    else: soma += 1/n

print(soma)
