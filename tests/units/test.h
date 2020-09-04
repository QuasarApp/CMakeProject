#ifndef TEST_H
#define TEST_H

class Test
{
public:
    Test() = default;
    virtual ~Test() = default;
    virtual void test() = 0;
};

#endif // TEST_H
