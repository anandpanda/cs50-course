while True:
    try:
        h = int(input("Height: "))
        if (h >= 1) and (h <= 8):
            break
    except:
        print("", end="")

for j in range(h):

    for spaces in range(h-j-1):
        print(" ", end="")

    for i in range(j+1):
        print("#", end="")

    print()
