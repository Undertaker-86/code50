import sys, random
from pyfiglet import Figlet

if len(sys.argv) != 3 or len(sys.argv) != 1:
    print("Invalid usage")
    sys.exit(0)

if len(sys.argv) == 3 :
    font = argv(2)

    word = input("Enter your word: ")
    f = Figlet_format(word, font)
    print(f)

else :
    f = random.choice(Figlet.getFonts())
    Figlet.setFont(font = f)
    print(f"{Figlet.renderText(user)}")