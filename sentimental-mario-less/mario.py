# TODO
import sys
from cs50 import get_int


while True:

    try:
        block = int(input("Height of tower: "))
        if block > 0 and block < 9:
            break

    except ValueError:
        print("Enter an integer")

# while True:
#     block = get_int("Enter integer between 1 and 8: ")
#     if (block > 0 or block < 9):
#         break

for i in range(block):
    print(" " * (block - 1 - i), end = "#" * (i + 1))
    print()