input_file = open("input.txt")

priority_sum = 0
for line in input_file:
    pivot_ind = int(len(line)/2)
    for item in line[:pivot_ind]:
        if item in line[pivot_ind:]:
            item_ascii = ord(item)
            priority_sum += item_ascii - 96 if item_ascii > 96 else item_ascii - 38
            break

print(priority_sum)

input_file.close()