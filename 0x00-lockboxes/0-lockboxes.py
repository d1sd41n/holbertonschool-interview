#!/usr/bin/python3
"""
here some docs
"""


def canUnlockAll(boxes):
    """
    here some docs
    """
    if len(boxes) == 0:
        return True
    else:

        l1 = set([box for box in range(1, len(boxes))])
        l2 = [i for i in boxes[0]]

        while len(l2) > 0:
            l2_item = l2.pop()

            if l2_item in l1:
                l1.remove(l2_item)
                l2.extend(boxes[l2_item])

            if not len(l1):
                return True

        return False
