import sys
import requests

def main():
    if len(sys.argv) != 2:
        sys.exit("Invalid command line argument", 1)
    try:
        exchange = float(sys.argv[1])
    except ValueError:
        print("CLI is not a float")
        sys.exit(1)

    try:
        response = requests.get(f"https://api.coindesk.com/v1/bpi/currentprice.json")
        result = response.json()

    except requests.RequestException:
        print("This is not a test")
        sys.exit(1)

    print(f'${(exchange * result["bpi"]["USD"]["rate_float"]):,.4f}')

main()