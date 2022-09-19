from cs50 import get_float

while True:
    # prompt for input
    change = get_float("Change owed: ")
    # reject if negative
    if change <= 0:
        change = get_float("Change owed: ")
    # accept if positive
    if change > 0:
        break
    
cents = round(change * 100)
coins = 0


# using quarters
while cents >= 25:
    cents -= 25
    coins += 1
    
# using dimes
while cents >= 10:
    cents -= 10
    coins += 1
    
# using pennies
while cents >= 5:
    cents -= 5
    coins += 1

# using nickels      
while cents >= 1:
    cents -= 1
    coins += 1
    
# tell user number of coins
print(f"{coins}")