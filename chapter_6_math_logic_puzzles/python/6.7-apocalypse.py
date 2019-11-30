import random


def run_one_family():
    """
    Will generate boys until a girl is reached.
    Returns tuple of girls to boys.
    """
    boys = girls = 0
    while not girls:
        if random.randint(0, 1):
            girls += 1
        else:
            boys += 1
    genders = (girls, boys)
    return genders


def run_n_families(n):
    """
    Given a sample size, will generate the ratio of boys to girls
    """
    boys = girls = 0
    for i in range(n):
        genders = run_one_family()
        girls += genders[0]
        boys += genders[1]
    return girls / (boys + girls)


print(run_n_families(100000))  # ~0.5
