max = 2 ** 31 - 1

def main():

    t = int(input())
    for _ in range(t):
        num_str = str(input())
        tot = 0
        curr = 0
        tamanho = len(num_str)
        i = 0
        while i < tamanho:
            n = int(num_str[i])
            
            if curr == 0 and tamanho - i < 20 and int(num_str[i:]) > max:
                print("entrou no digito ", n)
                print(f"o range é de {i} até {tamanho - 10}")
                max_i = i
                backup_i = i
                wasChanged = False
                max_num = int(num_str[i])
                for j in range(i, tamanho - 10):
                    if int(num_str[j]) > max_i:
                        if int(num_str[j]) > max_num:
                            backup_i = j
                        elif int(num_str[j:j+10]) < max:
                            max_i = j
                            wasChanged = True
                
                if wasChanged == False:
                    max_i = backup_i
                
                print("o max_i é ", max_i)
                print("o i é ", i)
                if i != max_i:
                    # print("eh diferente, claro")

                    tot += int(num_str[i:max_i]) # adiciona o remanescente no total
                    i = max_i # pula o i pra casa nova
                    # print("novo i: ", i)
                    curr = 0

            n = int(num_str[i])
            if curr * 10 + n > max:
                tot += curr
                curr = 0

            if i == tamanho - 1:
                if curr * 10 + n < max:
                    curr *= 10
                curr += n
                tot += curr
                curr = 0
                    # print(f"num: {num_str} atingiu o valor {tot}")
            
            else:
                curr *= 10
                curr += n
            # print(f"i: {i}, n = {n}, curr = {curr}, tot = {tot}")
            i+=1

        # print("\n")
        print(tot)

main()