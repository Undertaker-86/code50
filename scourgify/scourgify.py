import sys
import csv

if len(sys.argv) != 3:
    sys.exit(1)

if sys.argv[1][-4:] != ".csv" or sys.argv[2][-4:] != ".csv":
    sys.exit(2)

try:
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)

        with open(sys.argv[2], "w") as output:

            field_attribute = ["first", "last", "house"]
            writer = csv.DictWriter(output, fieldnames = field_attribute)

            writer.writeheader()

            for row in reader:
                lastName, firstName = row["name"].split(", ")
                house = row["house"]
                writer.writerow({"first": firstName, "last": lastName, "house" : house})

except FileNotFoundError:
    sys.exit(3)
