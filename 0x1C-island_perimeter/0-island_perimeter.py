#!/usr/bin/python3
"""[summary]
"""


def add_border(grid):
    """[summary]

    Args:
        grid ([type]): [description]
    """
    last_idx = len(grid[0]) + 1
    for row in grid:
        row.insert(0, 0)
        row.insert(last_idx, 0)


def transpose_grid(grid):
    """[summary]

    Args:
        grid ([type]): [description]

    Returns:
        [type]: [description]
    """
    return [
        [row[i] for row in grid] for i in range(len(grid[0]))
    ]


def count_blocks(grid):
    """[summary]

    Args:
        grid ([type]): [description]

    Returns:
        [type]: [description]
    """
    count = 0
    for row in grid:
        for i in range(len(row)):
            if row[i] == 1 and row[i-1] == 0:
                count += 1
            if row[i] == 0 and row[i-1] == 1:
                count += 1
    return count


def island_perimeter(grid):
    """[summary]

    Args:
        grid ([type]): [description]

    Returns:
        [type]: [description]
    """
    add_border(grid)
    perimeter = count_blocks(grid)
    grid_t = transpose_grid(grid)
    add_border(grid_t)
    perimeter += count_blocks(grid_t)
    return perimeter
