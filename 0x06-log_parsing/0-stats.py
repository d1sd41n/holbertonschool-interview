#!/usr/bin/python3
"""[summary]
"""
import sys


ssize = 0
sc = {"200": 0, "301": 0, "400": 0, "401": 0,
      "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for i, j in enumerate(sys.stdin, 1):
        splited = j.split(" ")
        if len(splited) < 2:
            continue
        if splited[-2] in sc:
            sc[splited[-2]] += 1
        ssize += eval(splited[-1])
        if i % 10 == 0:
            print("File size: {}".format(ssize))
            for key, value in sorted(sc.items()):
                if value > 0:
                    print("{}: {}".format(key, value))
finally:
    print("File size: {}".format(ssize))
    for key, value in sorted(sc.items()):
        if value > 0:
            print("{}: {}".format(key, value))
