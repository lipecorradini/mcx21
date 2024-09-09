sum = input().split("+")

for i in range(len(sum)):
    sum[i] = int(sum[i])

sorted_Sum = sorted(sum)

for i in range(len(sum)):
    print(sorted_Sum[i], end="")
    if i != len(sum) - 1:
        print("+", end="")
