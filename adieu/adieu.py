import inflect

p = inflect.engine()

name_list = []


while True:
    try:
        name = input("Enter username: ")
        name_list.append(name)
    except EOFError:
        break

mylist = p.join(name_list)
print("Adieu, adieu, to", mylist)