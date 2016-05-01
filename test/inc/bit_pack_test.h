#include <cxxtest/TestSuite.h>

#include "bit_pack.h"

class bit_pack_test: public CxxTest::TestSuite
{

public:

  void setUp()
  {
  }

  void tearDown()
  {
  }

  void test_pack(void)
  {
    unsigned char data[5] = { 0 };
    unsigned char ary[5] = { 0 };

    /*
     * Case1: One byte no shift
     */
    data[0] = 0xFF;
    memset(ary, 0x00, sizeof(ary));
    pack(data, 8, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0xFF);
    TS_ASSERT_EQUALS(ary[1], 0x00);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x00);
    TS_ASSERT_EQUALS(ary[4], 0x00);

    data[0] = 0x00;
    unsigned_unpack(data, 8, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0xFF);

    data[0] = 0x00;
    signed_unpack(data, 8, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0xFF);

    //Same as above, but bits are reversed.
    data[0] = 0x00;
    memset(ary, 0xFF, sizeof(ary));
    pack(data, 8, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0x00);
    TS_ASSERT_EQUALS(ary[1], 0xFF);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xFF);
    TS_ASSERT_EQUALS(ary[4], 0xFF);

    data[0] = 0xFF;
    unsigned_unpack(data, 8, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0x00);

    data[0] = 0xFF;
    signed_unpack(data, 8, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0x00);

    /*
     * Case2: One byte left shift
     */
    data[0] = 0xFF;
    memset(ary, 0x00, sizeof(ary));
    pack(data, 4, ary, 1);
    TS_ASSERT_EQUALS(ary[0], 0x78);
    TS_ASSERT_EQUALS(ary[1], 0x00);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x00);
    TS_ASSERT_EQUALS(ary[4], 0x00);

    data[0] = 0x00;
    unsigned_unpack(data, 4, ary, 1);
    TS_ASSERT_EQUALS(data[0], 0x0F);

    data[0] = 0x00;
    signed_unpack(data, 4, ary, 1);
    TS_ASSERT_EQUALS(data[0], 0xFF);

    //Same as above, but bits are reversed.
    data[0] = 0x00;
    memset(ary, 0xFF, sizeof(ary));
    pack(data, 4, ary, 1);
    TS_ASSERT_EQUALS(ary[0], 0x87);
    TS_ASSERT_EQUALS(ary[1], 0xFF);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xFF);
    TS_ASSERT_EQUALS(ary[4], 0xFF);

    data[0] = 0x0F;
    unsigned_unpack(data, 4, ary, 1);
    TS_ASSERT_EQUALS(data[0], 0x00);

    data[0] = 0x0F;
    signed_unpack(data, 4, ary, 1);
    TS_ASSERT_EQUALS(data[0], 0x00);

    /*
     * Case3: One byte right shift
     */
    data[0] = 0xFF;
    memset(ary, 0x00, sizeof(ary));
    pack(data, 8, ary, 4);
    TS_ASSERT_EQUALS(ary[0], 0x0F);
    TS_ASSERT_EQUALS(ary[1], 0xF0);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x00);
    TS_ASSERT_EQUALS(ary[4], 0x00);

    data[0] = 0x00;
    unsigned_unpack(data, 8, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0xFF);

    data[0] = 0x00;
    signed_unpack(data, 8, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0xFF);

    //Same as above, but bits are reversed.
    data[0] = 0x00;
    memset(ary, 0xFF, sizeof(ary));
    pack(data, 8, ary, 4);
    TS_ASSERT_EQUALS(ary[0], 0xF0);
    TS_ASSERT_EQUALS(ary[1], 0x0F);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xFF);
    TS_ASSERT_EQUALS(ary[4], 0xFF);

    data[0] = 0xFF;
    unsigned_unpack(data, 8, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0x00);

    data[0] = 0xFF;
    signed_unpack(data, 8, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0x00);

    /*
     * Case4: Four bytes no shift
     */
    data[0] = 0xFF;
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0xFF;
    memset(ary, 0x00, sizeof(ary));
    pack(data, 32, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0xFF);
    TS_ASSERT_EQUALS(ary[1], 0xFF);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xFF);
    TS_ASSERT_EQUALS(ary[4], 0x00);

    data[0] = 0x00;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    unsigned_unpack(data, 32, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0xFF);
    TS_ASSERT_EQUALS(data[1], 0xFF);
    TS_ASSERT_EQUALS(data[2], 0xFF);
    TS_ASSERT_EQUALS(data[3], 0xFF);

    //Same as above, but bits are reversed.
    data[0] = 0x00;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    memset(ary, 0xFF, sizeof(ary));
    pack(data, 32, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0x00);
    TS_ASSERT_EQUALS(ary[1], 0x00);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x00);
    TS_ASSERT_EQUALS(ary[4], 0xFF);

    data[0] = 0xFF;
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0xFF;
    unsigned_unpack(data, 32, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0x00);
    TS_ASSERT_EQUALS(data[1], 0x00);
    TS_ASSERT_EQUALS(data[2], 0x00);
    TS_ASSERT_EQUALS(data[3], 0x00);

    /*
     * Case5: Four bytes left shift
     */
    data[0] = 0x0F;
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0xFF;
    memset(ary, 0x00, sizeof(ary));
    pack(data, 28, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0xFF);
    TS_ASSERT_EQUALS(ary[1], 0xFF);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xF0);
    TS_ASSERT_EQUALS(ary[4], 0x00);

    data[0] = 0xF0;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    unsigned_unpack(data, 28, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0x0F);
    TS_ASSERT_EQUALS(data[1], 0xFF);
    TS_ASSERT_EQUALS(data[2], 0xFF);
    TS_ASSERT_EQUALS(data[3], 0xFF);

    //Same as above, but bits are reversed.
    data[0] = 0xF0;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    memset(ary, 0xFF, sizeof(ary));
    pack(data, 28, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0x00);
    TS_ASSERT_EQUALS(ary[1], 0x00);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x0F);
    TS_ASSERT_EQUALS(ary[4], 0xFF);

    data[0] = 0x0F;
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0xFF;
    unsigned_unpack(data, 28, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0x00);
    TS_ASSERT_EQUALS(data[1], 0x00);
    TS_ASSERT_EQUALS(data[2], 0x00);
    TS_ASSERT_EQUALS(data[3], 0x00);

    /*
     * Case6: Four bytes right shift
     */
    data[0] = 0xFF;
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0xFF;
    memset(ary, 0x00, sizeof(ary));
    pack(data, 32, ary, 4);
    TS_ASSERT_EQUALS(ary[0], 0x0F);
    TS_ASSERT_EQUALS(ary[1], 0xFF);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xFF);
    TS_ASSERT_EQUALS(ary[4], 0xF0);

    data[0] = 0x00;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    unsigned_unpack(data, 32, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0xFF);
    TS_ASSERT_EQUALS(data[1], 0xFF);
    TS_ASSERT_EQUALS(data[2], 0xFF);
    TS_ASSERT_EQUALS(data[3], 0xFF);

    //Same as above, but bits are reversed.
    data[0] = 0x00;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    memset(ary, 0xFF, sizeof(ary));
    pack(data, 32, ary, 4);
    TS_ASSERT_EQUALS(ary[0], 0xF0);
    TS_ASSERT_EQUALS(ary[1], 0x00);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x00);
    TS_ASSERT_EQUALS(ary[4], 0x0F);

    data[0] = 0xFF;
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0xFF;
    unsigned_unpack(data, 32, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0x00);
    TS_ASSERT_EQUALS(data[1], 0x00);
    TS_ASSERT_EQUALS(data[2], 0x00);
    TS_ASSERT_EQUALS(data[3], 0x00);
  }
};
