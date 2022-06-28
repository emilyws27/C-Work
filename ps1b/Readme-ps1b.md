# PS0: Hello SFML

## Contact
Name: Emily Sheehan
Section: 1
Time to Complete: 4 Hours


## Description
This project implements the Fibonacci LFSR created in project 1a and uses it to encrypt an image provided by the user and displays this image using the SFML library. It implements a two digit password instead of the traditional 16 digit seed.

### Features
The program accepts four arguments; the name of the program (PhotoMagic), the input file, the output, and the initial 2 character "password". It converts this password to binary, creates a FibLFSR object, and then cycles through it xors the rgb values of each pixel in the image with the number from calling generate. It then displays the transformed photo on the screen.

### Issues
I think everything works. 

### Extra Credit
I implemented a two character password in lieu of the 16 digit LFSR seed. I could have made it so that you can do a password of any length, but this would have required restructuring my FibLFSR class which I did not have time to do. 

## Acknowledgements
Prof Daly
https://stackoverflow.com/questions/55490732/checking-for-specific-command-line-arguments-in-c
https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Image.php
https://stackoverflow.com/questions/10184178/fastest-way-to-convert-string-to-binary