# Exercise 4

import random

LOTTERY_SIZE = 5
LOWER_BOUND = 1
UPPER_BOUND = 44


def gather_user_numbers():
    user_numbers = []
    print('**** Welcome to PICK{} lottery game ****'.format(LOTTERY_SIZE))
    print('Please pick {} numbers between {} and {}:'.format(
        LOTTERY_SIZE, LOWER_BOUND, UPPER_BOUND)
    )
    while len(user_numbers) < LOTTERY_SIZE:
        user_number = int(input(''))
        if user_number < LOWER_BOUND or user_number > UPPER_BOUND:
            print('Your number was too low or high, please pick another number')
        elif user_number in user_numbers:
            print('You have already chosen this number, please choose another')
        else:
            user_numbers.append(user_number)
    return user_numbers


def generate_winning_numbers():
    winning_numbers = set()
    while len(winning_numbers) < LOTTERY_SIZE:
        winning_numbers.add(random.randint(LOWER_BOUND, UPPER_BOUND))
    return list(winning_numbers)


def numbers_match(user_numbers, winning_numbers):
    total_numbers = set()
    total_numbers.update(winning_numbers)
    total_numbers.update(user_numbers)
    return len(total_numbers) == LOTTERY_SIZE


if __name__ == '__main__':
    user_numbers = gather_user_numbers()
    winning_numbers = generate_winning_numbers()
    print('The winning numbers are: {}'.format(
        ' '.join([str(number) for number in winning_numbers]))
    )
    if numbers_match(user_numbers, winning_numbers):
        print('CONGRATULATIONS! YOU WON THE LOTTERY!')
    else:
        print('Sorry, you do not win this time.')
