input_file = open("input.txt")
input_lines = input_file.readlines()

GROUP_SIZE = 3

priority_sum = 0
for i in range(0, len(input_lines), GROUP_SIZE):
    shared_items = [c for c in input_lines[i] if c != '\n']
    for n in range(1, GROUP_SIZE):
        shared_items = [s for s in shared_items if s in input_lines[i+n]]
    item_ascii = ord(shared_items[0])
    priority_sum += item_ascii - 96 if item_ascii > 96 else item_ascii - 38

print(priority_sum)

input_file.close()