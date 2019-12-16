'use strict';

function isPrime(item) {
  return item.type === 'prime';
}

let isNotPrime = item => !isPrime(item);

let applyCoupon = (item) => {
  let itemCopy = JSON.parse(JSON.stringify(item));
  if (itemCopy.category === 'tech') {
    itemCopy.price -= (itemCopy.price / 5);
  }
  return itemCopy;
}

let applySalesTax = (item) => {
  let itemCopy = JSON.parse(JSON.stringify(item));
  const SALES_TAX = 6.00;
  itemCopy.price += (itemCopy.price / 100 * SALES_TAX);
  return itemCopy;
}

let applyShippingCost = (item) => {
  let itemCopy = JSON.parse(JSON.stringify(item));
  itemCopy.price += 5;
  return itemCopy;
}

function totalCost(cart) {
  return cart.reduce((accumulator, item) => {
    accumulator += item.price;
    return accumulator;
  }, 0);
}

function main() {
  var cart = [
    {"name":"Biscuits",   "type":"regular", "category":"food",    "price": 2.0},
    {"name":"Monitor",    "type":"prime",   "category":"tech",    "price": 120},
    {"name":"Mouse",      "type":"prime",   "category":"tech",    "price": 25},
    {"name":"dress",      "type":"regular", "category":"clothes", "price": 50},
    {"name":"XL Monitor", "type":"prime",   "category":"tech",    "price": 160},
    {"name":"Cookies",    "type":"regular", "category":"food",    "price": 16},
  ];


  const totalPrimeItemCost = totalCost(
    cart
    .filter(isPrime)
    .map(applyCoupon)
    .map(applySalesTax)
  );


  const totalNonPrimeItemCost = totalCost(
    cart
    .filter(isNotPrime)
    .map(applyCoupon)
    .map(applyShippingCost)
    .map(applySalesTax)
  );

  const totalItemCost = totalCost(
    cart
    .map(applyShippingCost)
    .map(applySalesTax)
  );

  console.log(totalPrimeItemCost, totalNonPrimeItemCost, totalItemCost);
}

main();
