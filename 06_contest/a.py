factors = dict()

# algrithm largely based on https://www.rookieslab.com/posts/fastest-way-to-check-if-a-number-is-prime-or-not

def is_prime(n):
    """
    Assumes that n is a positive natural number
    """
    # We know 1 is not a prime number
    if n == 1:
        return False

    i = 2
    # This will loop from 2 to int(sqrt(x))
    while i*i <= n:
        # Check if i divides x without leaving a remainder
        if n % i == 0:
            # This means that n has a factor in between 2 and sqrt(n)
            # So it is not a prime number
            return False
        i += 1
    # If we did not find any factor in the above loop,
    # then n is a prime number
    return True

def factorize(n):
    """
    Assumes that n is a positive natural number
    """
    if n == 1:
        return False

    i = 2
    while i*i <= n:

        if n == i:
            break

        while n % i == 0:

            if i not in factors.keys():
                factors[i] = 1
                if is_prime(n//i):
                    n = (n//i)
                    factors[n//i] = 1
                    return
            else:
                factors[i] += 1
               

            n = (n // i)
        i += 1

    factors[n] = 1


def main():
    while True:
        n = int(input())
        if n == 0: return

        global factors
        factors.clear()

        factorize(n)
        # print(factors.keys())
        for exp in factors.keys():
            print(f"{exp}^{factors[exp]}", end = " ")
        print()

main()

