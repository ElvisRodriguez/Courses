# Exercise 3


def madlibs(words):
    story = []
    story.append('There once was an {adjective} barnacle.'.format(
        adjective=words['adjective'])
    )
    story.append('He was so {adjective} that everyone {verb}. The end.'.format(
        adjective=words['adjective'], verb=words['verb'])
    )
    return '\n'.join(story)


if __name__ == '__main__':
    words = {}
    words['adjective'] = str(input('Enter an adjective: '))
    words['verb'] = str(input('Enter a verb: '))
    print(madlibs(words))
