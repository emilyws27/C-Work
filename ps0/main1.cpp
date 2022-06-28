#include "FibLFSR.hpp"
#include "test.cpp"
#include <iostream>
#include <string>
#include <vector>
//#include <bits/stdc++.h> 

using namespace std;

int main(){
    FibLFSR flfsr("1011011000110110");
	int num = flfsr.step();
	std::cout << example2 << " " << num << endl;
    return 0;
}