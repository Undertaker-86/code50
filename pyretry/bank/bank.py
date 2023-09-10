greetings = input("please don't say hello: ").lower().strip()

if greetings.startswith("hello"):
    print("$0")
elif greetings[0] == "h":
    print("$20")
else:
    print("$100")