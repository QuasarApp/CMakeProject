//#
//# Copyright (C) 2020-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include <QtTest>
#include "exampletest.h"

/**
 * @brief The tstMain class - this is main test class
 */
class tstMain : public QObject
{
    Q_OBJECT

private:
    QList<Test*> _tests;


public:
    tstMain();

    ~tstMain();

private slots:
    void initTestCase();
    void unitTests();

};

/**
 * @brief tstMain::tstMain
 * init all availabel units for testsing
 */
tstMain::tstMain() {

    // init xample unit test
    _tests.push_back(new ExampleTest());

}

tstMain::~tstMain() {

}

/**
 * @brief tstMain::initTestCase - this method contains initialization of the data tests.
 */
void tstMain::initTestCase() {
}

/**
 * @brief tstMain::unitTests create application for testing
 */
void tstMain::unitTests() {
    int argc =0;
    char * argv[] = {nullptr};

    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("testRENAME_ME");
    QCoreApplication::setOrganizationName("QuasarApp");

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    QDir(path).removeRecursively();

    QTimer::singleShot(0, this, [&app, this]() {

        for (auto test : qAsConst(_tests) ) {
            test->test();
            delete test;
        }

        app.exit(0);
    });

    app.exec();
}

QTEST_APPLESS_MAIN(tstMain)

#include "tstMain.moc"
