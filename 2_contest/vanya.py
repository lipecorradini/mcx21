def main():

    m = int(input())
    
    
    if(m < 10):
        print(m)
    
    else:
        pot = 10
        soma = 9
        n_dig = 2

        while (m >= pot*10):
                soma += n_dig * 9 * pot
                pot *= 10
                n_dig += 1
        
        new_m = m - pot + 1

        soma += new_m * n_dig
        print(soma)

main()