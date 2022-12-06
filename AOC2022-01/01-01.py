input_file = open("input.txt")

highest_sum = -1
current_sum = 0
for line in input_file:
    if line == '\n':
        current_sum = 0
    else:
        current_sum += int(line)
        if current_sum > highest_sum:
            highest_sum = current_sum

print(highest_sum)

input_file.close()