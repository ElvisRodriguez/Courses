'use strict';

const convertToYen = (usd) => {
  return usd * 109.92;
}

const convertToEuro = (usd) => {
  return usd * 0.88;
}

const main = () => {
  if (process.argv.length < 3) {
    console.error('Exactly one argument is required');
    process.exit();
  }
  const usd = parseInt(process.argv[2]);
  const yens = convertToYen(usd);
  const euros = convertToEuro(usd);
  console.log(`${usd} US Dollars in Japanese Yens: ${yens}`);
  console.log(`${usd} US Dollars in Euros: ${euros}`);
}

main();
