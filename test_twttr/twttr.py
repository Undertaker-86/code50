def main():
    twttr = input("What's your sentence: ")
    print(shorten(twttr))
    print()

def shorten(word):
    vowel = ["a", 'e', 'i', 'o', 'u']

    shortened = []

    for c in word:

        if c.lower() not in vowel:
            shortened.append(c)

    return str("".join(shortened))

if __name__ == "__main__":
    main()