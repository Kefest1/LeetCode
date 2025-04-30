def reverse_integer(x: int) -> int:
    isNegative = -1 if x < 0 else 1
    x *= isNegative

    reversed_x = 0

    while x != 0:
        digit = x % 10
        x //= 10
        reversed_x = reversed_x * 10 + digit

    return isNegative * reversed_x

print(reverse_integer(-123))

print(reverse_integer(45648687))

print(reverse_integer(-444111))
