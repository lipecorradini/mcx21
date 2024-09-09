
from math import gcd
n = int(input())

trees = []

for i in range(n):
    x = int(input())
    trees.append(x)

dist = []
for i in range(1, n):
    dist.append(trees[i] - trees[i - 1])

greater = dist[0]
for i in range(1, n - 1):
    greater = gcd(dist[i], greater)

print(int((trees[-1] - trees[0])/greater - n + 1))