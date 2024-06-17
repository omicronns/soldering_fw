#include "unity.h"
#include "util/timer.hpp"
#include "input.hpp"


void test_timer(void)
{
    Timer<1> uut{{100}};
    TEST_ASSERT_FALSE(uut.trig(0));
    uut.update(10);
    TEST_ASSERT_FALSE(uut.trig(0));
    uut.update(90);
    TEST_ASSERT_FALSE(uut.trig(0));
    uut.update(100);
    TEST_ASSERT_FALSE(uut.trig(0));
    uut.update(101);
    TEST_ASSERT_TRUE(uut.trig(0));
}

void test_input_single(void)
{
    using Input1 = InputMgr<1>;
    Input1 uut{{Input1::Type::Single}, 100};
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(10, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(100, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(110, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(111, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Single, uut.poll(0));
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_timer);
    return UNITY_END();
}
