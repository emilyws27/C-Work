# PS4b: StringSound

## Contact
Name: Emily Sheehan
Section: 1
Time to Complete: 8


## Description
This project obtains a body of text, analyzes it over a fixed numbner of characters and a specific letter, calculates the probablity of certain letters in the text, and then generates nonsense text based off of the model its built. 
### Features
Along with the required class functions, I added four member variables to my header file: an int "num" to represent the order in the Markov model, a map to hold my kgrams, a string to represent the alphabet/letters used, and a string to represent the words in the input. I defined my coinstructor by looping through the text parameter, identifying the letters used and pushing them back to a list, and then looping thru that text again and situationally pushing back text to append to my kgrams.

### Testing
I wrote many tests to ensure the functionality of all of my functions. I used, BOOST_CHECK_EQUAL, BOOST_REQUIRE_THROW, and BOOST_REQUIRE_NO_THROW. I compared the values of function calls against the expected for _CHECK_EQUAL, and then compared exceptions and errors for the other two functions. 
### Lambda
My lambda function, located within kRand(), gets the length of the kgram parameter. It is located on lines 97-101 of RandWriter.cpp

### Issues
I found this to be a really frustrating project because I had one tiny error in my constructor logic that took me hours to debug. I was not incrementing properly for my kgram map which was very frustrating because the majority of the rest of my project was correct. 

### Extra Credit
I did not do extra credit.

### Changes
For my initial grading, I was docked for:
    1. 0.5 Doesn't throw an exception in the constructor on bad input.
    2. Frequencies found may not always be correct.
    3. generate() can produce unrecognized kgrams.
    4. -0.5 No test for generate()

I solved issue #1 by throwing exceptions in my constructor for when k < 0 and for when the size of k was greater than the length of the text. For #2, I addressed this by changing the structure of the for loops in my constructor. Instead of looping through character by character and appending to a temporary string, I now just use substrings over a range. This solution also solved issue 3 because it allowed for looping back to the beginning of the string which my previous solution did not, thereby raising errors. For #4, I created test cases with some basic statistics. I created ranges for how many of each letter should appear in a 1000 character string that I generated and tested each character against the values that it should fall between.

## Acknowledgements
Prof. Daly
https://www.geeksforgeeks.org/lambda-expression-in-c/
https://stackoverflow.com/questions/56283829/how-to-use-lambda-returning-a-bool-as-parameter
https://stackoverflow.com/questions/49216037/alternative-to-stringnpos
https://www.cs.princeton.edu/courses/archive/fall18/cos126/assignments/markov/ (helped explain the assignment)
https://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length
