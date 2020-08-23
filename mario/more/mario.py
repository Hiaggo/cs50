while True:
    height = input("Height: ")
    if height.isdigit():
        height = int(height)
    else:
        continue
    if height >= 1 and height <= 8:
        break

for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i + "  " + "#" * i)