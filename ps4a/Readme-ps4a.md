# PS4a: CircularBuffer

## Contact
Name: Emily Sheehan
Section: 1
Time to Complete: 1.5 hours


## Description
This project implements a template class called CircularBuffer that will later on serve as the structure for building a guitar in ps4b. It has two member variables, a queue and an int. The CircularBuffer queue has a max capacity, the int, that dictates how much it can hold. 

### Features
I built the class using a queue as my main data function. The functions required for implementation, size(), isEmpty(), isFull(), enqueue(), dequeue(), and peek() made a queue an easy choice over a vector because C++ has built in functions for many of these functions already. The project also throws exceptions if the queue tries to push back additional T objects over capacity, or if it tries to pop while the queue is empty. It throws invalid_argument and runtime_error exceptions.

### Testing
I used the invalid_argument and runtime_error excpetions, per the instructions. I tested for all of these, and the functions that do not throw errors, in my test.cpp file by creating a queue and adding/removing items under certain size constraints. 

### Complexity
I believe that they all have a O(1) time complexity because all of the calls are constant and there are no for-loops involved. 
### Issues
I didn't really have any issues. I only made silly mistakes when I was trying to copy/paste the different functions in my .hpp file and messed up the return types in the function definitions. 

### Extra Credit
I did not.

## Acknowledgements
https://cplusplus.com/doc/oldtutorial/templates/
https://cplusplus.com/reference/queue/queue/front/
https://cplusplus.com/reference/queue/queue/queue/