import csv
import sys
from tabulate import tabulate

if len(sys.argv) != 2:
    sys.exit(1)

try:
    if sys.argv[1][-4:].startswith(".csv") == False:
            raise FileNotFoundError
    with open(sys.argv[1]) as filename:


        reader = csv.DictReader(filename)

        print(tabulate(reader, headers = "keys", tablefmt = "grid"))

except FileNotFoundError:
    print("can't open file")
    sys.exit(2)


