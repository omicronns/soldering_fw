#include "unity.h"
#include "util/timer.hpp"
#include "util/input.hpp"


void test_timer(void)
{
    Timer<1> uut{{100}};
    TEST_ASSERT_FALSE(uut.trig(0));
    uut.update(10);
    TEST_ASSERT_FALSE(uut.trig(0));
    uut.update(90);
    TEST_ASSERT_FALSE(uut.trig(0));
    uut.update(100);
    TEST_ASSERT_TRUE(uut.trig(0));
}

void test_input_single_single(void)
{
    using Input1 = InputMgr<1>;
    Input1 uut{{Input1::Type::Single}, 100};
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(0, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(100, {1});
    TEST_ASSERT_EQUAL(Input1::Event::Single, uut.poll(0));
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
}

void test_input_double_single(void)
{
    using Input1 = InputMgr<1>;
    Input1 uut{{Input1::Type::Double}, 100};
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(0, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(100, {1});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(200, {1});
    TEST_ASSERT_EQUAL(Input1::Event::Single, uut.poll(0));
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
}

void test_input_double_single_longer(void)
{
    using Input1 = InputMgr<1>;
    Input1 uut{{Input1::Type::Double}, 100};
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(0, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(100, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(101, {1});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(200, {1});
    TEST_ASSERT_EQUAL(Input1::Event::Single, uut.poll(0));
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
}

void test_input_double_long(void)
{
    using Input1 = InputMgr<1>;
    Input1 uut{{Input1::Type::Double}, 100};
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(0, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(100, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
    uut.process(200, {0});
    TEST_ASSERT_EQUAL(Input1::Event::Long, uut.poll(0));
    TEST_ASSERT_EQUAL(Input1::Event::Idle, uut.poll(0));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_timer);
    RUN_TEST(test_input_single_single);
    RUN_TEST(test_input_double_single);
    RUN_TEST(test_input_double_single_longer);
    RUN_TEST(test_input_double_long);
    return UNITY_END();
}
