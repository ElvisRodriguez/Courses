'use strict';
const generateRightTriangleSides = (n) => {
  for (let c = 1; c <= n; c++) {
    for (let b = 1; b < c; b++) {
      for (let a = 1; a < b; a++) {
        if (a * a + b * b === c * c) {
          console.log(`${a}, ${b}, ${c}`);
        }
      }
    }
  }
}


const main = () => {
  if (process.argv.length != 3) {
    console.error('Exactly one argument is required');
    process.exit();
  }

  const sideLimit = process.argv[2];
  generateRightTriangleSides(sideLimit);
}


main();
