import sys

if len(sys.argv) != 2:
    sys.exit(1)

if sys.argv[1][-3:].startswith(".py") == False:
    sys.exit(2)

try:
    filename = open(sys.argv[1])

except FileNotFoundError:
    sys.exit(3)

line_count = 0
for row in filename:
    if row.lstrip().startswith("#") or row.strip() == "":
        pass
    else:
        line_count += 1

print(line_count)