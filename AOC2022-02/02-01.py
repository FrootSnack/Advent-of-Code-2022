input_file = open("input.txt")

PICK_VALS = {
    'X': 1,
    'Y': 2,
    'Z': 3
    }

PLAYER_WINS = {
    'X': 'C',
    'Y': 'A',
    'Z': 'B'
    }

score = 0
for line in input_file:
    line = line.split()
    opponent_pick = line[0]
    player_pick = line[1]

    score += PICK_VALS[player_pick]

    if ord(opponent_pick) - ord('A') == ord(player_pick) - ord('X'):
        score += 3
    elif PLAYER_WINS[player_pick] == opponent_pick:
        score += 6

print(score)

input_file.close()