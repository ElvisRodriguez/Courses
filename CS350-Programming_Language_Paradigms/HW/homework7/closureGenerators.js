'use strict';

function fibonacci() {
  const currentValues = [];
  let counter = 0;
  return function() {
    if (currentValues.length === 0) {
      currentValues.push(0);
      return 0;
    }
    if (currentValues.length === 1) {
      currentValues.push(1);
      return 1;
    }
    counter = currentValues[0] + currentValues[1];
    currentValues[0] = currentValues[1];
    currentValues[1] = counter;
    return counter;
  }
}

function factorial() {
  let nextNumber = 0;
  let counter = 1;
  return function() {
    nextNumber += 1;
    counter *= nextNumber;
    return counter;
  }
}

function powersOfTwo() {
  let counter = 0;
  return function() {
    if (counter === 0) {
      counter = 1;
      return counter;
    }
    counter *= 2;
    return counter;
  }
}

function oddNumbers() {
  let counter = 1;
  const baseCases = [0, 1];
  return function() {
    if (baseCases.length != 0) {
      const baseCase = baseCases.shift();
      return baseCase;
    }
    counter += 2;
    return counter;
  }
}

function evenNumbers() {
  let counter = -2;
  return function() {
    counter += 2;
    return counter;
  }
}

function testGenerator(generator, testCount) {
  console.log(`Testing ${generator.name} generator:`);
  const next = generator();
  for (let i = 0; i < testCount; i++) {
    console.log(next());
  }
}


function main() {
  testGenerator(fibonacci, 10);
  testGenerator(factorial, 10);
  testGenerator(powersOfTwo, 10);
  testGenerator(oddNumbers, 10);
  testGenerator(evenNumbers, 10);
}

main();
