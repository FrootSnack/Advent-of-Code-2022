input_file = open("input.txt")

stacks = []
stacks.append('G F V H P S'.split())
stacks.append('G J F B V D Z M'.split())
stacks.append('G M L J N'.split())
stacks.append('N G Z V D W P'.split())
stacks.append('V R C B'.split())
stacks.append('V R S M P W L Z'.split())
stacks.append('T H P'.split())
stacks.append('Q R S N C H Z V'.split())
stacks.append('F L G P V Q J'.split())

for line in input_file:
    line = line.split()
    count = int(line[1])
    src_ind = int(line[3]) - 1
    dest_ind = int(line[5]) - 1

    for n in range(count):
        crate = stacks[src_ind].pop()
        stacks[dest_ind].append(crate)

top_crates = ""
for stack in stacks:
    top_crates += stack[-1]

print(top_crates)

input_file.close()