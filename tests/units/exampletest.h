#ifndef EXAMPLE_TEST_H
#define EXAMPLE_TEST_H
#include "test.h"
#include "testutils.h"

#include <QtTest>

class ExampleTest: public Test, protected TestUtils
{
public:
    ExampleTest();
    ~ExampleTest();

    void test();

};

#endif // EXAMPLE_TEST_H
