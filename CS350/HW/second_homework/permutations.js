'use strict';
const generatePermutations = (a, n) => {
  if (n === 0) {
    console.log(a.join(''));
  } else {
    for (let i = 0; i < n; i++) {
      generatePermutations(a, n - 1);
      const j = n % 2 === 0 ? 0 : i;
      let temp = a[j];
      a[j] = a[n];
      a[n] = temp;
      //[a[j], a[n]] = [a[n], a[j]];
    }
    generatePermutations(a, n - 1);
  }
}


const main = () => {
  if (process.argv.length != 3) {
    console.error('Exactly one argument is required');
    process.exit();
  }

  const word = process.argv[2];
  const words = word.split(' ')
  generatePermutations(words, words.length - 1);
}


main();
