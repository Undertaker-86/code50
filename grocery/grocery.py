grocery = {}

while True:
    try:
        item = input("").upper()
        if item not in grocery:
            grocery[item] = 1
        else:
            grocery[item] += 1
    except EOFError:

        sorted_dict = dict(sorted(list(grocery.items())))

        for i in sorted_dict:
            print(f"{sorted_dict[i]} {i}")
        break