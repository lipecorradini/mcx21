
q = int(input())

for i in range(q):

    n, k = [int(x) for x in input().split()]
    arr = [x for x in input()]
    
    p0 = 0
    curr_0 = 0

    while(True):
        if(p0 >= len(arr) - 1): break
        
        while(arr[p0] != '0'):
            p0 += 1
        
        if(k >= p0 - curr_0):
            k -= (p0 - curr_0)
            arr[p0] = '1'
            arr[curr_0] = '0'
            curr_0 += 1
        
        else:
            arr[p0 - k] = '0'
            arr[p0] = '1'
            break
        
    for letter in arr:
        print(letter, end='')
    print()

