def main():

    currentTime = convert(input("Current time: "))

    if 7 <= currentTime <= 8:
        print("breakfast time")

    elif 12<= currentTime <= 13:
        print("lunch time")

    elif 18<= currentTime <= 19:
        print("dinner time")


def convert(time):

    splitTime = time.split(":")

    return float(splitTime[0]) + float(splitTime[1]) / 60


if __name__ == "__main__":
    main()