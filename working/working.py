import re
import sys


def main():
    print(convert(input("Hours: ")))

def convert(s):

    if time := re.search(r"^([0-9]{1,2})(?::)?([0-9]{1,2})? ([A|P]M) to ([0-9]{1,2})(?::)?([0-9]{1,2})? ([A|P]M)$", s):
        testminute1 = time.group(2)
        testminute2 = time.group(5)

        if testminute1 == None:
            testminute1 = "00"
        if  testminute2 == None:
            testminute2 = "00"

        hour1, minute1 = int(time.group(1)), int(testminute1)
        hour2, minute2 = int(time.group(4)), int(testminute2)

        if valid(hour1, minute1) and valid(hour2, minute2):
            if time.group(3) == "PM" and hour1 != 12:
                hour1 += 12
            elif time.group(3) == "PM" and hour1 == 12:
                pass
            elif time.group(3) == "AM" and hour1 == 12:
                hour1 = 0

            if time.group(6) == "PM" and hour2 != 12:
                hour2 += 12
            elif time.group(6) == "PM" and hour2 == 12:
                pass
            elif time.group(6) == "AM" and hour2 == 12:
                hour2 = 0

            return f"{hour1:02}:{minute1:02} to {hour2:02}:{minute2:02}"

        else:
            raise ValueError
    else:
        raise ValueError

def valid(hour, minute):
    if hour > 12 or hour < 0:
        return False
    if minute >= 60 or minute < 0:
        return False
    return True


if __name__ == "__main__":
    main()