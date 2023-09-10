# TODO
from cs50 import get_float
while True:
        try:
                change = get_float("Change: ")
                if change >= 0:
                        break

        except ValueError:
               print("Enter a real number")

change = change * 100

coin = 0

while change > 0:

    if change >= 25:
        change -= 25
        coin += 1

    elif change >= 10:
            change -= 10
            coin += 1


    elif change >= 5:
            change -= 5
            coin += 1


    elif change >= 1:
            change -= 1
            coin += 1

print(f"Total count: {coin}")