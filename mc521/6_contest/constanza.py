
def fib(n, memo):
    if n < 2:
        return n
    elif n in memo:
        return (memo[n]) % (1e9 + 7)
    else:
        memo[n] = (fib(n - 1, memo) % (1e9 + 7)) + (fib(n - 2, memo) % (1e9 + 7))
        return memo[n] % (1e9 + 7)

def main():

    word = str(input())

    memo = [-1] * (10 ** 5)

    i = 0
    tot = 1
    curr_u = 0
    curr_n = 0

    vec = []

    last = ''

    while i != len(word):

        a = word[i]
        
        if(word[i] == 'm' or word[i] == 'w'):
           print(0)
           return
        
        elif(last == 'u' and a == 'u'):

            if(curr_u == 0):
                curr_u += 2
            else:
                curr_u += 1
                    
        elif(last == 'n' and a == 'n'):

            if(curr_n == 0):
                curr_n += 2
            else:
                curr_n += 1

        elif(last == 'u' and curr_u > 0):

            vec.append(curr_u)
            curr_u = 0

        elif(last == 'n' and curr_n > 0):

            vec.append(curr_n)
            curr_n = 0
            
        last = word[i]
        i += 1

    if(i > 1 and word[i-1] == 'u' and word[i-2] == 'u'):
        vec.append(curr_u)
    
    if(i > 1 and word[i-1] == 'n' and word[i-2] == 'n'):
        vec.append(curr_n)

    # print(vec)
    for x in vec:
        # print("x do vec: ",x)
        if(x < 5):
            tot *= (x  % (10 ** 9 + 7))
        else:
            tot *= (fib(x + 1, memo) % (10 ** 9 + 7))
            
        tot = tot % (10 **9 + 7)
        
    if(tot == 0): print(1)
    else: print(tot)
    return
        
main()