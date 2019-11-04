def is_one_edit_replace(str1, str2):
    differences = 0
    for i, e in enumerate(str1):
        if str1[i] != str2[i]:
            differences += 1
    return differences <= 1


def is_one_edit_insert(str1, str2):
    if len(str1) > len(str2):
        long, short = str1, str2
    else:
        short, long = str1, str2
    i = j = 0
    found_difference = False
    while i < len(short):
        if (short[i] != long[j]):
            if found_difference:
                return False
            found_difference = True
            j += 1
        i += 1
        j += 1
    return True


def is_one_edit_away(str1, str2):
    len1 = len(str1)
    len2 = len(str2)
    if len1 == len2:
        return is_one_edit_replace(str1, str2)
    if abs(len1 - len2) == 1:
        return is_one_edit_insert(str1, str2)
    return False


print(is_one_edit_away('beal', 'bal'))  # True
print(is_one_edit_away('val', 'bal'))  # True
print(is_one_edit_away('val', 'bale'))  # False
print(is_one_edit_away('mail', 'mailman'))  # False
print(is_one_edit_away('abc', 'abcde'))  # False
print(is_one_edit_away('', 'a'))  # True
