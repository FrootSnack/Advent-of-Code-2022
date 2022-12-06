input_file = open("input.txt")
input_line = input_file.readlines()[0]

WINDOW_SIZE = 14

char_ind = 0
window = []

for char_ind, char in enumerate(input_line):
    if char in window:
        shift_start = window.index(char) + 1
        window = window[shift_start:]
    window.append(char)
    char_ind += 1
    if len(window) == WINDOW_SIZE:
        break

print(char_ind)

input_file.close()