#!/usr/bin/python3
import sys


def printSolution(table):
    solution = []
    for i in range(len(table)):
        for j in range(len(table)):
            if table[i][j] == 1:
                solution.append([i, j])
    print(solution)


def isSafe(table, row, coor, n):
    for i in range(coor):
        if table[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1),
                    range(coor, -1, -1)):
        if table[i][j] == 1:
            return False
    for i, j in zip(range(row, n, 1),
                    range(coor, -1, -1)):
        if table[i][j] == 1:
            return False

    return True


def solveNQUtil(table, coor, n):
    if coor == n:
        printSolution(table)
        return True
    cout = False
    for i in range(n):
        if isSafe(table, i, coor, n):
            table[i][coor] = 1
            cout = solveNQUtil(table, coor + 1, n) or cout
            table[i][coor] = 0
    return cout


if __name__ == "__main__":
    if not len(sys.argv) == 2:
        print("Usage: nqueens N")
        sys.exit(1)

    if not (sys.argv[1]).isdigit():
        print("N must be a number")
        sys.exit(1)

    n = int(sys.argv[1])

    table = [[0 for i in range(n)] for j in range(n)]
    solveNQUtil(table, 0, n)
