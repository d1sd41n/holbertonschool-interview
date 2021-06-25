#!/usr/bin/python3
"""[summary]
"""


def makeChange(coins, total):
    """[summary]

    Args:
        coins ([type]): [description]
        total ([type]): [description]

    Returns:
        [type]: [description]
    """
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    index = 0
    aux = 0
    tota_sum = 0
    while (tota_sum < total
           and index < len(coins)):
        while coins[index] <= total \
            - tota_sum:
            tota_sum += coins[index]
            aux += 1
            if tota_sum == total:
                return aux
        index += 1
    return -1
