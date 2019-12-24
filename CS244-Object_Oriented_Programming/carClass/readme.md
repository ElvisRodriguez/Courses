***Members: Elvis Rodriguez, Nusrath Ahmed***
***Date:03/08/18***

**Description**

*This class defines a car with the attributes:*

- speed (a double describing the car's current speed (in MPH)).
- index (use to point at an index in the directions string).
- directions (a string containing the characters N, E, S, W).
- direction (the car's current directions (either N, E, S, or W)).

*As well as these methods:*

- Car(): The constructor that assigns speed and index with 0 and direction with
         N (north) as default.

- Car(double, char): An overloaded constructor that allows the input of the
                     speed and direction.

- getSpeed(): Returns the current speed of the car object.

- getDirection(): Returns the current direction of the car object.

- changeDirection(char): changes the direction of the car object to the char
                         argument given. However if the argument is:
                         - 'L', it 'turns' the car left, which is to say that
                            the car's direction becomes the current index - 1
                            of the directions string (or the last index if
                            subtracting 1 would result in an out-of-bounds
                            error).
                         - 'R', it 'turns' the car right, which is to say that
                            the car's direction becomes the current index + 1
                            of the directions string (or the first index if
                            adding 1 would result in an out-of-bounds error).
                          - 'U', it causes the car object to 'perform' a U-turn,
                            which is to say that the car's direction becomes
                            the current index + 2 (or the current index - 2 if
                             adding 2 would result in an out-of-bounds error).

- changeSpeed(double): changes the speed to the given argument.

- isGoingForward(): returns true if the speed is greater than 0, false otherwise.

*We designed this class with just the basic properties of a car in real life.
With the car accurately changing direction when it 'turns' left/right or is
making a 'u-turn'*
