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
    if not coins:
        return -1
    coins.sort(reverse=True)
    if total < coins[-1]:
        return -1
    dx_num = 0
    num_coins = 0
    while (total > 0 and
           dx_num < len(coins)):
        coin_val = coins[dx_num]
        factor = total // coin_val
        if factor != 0:
            num_coins += factor
            total -= factor * coin_val
        dx_num += 1
    if total == 0:
        return num_coins
    return -1
