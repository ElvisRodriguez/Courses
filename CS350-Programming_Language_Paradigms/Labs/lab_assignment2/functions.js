'use strict';

function each(array, func) {
  for (let i = 0; i < array.length; i++) {
    array[i] = func(array[i]);
  }
  return array;
}

function sequence(n) {
  return Array(n).fill().map((_, index) => index + 1);
}

const square = (n) => n * n;

const cube = (n) => n * n * n;

const perfectSquares = (n) => each(sequence(n), square);

const perfectCubes = (n) => each(sequence(n), cube);

const pow = (p) => (n) => Math.pow(n, p);

const perfectPowers = (n, p) => each(sequence(n), pow(p));

function main() {

  // Calling perfectPowers with 2 as the second argument should return the
  //  same result as calling perfectSquares with 5 as the argument
  console.log(perfectSquares(5));
  console.log(perfectPowers(5, 2));

  // The same behavior is observed for comparing perfectPowers with perfectCubes
  console.log(perfectCubes(5));
  console.log(perfectPowers(5, 3));

  console.log(perfectPowers(5, 4));
}

main();
