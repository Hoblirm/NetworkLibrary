/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_bit_pack_test_init = false;
#include "/home/hobby/dev/NetworkLibrary/test/inc/bit_pack_test.h"

static bit_pack_test suite_bit_pack_test;

static CxxTest::List Tests_bit_pack_test = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_bit_pack_test( "test/inc/bit_pack_test.h", 5, "bit_pack_test", suite_bit_pack_test, Tests_bit_pack_test );

static class TestDescription_suite_bit_pack_test_test_pack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 18, "test_pack" ) {}
 void runTest() { suite_bit_pack_test.test_pack(); }
} testDescription_suite_bit_pack_test_test_pack;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
