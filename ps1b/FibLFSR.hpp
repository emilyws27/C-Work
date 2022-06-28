#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FibLFSR {
    public:
        // Constructor to create LFSR with the given initial seed
        FibLFSR(string seed);
        // Simulate one step and return the new bit as 0 or 1
        int step();
        // Simulate k steps and return a k-bit integer
        vector<bool> get_fib_vector();
        int generate(int k);
        vector<bool> tap_vector;
        unsigned int seed_size;
        bool wrong_digit;
        ~FibLFSR();
    private:

// Any fields that you need
    };
std::ostream& operator<<(std::ostream&, const FibLFSR& flfsr);