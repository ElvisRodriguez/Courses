#include <iostream>
#include <string>

using namespace std;

#define SIZE 5

class Movie {
  private:
    string name;
    int releaseYear;
    int ratingsCount;
    int ratings [SIZE] = {0, 0, 0, 0, 0};
  public:
    Movie(string name, int year);
    double averageRating() const;
    void addRating(int rating);
    friend ostream &operator<<(ostream &output, const Movie &M) {
      //Overloaded operator, do NOT modify.
      cout << M.name << ", " << M.releaseYear << endl;
      cout << "Average Rating: " << M.averageRating() << endl;
      cout << "Rated by: " << M.ratingsCount << " users" << endl;
      return output;
    }
};

Movie::Movie(string name, int year) {
  this->name = name;
  releaseYear = year;
  ratingsCount = 0;
}

double Movie::averageRating() const {
  int totalRatings = 0;
  int rating_value = 0;
  for (int i = 0; i < SIZE; i++) {
    rating_value = i + 1;
    totalRatings += (ratings[i] * rating_value);
  }
  return totalRatings / ratingsCount;
}

void Movie::addRating(int rating) {
  int index = rating - 1;
  ratings[index] += 1;
  ratingsCount += 1;
}

int main() {
  //Create Movie objects
  Movie lord1("Lord of the Rings: The Fellowship of the Ring",2001);
  Movie lord2("Lord of the Rings: The Return of the King",2003);
  Movie socialNetwork("The Social Network", 2010);
  Movie scottPilgrim("Scott Pilgrim vs The World", 2010);
  Movie deadpool("Deadpool", 2016);
  //lord1 RATINGS
    //Add 5 ratings of 5stars to lord1 object
    for (int i=1; i<=5; i++)
    lord1.addRating(5);
    //Add 15 ratings of 4stars to lord1 object
    for (int i=1; i<=15; i++)
    lord1.addRating(4);
    //Add 5 ratings of 3stars to lord1 object
    for (int i=1; i<=5; i++)
    lord1.addRating(3);
    //Add 2 ratings of 2stars to lord1 object
    lord1.addRating(2);
    lord1.addRating(2);
  //lord2 RATINGS
    //Add 3 ratings of 4stars to lord2 object
    for (int i=1; i<=3; i++)
    lord2.addRating(4);
    //Add 1 ratings of 2stars to lord2 object
    lord2.addRating(2);
    //Add 1 ratings of 1stars to lord2 object
    lord2.addRating(1);
  //socialNetwork Ratings
    //Add 5 ratings of 5 stars to socialNetwork object
    for (int i = 1; i <= 5; i++) {
      socialNetwork.addRating(5);
    }
  //scottPilgrim Ratings
    //Add 4 ratings of 4 stars to scottPilgrim object
    for (int i = 1; i <= 4; i++) {
      scottPilgrim.addRating(4);
    }
    //Add 1 rating of 5 stars to scottPilgrim object
    scottPilgrim.addRating(5);
  //deadpool Ratings
    //Add 3 ratings of 4 stars to deadpool object
    for (int i = 1; i <= 3; i++) {
      deadpool.addRating(4);
    }
    //Add 2 ratings of 5 stars to deadpool object
    deadpool.addRating(5);
    deadpool.addRating(5);

  //PRINT MOVIES AND AVERAGE RATINGS
  cout << "FIRST MOVIE" << endl << lord1<< endl << endl;
  cout << "SECOND MOVIE" << endl << lord2 << endl << endl;
  cout << "THIRD MOVIE" << endl << socialNetwork << endl << endl;
  cout << "FOURTH MOVIE" << endl << scottPilgrim << endl << endl;
  cout << "FIFTH MOVIE" << endl << deadpool << endl << endl;

  return 0;
}
