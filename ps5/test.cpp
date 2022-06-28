// Copyright 2022 Emily Sheehan

#include "RandWriter.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

using boost::test_tools::output_test_stream;

output_test_stream output;
BOOST_AUTO_TEST_CASE(order0) {
  RandWriter rw("gagggagaggcgagaaa", 0);
  BOOST_CHECK_EQUAL(rw.freq("", 'a'), 7);
  BOOST_CHECK_EQUAL(rw.freq("", 'g'), 9);
  BOOST_CHECK_EQUAL(rw.freq("", 'c'), 1);
  BOOST_CHECK_EQUAL(rw.freq("", 'z'), 0);

  BOOST_CHECK_EQUAL(rw.orderK(), 0);
  BOOST_CHECK_EQUAL(rw.freq("") , 17);
  BOOST_REQUIRE_THROW(rw.freq("x"), std::runtime_error);
}
BOOST_AUTO_TEST_CASE(gen) {
  RandWriter rw("gagggagaggcgagaaa", 2);
  std::string g = rw.generate("ga", 1000);
  BOOST_CHECK_EQUAL(g.size(), 1000);
  BOOST_CHECK_EQUAL(g.substr(0, 2), "ga");

  int num_as = count(g.begin(), g.end(), 'a');
  BOOST_REQUIRE_GE(num_as, 200);
  BOOST_REQUIRE_LE(num_as, 500);
  int num_gs = count(g.begin(), g.end(), 'g');
  BOOST_REQUIRE_GE(num_gs, 350);
  BOOST_REQUIRE_LE(num_gs, 750);
  int num_cs = count(g.begin(), g.end(), 'c');
  BOOST_REQUIRE_GE(num_cs, 0);
  BOOST_REQUIRE_LE(num_cs, 100);
}

BOOST_AUTO_TEST_CASE(order1) {
  RandWriter rw("gagggagaggcgagaaa", 1);

  BOOST_REQUIRE_THROW(rw.kRand("d"), std::runtime_error);
  BOOST_REQUIRE_THROW(rw.freq(""), std::runtime_error);
  BOOST_REQUIRE_THROW(rw.freq("fsdfs"), std::runtime_error);

  BOOST_REQUIRE_NO_THROW(rw.kRand("a"));
  BOOST_REQUIRE_NO_THROW(rw.kRand("c"));
  BOOST_REQUIRE_NO_THROW(RandWriter("gagggagaggcgagaaa", 1));

  BOOST_CHECK_EQUAL(rw.orderK(), 1);

  BOOST_CHECK_EQUAL(rw.freq("a"), 7);
  BOOST_CHECK_EQUAL(rw.freq("g"), 9);
  BOOST_CHECK_EQUAL(rw.freq("c"), 1);
  BOOST_CHECK_EQUAL(rw.freq("a", 'a'), 2);
  BOOST_CHECK_EQUAL(rw.freq("a", 'c'), 0);
  BOOST_CHECK_EQUAL(rw.freq("a", 'g'), 5);
  BOOST_CHECK_EQUAL(rw.freq("c", 'a'), 0);
  BOOST_CHECK_EQUAL(rw.freq("c", 'c'), 0);
  BOOST_CHECK_EQUAL(rw.freq("c", 'g'), 1);
  BOOST_CHECK_EQUAL(rw.freq("g", 'a'), 5);
  BOOST_CHECK_EQUAL(rw.freq("g", 'c'), 1);
  BOOST_CHECK_EQUAL(rw.freq("g", 'g'), 3);
}

BOOST_AUTO_TEST_CASE(order3) {
  RandWriter rw("gagggagaggcgagaaa", 3);

  BOOST_REQUIRE_THROW(rw.kRand("d"), std::runtime_error);
  BOOST_REQUIRE_THROW(rw.freq(""), std::runtime_error);
  BOOST_REQUIRE_THROW(rw.freq("fsdfs"), std::runtime_error);

  BOOST_REQUIRE_NO_THROW(rw.kRand("aaa"));
  BOOST_REQUIRE_NO_THROW(rw.kRand("ggc"));
  BOOST_REQUIRE_NO_THROW(RandWriter("gagggagaggcgagaaa", 3));

  BOOST_CHECK_EQUAL(rw.orderK(), 3);

  BOOST_CHECK_EQUAL(rw.freq("gag"), 4);
  BOOST_CHECK_EQUAL(rw.freq("ggg"), 1);
  BOOST_CHECK_EQUAL(rw.freq("aga"), 3);
  BOOST_CHECK_EQUAL(rw.freq("cga"), 1);
  BOOST_CHECK_EQUAL(rw.freq("gaa"), 1);
  BOOST_CHECK_EQUAL(rw.freq("agg"), 2);
}
