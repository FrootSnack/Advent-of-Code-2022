input_file = open("input.txt")

PICK_VALS = {
    'X': 1,
    'Y': 2,
    'Z': 3
    }

PLAYER_WINS = {
    'A': 'Y',
    'B': 'Z',
    'C': 'X'
    }

PLAYER_DRAWS = {
    'A': 'X',
    'B': 'Y',
    'C': 'Z'
    }

PLAYER_LOSES = {
    'A': 'Z',
    'B': 'X',
    'C': 'Y'
    }

score = 0
for line in input_file:
    line = line.split()
    opponent_pick = line[0]
    match_result = line[1]

    if match_result == 'X':
        score += PICK_VALS[PLAYER_LOSES[opponent_pick]]
    elif match_result == 'Y':
        score += 3 + PICK_VALS[PLAYER_DRAWS[opponent_pick]]
    else:
        score += 6 + PICK_VALS[PLAYER_WINS[opponent_pick]]

print(score)

input_file.close()