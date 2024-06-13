thing = dict()

n = int(input())

for i in range(n):
    ent = input().split()
    if(ent[0] not in thing):
        thing[ent[0]] = list(tuple())
        thing[ent[0]].append((int(ent[1]), i))
        
    else:
        prev = thing[ent[0]][-1][0]
        thing[ent[0]].append((prev + int(ent[1]), i))

# print(thing)

max_value = 0
round_max = n + 1
max_person = ""
for k in thing:
    item = thing[k][-1]
    if item[0] > max_value:
        max_value = item[0]
        round_max = item[1]
        max_person = k
    elif item[0] == max_value:
        rd1 = n

        for i in thing[k]:
            if i[0] >= max_value:
                rd1 = i[1]
                break
        
        rd2 = n
        for i in thing[max_person]:
            if i[0] >= max_value:
                rd2 = i[1]
                break
    
        if rd1 < rd2:
            max_value = item[0]
            round_max = item[1]
            max_person = k
        

print(max_person)