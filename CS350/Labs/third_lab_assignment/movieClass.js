'use strict';

class Movie {
  constructor(name, year) {
    this.name = name;
    this.releaseYear = year;
    this.ratings = [0, 0, 0, 0, 0];
    this.ratingsCount = 0;
  }

  averageRating() {
    let totalRatings = 0;
    let ratingValue = 0;
    for (let i = 0; i < this.ratings.length; i++) {
      ratingValue = i + 1;
      totalRatings += (this.ratings[i] * ratingValue);
    }
    return Math.floor(totalRatings / this.ratingsCount);
  }

  addRating(rating) {
    const index = rating - 1;
    this.ratings[index] += 1;
    this.ratingsCount += 1;
  }

}

function printMovie (movie) {
  console.log(`${movie.name}, ${movie.releaseYear}\n`);
  console.log(`Average Rating: ${movie.averageRating()}\n`);
  console.log(`Rated by: ${movie.ratingsCount} users\n`);
}

function main() {
  const lord1 = new Movie("Lord of the Rings: The Fellowship of the Ring",2001);
  const lord2 = new Movie("Lord of the Rings: The Return of the King", 2003);
  // Add 5 ratings of 5 stars to lord1 object
  for (let i = 1; i <= 5; i++) {
    lord1.addRating(5);
  }
  // Add 15 ratings of 4 stars to lord1 object
  for (let i = 1; i <= 15; i++) {
    lord1.addRating(4);
  }
  // Add 5 ratings of 3 stars to lord1 object
  for (let i = 1; i <= 5; i++) {
    lord1.addRating(3);
  }
  // Add 2 ratings of 2 stars to lord1 object
  lord1.addRating(2);
  lord1.addRating(2);

  // Add 3 ratings of 4stars to lord2 object
  for (let i = 1; i <= 3; i++) {
    lord2.addRating(4);
  }
  //Add 1 ratings of 2stars to lord2 object
  lord2.addRating(2);
  //Add 1 ratings of 1stars to lord2 object
  lord2.addRating(1);

  // Print Movies and average ratings
  printMovie(lord1);
  printMovie(lord2);
}

main();
