'use strict';

function product(a=1, b=1, c=1, d=1, e=1, f=1, g=1, h=1, i=1, j=1) {
  return a*b*c*d*e*f*g*h*i*j;
}

function main() {
  console.log(product(1,2,3));
  console.log(product(3,4));
  console.log(product(6));
  console.log(product(1,2,3,5,10));
  console.log(product(1,2,3,4,5,6,7,8,9,10));
}

main();
