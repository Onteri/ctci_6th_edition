def is_power_of_two(n):
    """
    Determines if a number is a power of two
    """
    return n and not (n & (n - 1))


print(is_power_of_two(0))  # False
print(is_power_of_two(2))  # True
print(is_power_of_two(6))  # False
print(is_power_of_two(8))  # True
