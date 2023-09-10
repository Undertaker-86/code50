coke_price = 50
coins = [5, 10, 25]
while coke_price > 0:


    coin = int(input("Enter coin price: ").strip())

    if coin in coins:
        coke_price -= coin

        if (coke_price <= 0):
            print(f"Change Owed: {-coke_price}")
        else:
            print(f"Amount Due: {coke_price}")
    else:
        print(f"Amount Due: {coke_price}")

