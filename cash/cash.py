while True:

    cash = input("Change owned: ")

    try:
        cash = float(cash)
    except:
        continue
    if cash > 0.0:
        break

coinNumber = 0
cents = round(cash * 100)
while cents > 0:
    if cents >= 25:
        coinNumber += 1
        cents -= 25
        #print(f"1: {cents}")

    elif cents >= 10:
        coinNumber += 1
        cents -= 10
        #print(f"2: {cents}")

    elif cents >= 5:
        coinNumber += 1
        cents -= 5
        #print(f"3: {cents}")

    elif cents >= 1:
        coinNumber += 1
        cents -= 1
        #print(f"4: {cents}")

print(coinNumber)