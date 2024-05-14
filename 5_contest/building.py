from math import ceil

def find_total_per_height(height, corals):
    sum_h = 0
    for coral in corals:
        if coral < height:
            sum_h += height - coral
    return sum_h

def find_amount(min_height, max_height, corals, n, x):
    
    valor = abs((min_height + max_height)/2)
    mid = find_total_per_height(ceil(valor), corals)

    if abs((min_height - max_height)/2) < 1:
        if mid <= x:
            return max_height
        else:
            return min_height

    elif mid > x:
        return find_amount(min_height, (min_height + max_height) // 2, corals, n, x)

    return find_amount((min_height + max_height) // 2, max_height, corals, n, x)

def solve(n, x):
    corals = list(map(int, input().split()))

    min_height = 0
    max_height = x + sum(corals)

    print(find_amount(min_height, max_height, corals, n, x))

def main():
    v = int(input())

    for _ in range(v):
        n, x = [int(a) for a in input().split()]
        solve(n, x)

if __name__ == "__main__":
    main()
