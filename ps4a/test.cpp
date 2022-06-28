// "Copyright 2022 Emily Sheehan"

#include <queue>

#include "CircularBuffer.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

using boost::test_tools::output_test_stream;

output_test_stream output;

BOOST_AUTO_TEST_CASE(test) {
    CircularBuffer<int> cb(3);
    BOOST_CHECK(cb.isEmpty());
    BOOST_REQUIRE_THROW(cb.peek(), std::runtime_error);
    BOOST_REQUIRE_THROW(cb.dequeue(), std::runtime_error);
    BOOST_REQUIRE_NO_THROW(cb.enqueue(123));
    cb.enqueue(2);
    cb.enqueue(3);
    BOOST_CHECK_EQUAL(cb.size(), 3);
    BOOST_CHECK(cb.isFull());
    BOOST_REQUIRE_THROW(cb.enqueue(4), std::runtime_error);
}

