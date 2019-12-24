POUNDS_TO_KILOGRAMS = 0.453592
INCHES_TO_METERS = 0.0254


def pounds_to_kg(pounds):
    return pounds * POUNDS_TO_KILOGRAMS


def inches_to_meters(inches):
    return inches * INCHES_TO_METERS


def add_bmi(person):
    pounds = person['pounds_weight']
    inches = person['inches_height']
    kilograms = pounds_to_kg(pounds)
    meters = inches_to_meters(inches)
    bmi = kilograms / (meters ** 2)
    person['bmi'] = bmi
    return person


def is_overweight(person):
    return 25 <= person['bmi'] < 30


if __name__ == '__main__':
    people = [
        {'name': 'Amy', 'pounds_weight': 152, 'inches_height': 63},
        {'name': 'Joe', 'pounds_weight': 120, 'inches_height': 64},
        {'name': 'Tom', 'pounds_weight': 210, 'inches_height': 78},
        {'name': 'Jim', 'pounds_weight': 180, 'inches_height': 68},
        {'name': 'Jen', 'pounds_weight': 120, 'inches_height': 62},
        {'name': 'Ann', 'pounds_weight': 252, 'inches_height': 63},
        {'name': 'Ben', 'pounds_weight': 240, 'inches_height': 72},
    ]
    obese_people = list(filter(is_overweight, map(add_bmi, people)))
    print(obese_people)
