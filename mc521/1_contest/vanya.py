def main():
    n, l = [int(x) for x in input().split()]
    an = [int(x) for x in input().split()]

    sort_an = sorted(an)

    max_dist = 0
    for i in range(0, len(sort_an) - 1):
        diff = sort_an[i+1] - sort_an[i]

        if(i == 0):
            max_dist = sort_an[0]
        
        elif(i == len(sort_an) - 2 and (l - sort_an[i] > max_dist)):
            max_dist = l - sort_an[i]

        elif(diff > max_dist and i < len(sort_an) - 2):
            max_dist = diff/2
 

    print(f"{float(max_dist):.10f}")


main()
