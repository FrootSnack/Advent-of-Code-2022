input_file = open("input.txt")

overlapping_pairs = 0

for line in input_file:
    line = line.split(',')
    
    assignment_0 = line[0]
    assignment_0_l = int(assignment_0.split('-')[0])
    assignment_0_r = int(assignment_0.split('-')[1])

    assignment_1 = line[1]
    assignment_1_l = int(assignment_1.split('-')[0])
    assignment_1_r = int(assignment_1.split('-')[1])

    if (assignment_0_r >= assignment_1_l and assignment_0_l <= assignment_1_r)\
          or (assignment_1_r >= assignment_0_l and assignment_1_l <= assignment_0_r):
        overlapping_pairs += 1

print(overlapping_pairs)

input_file.close()