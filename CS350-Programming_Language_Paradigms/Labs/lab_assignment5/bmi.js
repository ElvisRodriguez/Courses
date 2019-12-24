'use strict';

const poundsToKilograms = pounds => pounds * 0.453592;

const inchesToMeters = inches => inches * 0.0254;

const addBMI = person => {
  const kilograms = poundsToKilograms(person.pounds_weight);
  const meters = inchesToMeters(person.inches_height);
  const bmi = kilograms / (meters * meters);
  person.bmi = bmi;
  return person;
}

const isOverweight = person => person.bmi >= 25 && person.bmi < 30;

const isObese = person => person.bmi >= 30;

function main() {
  let people = [
    {name: "Amy", pounds_weight: 152, inches_height: 63},
    {name: "Joe", pounds_weight: 120, inches_height: 64},
    {name: "Tom", pounds_weight: 210, inches_height: 78},
    {name: "Jim", pounds_weight: 180, inches_height: 68},
    {name: "Jen", pounds_weight: 120, inches_height: 62},
    {name: "Ann", pounds_weight: 252, inches_height: 63},
    {name: "Ben", pounds_weight: 240, inches_height: 72},
  ];

  const overweight_people = people.map(addBMI).filter(isOverweight);
  const obese_people = people.map(addBMI).filter(isObese);
  console.log(overweight_people);
  console.log(obese_people);
}

main();
