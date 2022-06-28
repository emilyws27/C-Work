// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 5/12/2022

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

using boost::test_tools::output_test_stream;

output_test_stream output;

BOOST_AUTO_TEST_CASE(testStepInstr1) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testStepInstr2) {
  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE_EQUAL(l2.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(test3){

   FibLFSR l3("10110");
   BOOST_REQUIRE_EQUAL(l3.step(), -1);
   output << l3;
   BOOST_REQUIRE(output.is_equal("Not 16 Bits"));
}

BOOST_AUTO_TEST_CASE(test4){
  FibLFSR l3("1011311Q00110110");
  BOOST_REQUIRE_EQUAL(l3.step(), -1);
  output << l3;
  BOOST_REQUIRE(output.is_equal("crazy input - contains a non-0 or 1 value"));
  
}