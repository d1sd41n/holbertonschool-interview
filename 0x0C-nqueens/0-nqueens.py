#!/usr/bin/python3
"""[summary]

    Returns:
        [type]: [description]
    """
import sys


def check_input(inp):
    """[summary]

    Args:
        inp ([type]): [description]

    Returns:
        [type]: [description]
    """
    if len(inp) != 2:
        print("Usage: nqueens N")
        exit(1)

    N = 0
    try:
        N = int(inp[1])
    except ValueError:
        print("N must be a number")
        exit(1)

    if N < 4:
        print("N must be at least 4")
        exit(1)

    return N


def check__atacking(Queen1, Queen2):
    """[summary]

    Args:
        Queen1 ([type]): [description]
        Queen2 ([type]): [description]

    Returns:
        [type]: [description]
    """
    x1, y1 = Queen1
    x2, y2 = Queen2

    if x1 == x2 or y1 == y2 or abs(x1 - x2) == abs(y1 - y2):
        return True

    return False


def rotate_board(positions):
    """[summary]

    Args:
        positions ([type]): [description]

    Returns:
        [type]: [description]
    """
    N = len(positions)
    rotated = [[0, 0] for i in range(N)]

    for i in range(N):
        rotated[i][0] = positions[i][1]
        rotated[i][1] = - positions[i][0] + (N - 1)

    rotated = sorted(rotated, key=lambda x: x[0])

    return rotated


def get_positions(N, variant):
    """[summary]

    Args:
        N ([type]): [description]
        variant ([type]): [description]

    Returns:
        [type]: [description]
    """
    positions = [[k, 0] for k in range(N)]
    positions[0][1] = variant

    i = 0
    while i < N:
        j = 0
        while j < i:
            if positions[i][1] > N - 1:
                positions[i][1] = 0
                positions[i - 1][1] += 1
                i -= 2
                break
            if check__atacking(positions[i], positions[j]):
                positions[i][1] += 1
                j = 0
            else:
                j += 1
        i += 1

    return positions


N = check_input(sys.argv)
e = 0
all_pos = []
while e < N:
    posotion = get_positions(N, e)
    y = posotion[0][1]
    e = y + 1
    valid = all([Queen[0] < N and Queen[1] < N for Queen in posotion])
    if valid:
        posotion = sorted(posotion, key=lambda x: x[0])
        all_pos.append(posotion)
for posotion in all_pos:
    current_pos = posotion
    for i in range(3):
        current_pos = rotate_board(current_pos)
        different = True
        for j in range(len(all_pos)):
            if all_pos[j] == current_pos:
                different = False
        if different is True:
            all_pos.append(current_pos)
for posotion in all_pos:
    print(posotion)
