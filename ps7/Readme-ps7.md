# PS4b: StringSound

## Contact
Name: Emily Sheehan
Section:1
Time to Complete: 3


## Description
This program reads a Kronos log file and determines whether or not the system in the log has been booted successfully or not based upon the log. If the system was booted, the file contains a time stamp which is reported. Once the entire log file is interpreted, the time stamp is recorded again and then saved into a report that describes the each boot.

### Features
I basically pulled the time calculations from the .cpp file provided with the project guide. I used a while loop, also suggested in teh stdin_boost.cpp file, to loop through line by line of the log file. I then checked to see whether the line currently read in matched the starting or ending time, or neither. Depending on this boolean, I printed to the report file. 

### Approach
I tried to keep it simple and follow the tutorials provided. I think its fairly straight forward but I basically just used a series of if statements and matched the line that was read in as either indicating that the program was starting up or ending. 

### Regex
I used two which indicate the starting time (eb) and time of completion (ed).
    regex eb("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})"
            " ([0-9]{2}):([0-9]{2}):([0-9]{2})"
                + std::string("(.*log.c.166.*) server started"));
    regex ed("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})"
             " ([0-9]{2}):([0-9]{2}):([0-9]{2})"
                + std::string("(.*oejs.AbstractConnector:"
                "Started SelectChannelConnector@0.0.0.0:9080.*)"));
### Issues
I did have some issues with regex and had to use a stack overflow for help
### Extra Credit
I added the summary header but its at the bottom.
## Acknowledgements
https://stackoverflow.com/questions/37732/what-is-the-regex-pattern-for-datetime-2008-09-01-123545?answertab=trending#tab-top
https://stackoverflow.com/questions/47017969/boost-regex-undefined-references-when-linking
https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
https://stackoverflow.com/questions/33266944/attempt-to-access-an-unitialized-boostmatch-result-class
