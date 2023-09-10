import random


def main():
    level = get_level()
    score = 0

    for _ in range(10):

        first_integer = generate_integer(level)
        second_integer = generate_integer(level)
        correct_answer = first_integer + second_integer

        for life in range(3):
            try:
                answer = int(input(f"{first_integer} + {second_integer} = "))

                if answer == correct_answer:
                    score += 1
                    break

                elif life == 2:
                    print(f"{first_integer} + {second_integer} =", correct_answer)

                else:
                    print("EEE")

            except ValueError:
                print("EEE")

    print("Score:", score)

def get_level():
    while True:
        try:
            level = int(input("Level: "))
            if not(0 < level < 4) :
                raise ValueError

            return level

        except ValueError:
            pass



def generate_integer(level):
    if level == 1:
        return random.randint(0, 9)
    else:
        return random.randint(10 ** (level - 1), 10 ** level - 1)


if __name__ == "__main__":
    main()