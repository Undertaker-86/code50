operation = input("Expression: ").split()

match operation[1]:
    case "+":
        print(f"{(int(operation[0]) + int(operation[2])):.1f}")
    case "-":
        print(f"{int(operation[0]) - int(operation[2]):.1f}")
    case "*":
            print(f"{int(operation[0]) * int(operation[2]):.1f}")
    case "/":
            print(f"{int(operation[0]) / int(operation[2]):.1f}")