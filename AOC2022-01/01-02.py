input_file = open("input.txt")

# priority queue implementation from https://www.geeksforgeeks.org/priority-queue-in-python/

TOP_N = 3

queue = []
current_sum = 0
for line in input_file:
    if line == '\n':
        queue.append(current_sum)
        current_sum = 0
    else:
        current_sum += int(line)

top_N_sum = 0
for n in range(TOP_N):
    max_sum_ind = 0
    for sum_ind in range(len(queue)):
        max_sum_ind = sum_ind if queue[sum_ind] > queue[max_sum_ind] else max_sum_ind
    max_sum = queue[max_sum_ind]
    del queue[max_sum_ind]
    top_N_sum += max_sum

print(top_N_sum)

input_file.close()