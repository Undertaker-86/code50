camelCase = input("Input camel case: ").strip()

for c in camelCase:
    if (c.isupper()):
        print("_" + c.lower(), end = "")
    else:
        print(c, end = "")

print()