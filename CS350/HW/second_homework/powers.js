'use strict';
const computePowers = (limit, base) => {
  for (let x = 1, i = 0; i <= limit; i += 1) {
      console.log(`${base}^${i} = ${x}`);
      x *= base;
  }
}


const main = () => {
  if (process.argv.length < 4) {
    console.error('Exactly 2 arguments are needed (exponent limit and base)');
    process.exit();
  }
  const limit = Number(process.argv[2]);
  const base = Number(process.argv[3]);
  computePowers(limit, base);
}

main();
