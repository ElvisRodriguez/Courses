import random


FILENAME = 'bad_beginning.txt'


def get_words(filename):
    file = open(filename, 'r')
    text = file.read()
    stop_letters = ['.', ',', ';', ':', "'s", '"', '!', '?', '(', ')', '“', '”']
    text = text.lower()
    words = ''.join([
        letter for letter in list(text) if letter not in stop_letters
    ]).split()
    return words


def compute_bigrams(filename):
    input_list = get_words(filename)
    bigram_list = {}
    for i in range(len(input_list) - 1):
        word = input_list[i]
        if word in bigram_list:
            bigram_list[word] = bigram_list[word] + [input_list[i+1]]
        else:
            bigram_list[word] = [input_list[i+1]]
    return bigram_list


if __name__ == '__main__':
    print(get_words(FILENAME))
    print(compute_bigrams(FILENAME))
