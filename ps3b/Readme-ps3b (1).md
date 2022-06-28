# PS3b: N-Body Simulation

## Contact
Name: Emily Sheehan
Section: 1
Time to Complete: 5 hours


## Description
This assignment continues off of ps3a, adding animation and physics to the universe simulation. This is done by having the user input two new arguments into the command line: the total time and the time quantum (delta t). Using these two values, the simulation then displays the orientation and movement of the universe up until that time, using increments of delta t.

### Features
I created an accelerate function inside of the CelestialBody class that handles all of the force, velocity, and acceleration calculations. This function is then called inside my step() function inside of Universe.hpp. It takes the time and a CelestialBody object as parameters, performs the calculations, and then updates the xvelocity and yvelocity of the celestial body. I also elected to update the elapsed time on the screen in my main function. I did this by creatring a text object and drawing it to the window. 

### Memory
I used smart pointers in the same way that I did for ps3a. I was going to switch to shared pointers but I ran out of time and had to go to a work meeting. 

### Issues
I did not use smart pointers. I also could not figure out how to get the sound working, despite reading up on the documentation and copying word for word. 

### Extra Credit
I created my own universe -- planets_new.txt. It includes all of the planets in our solar system in reverse order. This was a weird illusion and it was funny seeing Pluto, so tiny, orbiting the sun in a tiny circle. The inner circle around the sun too was very crammed because of the larger planets around it.

## Acknowledgements
Prof. Daly
https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
https://en.sfml-dev.org/forums/index.php?topic=17170.0
https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
https://stackoverflow.com/questions/54623124/c-printing-shared-ptr-use-count-in-tree