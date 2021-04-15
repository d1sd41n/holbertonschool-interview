#!/usr/bin/python3
"""[summary]
"""

def rain(walls):
    """[summary]

    Args:
        walls ([type]): [description]

    Returns:
        [type]: [description]
    """
    if not len(walls):
        return 0
    trin_sum = 0
    aux_var = [0] * len(walls)
    aux_var[0] = walls[0]
    for x in range(1, len(walls)):
        aux_var[x] = max(aux_var[x - 1],
                         walls[x])
    right_side = [0] * len(walls)
    right_side[-1] = walls[-1]
    for i in range(len(walls) - 2, -1, -1):
        right_side[i] = max(right_side[i + 1],
                            walls[i])
    for i in range(len(walls)):
        trin_sum += min(aux_var[i],
                        right_side[i]) - walls[i]
    return trin_sum
