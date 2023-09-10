def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):

    if s[0:2].isalpha() == False:
        return False

    if  len(s) > 6 or len(s) < 2:
        return False

    if s.isalnum() == False:
        return False

    nomoreletter = False
    for c in s:


        if c.isdigit() and nomoreletter == False:

            if int(c) == 0:
                return False

            nomoreletter = True

        if nomoreletter and c.isalpha():
            return False

    return True

main()