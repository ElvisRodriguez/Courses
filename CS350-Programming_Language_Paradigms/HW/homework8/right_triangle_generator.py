# Exercise 1


def right_triangle_generator():
    max_triangle_size = int(input('Enter max triangle size: '))
    for c in range(1, max_triangle_size):
        for b in range(1, c):
            for a in range(1, b):
                if a * a + b * b == c * c:
                    print('{}, {}, {}'.format(a, b, c))


if __name__ == '__main__':
    right_triangle_generator()
