# O(n) solution


def create_map(string):
    obj = {}
    for ch in string:
        if ch in obj:
            obj[ch] += 1
        else:
            obj[ch] = 1
    return obj


def check_permutation(str1, str2):
    if len(str1) != len(str2):
        return False
    str_map = create_map(str1)
    for ch in str2:
        if ch not in str_map:
            return False
        str_map[ch] -= 1
        if str_map[ch] < 0:
            return False
    return True


print(check_permutation('dog', 'god'))  # true
print(check_permutation('dog', 'God'))  # false
print(check_permutation('dog', 'good'))  # false
print(check_permutation('mmmmm', 'mmmmm'))  # true
print(check_permutation('mmmmm', 'mmmmn'))  # true
