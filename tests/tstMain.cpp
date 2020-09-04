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

    QTimer::singleShot(0, [&app, this]() {

        for (auto test : _tests ) {
            test->test();
            delete test;
        }

        app.exit(0);
    });

    app.exec();
}

QTEST_APPLESS_MAIN(tstMain)

#include "tstMain.moc"
