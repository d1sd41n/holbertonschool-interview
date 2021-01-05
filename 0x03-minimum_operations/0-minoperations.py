#!/usr/bin/python3
"""[summary]
"""


def minOperations(n):
    """[summary]

    Args:
        n ([type]): [description]

    Returns:
        [type]: [description]
    """
    if type(n) != int or n <= 1:
        return 0

    nuum_f = []
    i = 2
    while n > 1:
        if n % i == 0:
            n /= i
            nuum_f.append(i)
            continue

        i += 1
    return sum(nuum_f)
