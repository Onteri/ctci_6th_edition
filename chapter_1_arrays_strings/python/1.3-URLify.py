# O(n) solution


def urlify(string):
    return string.strip().replace(' ', '%20')


print(urlify("Mr John Smith    "))
# Mr%20John%20Smith
print(urlify("Say hello to my little friend          "))
# Say%20hello%20to%20my%20little%20friend
