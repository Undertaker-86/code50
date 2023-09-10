food = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

def main():
    bill = 0
    while True:
        try:
            bill += get_food("Item: ")
            print(f"Total: ${bill:.2f}")
        except EOFError:
            print()
            break

def get_food(prompt):
    while True:
        try:
            return food[input(prompt).title().strip()]
        except KeyError:
            pass

main()