
while True:
    try:
        x, y = input("What is the fraction: ").split("/")
        percentage = int(x) / int(y)
        if percentage < 0 or percentage > 1:
            raise ValueError("Value exceed threshold")
        break
    except (ValueError, ZeroDivisionError):
        pass

percentage *= 100
if percentage <= 1:
    print("E")
elif percentage >= 99:
    print("F")
else:
    print(f"{percentage:.0f}%")