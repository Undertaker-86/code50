def main():
    word = input("Input your word here: ")
    print(convert(word))

def convert(word):
    return word.replace(":)", '🙂').replace(":(", '🙁')

main()