#!/usr/bin/python3
"""[summary]
"""


def validUTF8(data):
    """[summary]

    Args:
        data ([type]): [description]

    Returns:
        [type]: [description]
    """
    total_b = 0

    for i in data:
        byte = format(i, '#010b')[-8:]
        if total_b == 0:

            if byte[0] == '1':
                total_b = len(byte.split('0')[0])

            if total_b > 4 or total_b == 1:
                return False

            elif total_b == 0:
                continue

        else:
            if not byte.startswith('10'):
                return False
        total_b = total_b - 1

    if total_b != 0:
        return False

    return True
