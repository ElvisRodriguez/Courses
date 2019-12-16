'use strict';
const SALES_TAX = 6.00;

function isPrime(item) {
    return item.type === 'prime';
}

function primeItems(cart) {
  return cart.filter(isPrime);
}

const reject = (arr, callback) => {
    const notCallback = (item) => {
        return !(callback(item));
    }
    return arr.filter(notCallback);
}

function notPrimeItems(cart) {
  return reject(cart, isPrime);
}

function applyCoupon(cart) {
    return cart.map((item) => {
        if (item.category === 'tech') {
            item.price -= (item.price / 5);
        }
        return item;
    });
}

function regularShippingCost(cart) {
  return cart.map((item) => {
    if (!isPrime(item)) {
      item.price += 2;
    }
    return item;
  });
}

function salesTax(cart) {
  return cart.map((item) => {
    item.price += (item.price / 100 * SALES_TAX);
    return item;
  });
}

function totalCost(cart){
  const finalCart = salesTax(regularShippingCost(cart));
  return finalCart.reduce((accumulator, item) => {
      accumulator += item.price;
      return accumulator;
  }, 0);
}

function main() {
  const cart = [
    {"name":"Biscuits", "type":"regular", "category":"food", "price": 10.00},
    {"name":"Monitor", "type":"prime", "category":"tech", "price": 119.99},
    {"name":"Mouse", "type":"prime", "category":"tech", "price": 25.50},
    {"name":"dress", "type":"regular", "category":"clothes", "price": 49.90},
    {"name":"keyboard", "type":"regular", "category":"tech", "price": 19.99},
    {"name":"fatsnax", "type":"regular", "category":"food", "price": 18.49},
    {"name":"camo pants", "type":"regular", "category":"clothes", "price": 35.50},
    {"name":"hardrive", "type":"prime", "category":"tech", "price": 42.50},
    {"name":"jacket", "type":"prime", "category":"clothes", "price": 51.45},
    {"name":"zevia soda", "type":"prime", "category":"food", "price": 9.99},
  ]
  console.log(totalCost(cart));
}

main();
