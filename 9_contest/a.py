from math import ceil 
t = int(input())


for i in range(t):
    n, k = [int(x) for x in input().split()]
    arr = []
    pos = dict()
    ops = 0
    arr = input().split()
    arr.insert(0, -1)

    for j in range(1, n + 1):
        arr[j] = int(arr[j])
        pos[arr[j]] = j
    
    prev_pos = pos[1]
    
    for j in range(1, n, k):
        vaimudar = False
        cont = 0
        curr_j = j + 1
        while (cont < k):
            if((pos[curr_j - 1] > pos[curr_j] or pos[curr_j - 1] < prev_pos)):
                print(f"vai mudar pro currj: {curr_j}, sendo o j: {j}")
                vaimudar = True
            curr_j += 1
            cont += 1
            if(vaimudar):
                ops += ((n - j)/k)
                break
        if(vaimudar):
                break
        prev_pos = pos[j]
    
    print(ops)

