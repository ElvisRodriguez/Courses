'use strict';

const NAME_LENGTH = 'ElvisRodriguez'.length;


function getNameLengthGeneratorObject() {
  return {
    counter: 0,
    next: function() {
      if (this.counter === 0) {
        this.counter = NAME_LENGTH;
        return this.counter;
      }
      this.counter *= 2;
      return this.counter;
    }
  }
}


function getNameLengthGeneratorClosure() {
  let counter = 0;
  return function() {
    if (counter === 0) {
      counter = NAME_LENGTH;
      return counter;
    }
    counter *= 2;
    return counter;
  };
}


function main() {
  console.log('Object Generator:');
  const nameLengthGeneratorObject = getNameLengthGeneratorObject();
  for (let i = 0; i < 10; i++) {
    console.log(nameLengthGeneratorObject.next());
  }

  console.log('Closure Generator:');
  const next = getNameLengthGeneratorClosure();
  for (let i = 0; i < 10; i++) {
    console.log(next());
  }
}

main();
