#include "FibLFSR.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

FibLFSR::FibLFSR(string seed)
{
    //num_taps = 3;
    seed_size = seed.length();
    
    
    for(char& c : seed){
        if(c=='1'){
            tap_vector.push_back(true);
        }
        else if (c=='0'){
            tap_vector.push_back(false);
        }
        else{
            wrong_digit = true;
        }
    }
   
}

FibLFSR::~FibLFSR() {}

vector<bool> FibLFSR::get_fib_vector(){
    return tap_vector;
}


// shifts the seed one to the left by one bit
int FibLFSR::step()
{
    if(tap_vector.size() != 16){
        return -1;
    }
    else if(wrong_digit == true){
        return -1;
    }

    int bit1;
    int bit2;
    int bit3;

    int leftbit = tap_vector[0];

    bit1 = tap_vector[2];
    bit2 = tap_vector[3];
    bit3 = tap_vector[5];

    leftbit = ((bit1 ^ leftbit) ^ bit2) ^ bit3;

    //shifts bits except for last
    for (unsigned i = 0; i < (15); i++){
        tap_vector[i] = tap_vector[i+1];
    }

    tap_vector[15] = leftbit;

   // cout << *this << endl;
    return leftbit;

}

int FibLFSR::generate(int k)
{
    int x = 0;
    for (int i = 0; i < k; i++){
        x = x * 2;
        x = x + step();
    }
    return x;
   
}

ostream &operator<<(ostream &output, FibLFSR const &flfsr)
{
    if(flfsr.wrong_digit == true){
        output << "crazy input - contains a non-0 or 1 value";
        return output;
    }
    else if(flfsr.seed_size != 16){
        output << "Not 16 Bits";
        return output;
    }

    for (unsigned i = 0; i < flfsr.tap_vector.size(); i++)

        if (flfsr.tap_vector[i] == true)
        {
            output << 1;
            
        }

        else if (flfsr.tap_vector[i] ==false)
        {
            output << 0;
        }
    return output;
}