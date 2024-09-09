def main():

    seq = input()

    sets = dict()
    curr = ''
    for i in seq:
        if i == '4' or i == '7':
            if i not in sets and curr != '':
                sets[i] = 1
            elif i in sets and curr != '':
                sets[i] += 1
            curr += i
            if curr not in sets:
                sets[curr] = 1
            elif curr in sets:
                sets[curr] += 1

        else:
            curr = ''
    min = 0
    min_key = "7"*51

    for key in sets:
        if sets[key] > min:
            min = sets[key]
            min_key = key
        if sets[key] == min:
            if str(key) < str(min_key):
                min_key = key

    if min_key != "7"*51:
        print(min_key)
    else:
        print(-1)

    return


main()
