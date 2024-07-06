from cs50 import get_float

# Get positive input
while True:
    try:
        change = get_float("Change: ")
        if change > 0:
            break
    except ValueError:
        pass

# Convert dollars to cents
cents = int(round(change * 100))

# Calculate the number of coins needed
coins = 0
for coin in [25, 10, 5, 1]:
    coins += cents // coin
    cents %= coin

print(coins)
