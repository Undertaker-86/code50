vowel = ["a", 'e', 'i', 'o', 'u']

twttr = input("What's your sentence: ")

for c in twttr:

    if c.lower() in vowel:
        print("", end="")

    else:
        print(c, end = "")

print()