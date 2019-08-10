***Bank Account Class***

**Description:**

This class uses the private members *accountNumber*,
*pin*, *balance*, and *isLoggedIn*

*isLoggedIn* is a member used by most of the class' methods
so that the user is not continuously prompted for a pin

There are two constructors:
- One with no arguments that prompts a user to setup their 'account.'
- Another with 2 arguments that creates an 'account.'

The *login()* method checks if the string argument matches
the *pin*

**Design Choices:**

I decided to set up this bank account class with the partial intention
that another program will be the user interface instead.
