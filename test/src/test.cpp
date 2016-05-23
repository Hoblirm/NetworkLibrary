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

static class TestDescription_suite_bit_pack_test_test_pack_impl : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_impl() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 18, "test_pack_impl" ) {}
 void runTest() { suite_bit_pack_test.test_pack_impl(); }
} testDescription_suite_bit_pack_test_test_pack_impl;

static class TestDescription_suite_bit_pack_test_test_pack_uint64 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_uint64() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 282, "test_pack_uint64" ) {}
 void runTest() { suite_bit_pack_test.test_pack_uint64(); }
} testDescription_suite_bit_pack_test_test_pack_uint64;

static class TestDescription_suite_bit_pack_test_test_pack_uint32 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_uint32() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 348, "test_pack_uint32" ) {}
 void runTest() { suite_bit_pack_test.test_pack_uint32(); }
} testDescription_suite_bit_pack_test_test_pack_uint32;

static class TestDescription_suite_bit_pack_test_test_pack_uint16 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_uint16() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 414, "test_pack_uint16" ) {}
 void runTest() { suite_bit_pack_test.test_pack_uint16(); }
} testDescription_suite_bit_pack_test_test_pack_uint16;

static class TestDescription_suite_bit_pack_test_test_pack_uint8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_uint8() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 480, "test_pack_uint8" ) {}
 void runTest() { suite_bit_pack_test.test_pack_uint8(); }
} testDescription_suite_bit_pack_test_test_pack_uint8;

static class TestDescription_suite_bit_pack_test_test_pack_int64 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_int64() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 546, "test_pack_int64" ) {}
 void runTest() { suite_bit_pack_test.test_pack_int64(); }
} testDescription_suite_bit_pack_test_test_pack_int64;

static class TestDescription_suite_bit_pack_test_test_pack_int32 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_int32() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 674, "test_pack_int32" ) {}
 void runTest() { suite_bit_pack_test.test_pack_int32(); }
} testDescription_suite_bit_pack_test_test_pack_int32;

static class TestDescription_suite_bit_pack_test_test_pack_int16 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_int16() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 802, "test_pack_int16" ) {}
 void runTest() { suite_bit_pack_test.test_pack_int16(); }
} testDescription_suite_bit_pack_test_test_pack_int16;

static class TestDescription_suite_bit_pack_test_test_pack_int8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_int8() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 930, "test_pack_int8" ) {}
 void runTest() { suite_bit_pack_test.test_pack_int8(); }
} testDescription_suite_bit_pack_test_test_pack_int8;

static class TestDescription_suite_bit_pack_test_test_pack_uchar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_uchar() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 1058, "test_pack_uchar" ) {}
 void runTest() { suite_bit_pack_test.test_pack_uchar(); }
} testDescription_suite_bit_pack_test_test_pack_uchar;

static class TestDescription_suite_bit_pack_test_test_pack_char : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_bit_pack_test_test_pack_char() : CxxTest::RealTestDescription( Tests_bit_pack_test, suiteDescription_bit_pack_test, 1126, "test_pack_char" ) {}
 void runTest() { suite_bit_pack_test.test_pack_char(); }
} testDescription_suite_bit_pack_test_test_pack_char;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
