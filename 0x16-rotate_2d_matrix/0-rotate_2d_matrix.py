#!/usr/bin/python3
"""[summary]
"""


def rotate_2d_matrix(matrix):
    """[summary]

    Args:
        matrix ([type]): [description]
    """
    matrix.reverse()
    m = [i.copy()
         for i in matrix]
    for i, row in enumerate(m):
        for j, col in enumerate(row):
            matrix[j][i] = m[i][j]
