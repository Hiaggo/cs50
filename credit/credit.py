card = int(input("Number: "))

def cardChecker (card):

    n = card // 1000000000000
    print(n)
    if n == 4:
        print("VISA")
        return
    elif n / 100 == 51 or n / 100 == 52 or n / 100 == 53 or n / 100 == 54 or n / 100 == 55:
        print("MASTERCARD")
        return
    elif n / 10 == 34 or n /10 == 37:
        print("AMEX")
        return
    elif n / 1000 == 4:
        print("VISA")
        return
    else:
        print("INVALID")
        return

_sum = 0
_rest = 0
cardCpy = card

for i in range(16):

    _sum += cardCpy % 10
    cardCpy = cardCpy // 10
    rest = (cardCpy % 10) * 2

    if rest >= 10:
        print(_sum)
        _sum += _rest % 10
        _sum += _rest // 10
        print(_sum)

    else:
        _sum += _rest

    cardCpy = cardCpy // 10

if _sum % 10 == 0:
    cardChecker(card)

else:
    print("INVALID")