'use strict';

const add2 = (n) => {
  return 2 + n;
}

const main = () => {
  const n = process.argv[2];
  // Command line args are strings by default.
  // We must convert the input to an integer.
  const result = add2(parseInt(n, 10));
  console.log(result);
}


main()
