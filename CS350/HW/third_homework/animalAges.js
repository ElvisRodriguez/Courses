'use strict';

const isDog = (animal) => animal.type === 'dog';

const isCat = (animal) => animal.type === 'cat';

const dogYears = (animal) => animal.age * 7;

const catYears = (animal) => animal.age * 10;

const sum = (sum, animal) => sum + animal;

function main() {
  let data = [
    {name: 'Butters',  age: 3,  type: 'dog'},
    {name: 'Lizzy',    age: 6,  type: 'dog'},
    {name: 'Joey',     age: 3,  type: 'dog'},
    {name: 'Rex',      age: 4,  type: 'dog'},
    {name: 'Air Bud',  age: 9,  type: 'dog'},
    {name: 'Clifford', age: 5,  type: 'dog'},
    {name: 'Red',      age: 1,  type: 'cat'},
    {name: 'Tesla',    age: 3,  type: 'cat'},
    {name: 'Edison',   age: 5,  type: 'cat'},
    {name: 'Smitty',   age: 7,  type: 'cat'},
    {name: 'Bella',    age: 10, type: 'cat'},
    {name: 'Meowth',   age: 6,  type: 'cat'},
  ];

  const totalDogAges = data.filter(isDog).map(dogYears).reduce(sum);
  const totalCatAges = data.filter(isCat).map(catYears).reduce(sum);
  console.log(totalDogAges);
  console.log(totalCatAges);
}

main();
