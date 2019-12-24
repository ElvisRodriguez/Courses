/*
//Name: Elvis Rodriguez
//Date: 04/05/18
//Directive: Astronomers  and physicists also use OOP. Design a class for
             objects in our solar system. Use the Internet to gather
             information to design this class. Since this is design only,
             capture as much as possible.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class SolarSystem {
  private:
    double mass;
    double density;
    double volume;
    long int age;
    double orbitRadius;
    string name; /*
                   name of object, if name is in knownObjects, other attributes
                   will have their attributes set to match the properties of the
                   "real life" version of the object
                 */
    string* knownObjects; /*
                            stores the name of all known objects currently
                            residing in the solar system; including, but not
                            limited to: planets, natural satellites, man-made
                            satellites, the Sun, named asteroids, name comets
                            Array will be dynamically allocated as the number
                            of known objects is not constant
                          */
    double* knownOrbits; /*
                           stores the known orbits of all known objects in
                           knownObjects array, with the index of each orbit
                           matching the index of the object in knownObjects
                           with that orbit in "real life"
                         */
    stringstream* compositions; /*
                                 stores the known compositions of all known objects in
                                 knownObjects array, with the index of each
                                 composition matching the indices of knownOrbits and
                                 knownObjects with that composition. The actual strings
                                 of this array are stringstream objects so as to not
                                 only better format the information held, but allow
                                 the user to write in more data without affecting the
                                 program
                               */
    bool isInKnownObjects() const; /*
                                     compares the name attribute of the object
                                     to the strings in knownObjects and returns
                                     true if the name matches a name. Comparison
                                     does not fail if the name attribute does not
                                     match the casing of the name in knownObjects
                                     as the string will be formatted when the
                                     object's name attribute is created/inputted
                                   */
  public:
    SolarSystem(string, double, double, double, int);
      /*
        Creates the arrays: knownObjects, knownOrbits, and composition.
        Sets attributes to arguments given if arguments are provided, otherwise
        object name is set to "Earth" with attributes equal to the properties
        of the planet Earth. If only some, but not all arguments are provided,
        the unprovided attributes will be set to "Planet X" and/or 0 depending
        on what is/is not provided
      */
    void setMass(double); //sets mass to input if input > 0
    void setDensity(double); //sets density to input if input > 0
    void setVolume(double); //sets volume to input if input > 0
    void setAge(long int); //sets age to input if input > 0
    void setOrbitRadius(double); //sets OrbitRadius to input if input > findRadius()
    void setName(string);
      /*
        sets name to input after formatting string. If name
        is in knownObjects, other attributes will be set to
        the appropriate properties
      */
    void addComposition(string);
      /*
        adds string to composition array if isInKnownObjects() returns false; if
        member function is called more than once, the same string first inputted
        is concatenated with the new string. If isInKnownObjects() is true,
        input is ignored
      */
    double getMass() const;
    double getDensity() const;
    double getVolume() const;
    long int getAge() const;
    double getOrbitRadius() const;
    string getName() const;
    string getComposition() const;
    double findRadius() const; //calculates radius of object using mass/volume attributes
    bool isPlanet() const; //returns true is name attribute is one of the eight planets
    bool isSatellite() const; //returns true if name attribute is not the Sun/a planet
    bool isTheSun() const; //return true if name attribute is "The Sun"
    bool isNEO() const; //returns true if name attribute is a "Near-Earth Object"
    string stats() const; //returns all the data stored in every attribute
    double gravitationalPull() const;
      /*
        calculates gravitational pull of object using mass/density
      */
    bool hasLife() const; //returns true if name attribute is "Earth"
    ~SolarSystem();
      /*
        deallocates the data stored in knownObjects, knownOrbits, and compositions
      */
};
