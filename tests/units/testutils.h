#ifndef TESTUTILS_H
#define TESTUTILS_H

#include "functional"
#include <QMetaObject>

class TestUtils
{
public:
    TestUtils();
    virtual ~TestUtils();
    bool wait(const std::function<bool()> &forWait, int msec) const;


    bool funcPrivateConnect(const std::function<bool ()> &requestFunc,
                            const std::function<bool ()> &checkFunc,
                            const std::function<QMetaObject::Connection ()> &connectFunction) const;

    bool funcPrivateConnect(const std::function<bool ()> &requestFunc,
                            const std::function<bool ()> &checkFunc) const;

};

#endif // TESTUTILS_H
