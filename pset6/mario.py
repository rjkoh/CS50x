from cs50 import get_int

while True:
    # prompt for input
    height = get_int("Height: ")
    # reject if smaller than 1 or greater than 8
    if height < 1 or height > 8:
        height = get_int("Height: ")
    # accept if in range
    if height >= 1 and height <= 8:
        break

# go row by row
for row in range(height):
    # print spaces
    print((height-row-1) * " ", end="")
    # print #
    print((row+1) * "#")