# PS0: Hello SFML

## Contact
Name: Emily Sheehan
Section: 1
Time to Complete: 4 hours

## Description
This project produces "random" bits by implementing a fibonacci linear feedback shift register. A LFSR works by shifting the bits of the input to the left by one and then replacing the empty bit by the bit at tap positions. 

### Features
I created my FibLFSR using a bool vector representing each bit. For my step function, I got the left most bit (@ pos 0 in the vector) and x-ored it with the tap bits (@ pos 2,3,5). I then shifted each "bit" except for the leftmost in the vector (true or false) by one to the left, set the first bit equal to the left most bit, and returned the new leftbit. For my generate function, I set an int equal to 0 to begin with and then iterated k times, each time multiplying the int by 2 and adding it to the int that step() returned. In my << operator, I first created two checks to ensure that the initial input was a 16 bit sequence containing only 1s and 0s. If so, I then printed the output.

### Issues
I think everything works.

### Tests
The first two tests supplied by Prof. Daly check that the step() and generate() functions have the correct logic and produce the inteded output. The first test that I implemented ensures that the intial sequence that is supplied is indeed a fibonacci sequence of 16 bits. The second makes sure that the sequence contains only 1s and 0s.

## Acknowledgements
Prof Daly
Izzy (Discord?)
https://techoverflow.net/2021/04/11/how-to-fix-gcc-lots-of-undefined-reference-to-std-functions/
https://www.boost.org/doc/libs/1_53_0/libs/test/doc/html/tutorials/new-year-resolution.html
https://www.boost.org/doc/libs/1_53_0/libs/test/doc/html/tutorials/new-year-resolution.html
