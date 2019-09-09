'use strict';

const encrypt = (string, n) => {
   let result = [];
   const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".split('');
   for (let i = 0; i < string.length; i ++) {
      // Check if a character is a letter, no need to shift if it isn't
      if (string[i].toLowerCase() == string[i].toUpperCase()) {
        result.push(string[i]);
      } else {
        const index = (alphabet.indexOf(string[i]) + n) % alphabet.length;
        result.push(alphabet[index]);
      }
    }
   return result.join('');
}


const main = () => {
  if (process.argv.length != 4) {
    console.error('Exactly two arguments are required');
    process.exit();
  }

  const word = process.argv[2];
  const shift = parseInt(process.argv[3], 10);
  console.log(encrypt(word.toUpperCase(), shift));
}


main();
