def main():
    a, b, c, d = [int(part) for part in input().split()]

    rate = d/b
    total = 0
    if rate <= c:
        while a >= b:
            total += d
            a -= b
    if a > 0:
        if d < a * c and rate <= c:
            total += d
        else: 
            total += c * a
    print(total)
    return

main()