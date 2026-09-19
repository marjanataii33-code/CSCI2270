#include "stepcounter.h"

#include <gtest/gtest.h>

#include <iostream>

using namespace std;



TEST(CounterTest, CounterHello) {

    StepCounter my_counter;

}
TEST(CounterTest,CounterStartsAtZero){
    StepCounter my_count;

    int result= my_count.get();

    EXPECT_EQ(result,0);

}
