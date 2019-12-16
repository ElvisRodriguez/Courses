import random

import bigrams


def two_grams(paragraph_number, paragraph_size):
    bigram_list = bigrams.compute_bigrams(bigrams.FILENAME)
    keys = list(bigram_list.keys())
    paragraphs = []
    for _ in range(paragraph_number):
        paragraph = []
        current_key = random.choice(keys)
        paragraph.append(current_key)
        while len(paragraph) < paragraph_size:
            next_word = random.choice(bigram_list[current_key])
            paragraph.append(next_word)
            if next_word in bigram_list:
                current_key = next_word
            else:
                current_key = random.choice(keys)
        paragraphs.append(paragraph)
    return '\n\n'.join([' '.join(paragraph) for paragraph in paragraphs])


if __name__ == '__main__':
    print(two_grams(4, 100))
