# Exercise 2


def product(*args):
    _product = 1
    for value in args:
        _product *= value
    return _product


if __name__ == '__main__':
    print(product(1, 2, 3) == 6)
    print(product(3, 4) == 12)
    print(product(6) == 6)
    print(product(1, 2, 3, 5, 10) == 300)
    print(product(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 3628800)
