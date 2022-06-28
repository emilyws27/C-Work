// Copyright 2022 Emily Sheehan
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <boost/regex.hpp>



#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using boost::regex;
using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::posix_time::time_from_string;
using boost::posix_time::ptime;
using boost::posix_time::time_duration;


int main(int argc, char *argv[]) {
    std::ifstream iF(argv[1], std::ifstream::in);
    std::string name = std::string(argv[1]) + ".rpt";
    std::string oFName(name);
    std::ofstream oF;
    boost::smatch m;
    std::string line;
    int bootStart = 0;
    int bootComplete = 0;
    ptime t1;

    if (argc != 2) {
        std::cout << "Wrong # of args" << std::endl;;
        return -1;
    }

    if (!iF.is_open()) {
        std::cout << "Can't open file." << std::endl;;
        return -1;
    }

    oF.open(oFName.c_str());

    regex eb("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})"
            " ([0-9]{2}):([0-9]{2}):([0-9]{2})"
                + std::string("(.*log.c.166.*)"));
    regex ed("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})"
             " ([0-9]{2}):([0-9]{2}):([0-9]{2})"
                + std::string("(.*oejs.AbstractConnector:"
                "Started SelectChannelConnector@0.0.0.0:9080.*)"));

    int lineNum = 1;
    bool startToBoot = false;

    while (getline(iF, line)) {
        if (regex_match(line, m, eb)) {
            if (startToBoot) {
                oF << "**** Incomplete boot **** \n" << std::endl;;
            }
            startToBoot = true;

            date d_(from_simple_string(m[0]));
            time_duration td1(atoi(m[4].str().c_str()),
                              atoi(m[5].str().c_str()),
                              atoi(m[6].str().c_str()));
            ptime temp(d_, td1);
            t1 = temp;

            std::string x1 = std::to_string(lineNum) + "(" + argv[1] + "):";
            std::string x2 = m[1] + "-" + m[2] + "-" + m[3] + " ";
            std::string x3 = m[4] + ":" + m[5] + ":" + m[6] + " ";
            oF << "=== Device boot ===" << std::endl;;
            oF << x1;
            oF << x2;
            oF << x3;
            oF << "Boot Start" << std::endl;;
            bootStart++;
        } else if (regex_match(line, m, ed)) {
            if (startToBoot) {
                startToBoot = false;

                date d_(from_simple_string(m[0]));
                time_duration td2(atoi(m[4].str().c_str()),
                                  atoi(m[5].str().c_str()),
                                  atoi(m[6].str().c_str()));
                ptime temp(d_, td2);
                time_duration td = temp - t1;

                std::string x1 = std::to_string(lineNum) + "(" + argv[1] + "):";
                std::string x2 = m[1] + "-" + m[2] + "-" + m[3] + " ";
                std::string x3 = m[4] + ":" + m[5] + ":" + m[6] + " ";

                oF << x1;
                oF << x2;
                oF << x3;
                oF << "Boot Completed\n";
                oF << "\tBoot Time: ";

                std::string time1 = std::to_string(td.total_milliseconds())
                + "ms \n\n";
                oF << time1;
                bootComplete++;
            } else {
                oF << "**** Unexpected boot ****\n\n";
            }
        }

        lineNum++;
    }

    oF << "Device Boot Report\n\n"
    << "InTouch log file: " << argv[1] << std::endl
    << "Lines Scanned: " << lineNum - 1 << std::endl << std::endl
    << "Device boot count: initiated: " << bootStart << ", completed: "
    << bootComplete << std::endl << std::endl;

    return 0;
}
