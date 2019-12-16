import random

import bigrams


def random_word_generator(paragraph_number, paragraph_size):
    words = bigrams.get_words(bigrams.FILENAME)
    paragraphs = [
        [random.choice(words) for _ in range(paragraph_size)] for _ in range(paragraph_number)
    ]
    return '\n\n'.join([' '.join(paragraph) for paragraph in paragraphs])


if __name__ == '__main__':
    print(random_word_generator(4, 100))
