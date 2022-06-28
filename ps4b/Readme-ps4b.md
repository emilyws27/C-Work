# PS4b: StringSound

## Contact
Name: Emily Sheehan
Section: 1
Time to Complete: 6 hours


## Description
This project comples project ps4a, adding the full functionality of the keytar. It simulates the instrument through the pressing of keys on the keyboard that correspond to different notes. It uses the Karplus-Strong algorithm to create the guitar plucking sounds. 

### Features
I used a lot of the base code from the SSLite.cpp to create my KSGuitarSim. Instead of coming up with 37 edge cases, I instead just used the key binding codes and checked to see which was pressed by matching it to the value. 

### Testing
I used runtime_errors and the BOOST_CHECK_EQUAL functions within my test.cpp file. In my KSGuitarSim.cpp, I threw a few runtime errors and also implemented a try-catch.

### Lambda
I did not incorporate a lambda

### Issues
none 

### Extra Credit
I did not do any of the extra credit

## Acknowledgements
Dr. Daly
https://cplusplus.com/reference/cmath/ceil/
https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
https://stackoverflow.com/questions/709146/how-do-i-clear-the-stdqueue-efficiently