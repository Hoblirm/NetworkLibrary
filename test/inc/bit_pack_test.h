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

  void test_pack_impl(void)
  {
    unsigned char data[4] = { 0 };
    unsigned char ary[5] = { 0 };

    /*
     * Case1: One byte no shift
     */
    data[0] = 0xFF;
    memset(ary, 0x00, sizeof(ary));
    pack_impl(data, 8, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0xFF);
    TS_ASSERT_EQUALS(ary[1], 0x00);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x00);
    TS_ASSERT_EQUALS(ary[4], 0x00);

    data[0] = 0x00;
    unpack(data, 8, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0xFF);

    data[0] = 0x00;
    unpack((int32_t*) data, 8, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0xFF);

    //Same as above, but bits are reversed.
    data[0] = 0x00;
    memset(ary, 0xFF, sizeof(ary));
    pack_impl(data, 8, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0x00);
    TS_ASSERT_EQUALS(ary[1], 0xFF);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xFF);
    TS_ASSERT_EQUALS(ary[4], 0xFF);

    data[0] = 0xFF;
    unpack(data, 8, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0x00);

    data[0] = 0xFF;
    unpack((int32_t*) data, 8, ary, 0);
    TS_ASSERT_EQUALS(data[0], 0x00);

    /*
     * Case2: One byte left shift
     */
    data[0] = 0xFF;
    memset(ary, 0x00, sizeof(ary));
    pack_impl(data, 4, ary, 1);
    TS_ASSERT_EQUALS(ary[0], 0x78);
    TS_ASSERT_EQUALS(ary[1], 0x00);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x00);
    TS_ASSERT_EQUALS(ary[4], 0x00);

    data[0] = 0x00;
    unpack(data, 4, ary, 1);
    TS_ASSERT_EQUALS(data[0], 0x0F);

    data[0] = 0x00;
    unpack((int32_t*) data, 4, ary, 1);
    TS_ASSERT_EQUALS(data[0], 0xFF);

    //Same as above, but bits are reversed.
    data[0] = 0x00;
    memset(ary, 0xFF, sizeof(ary));
    pack_impl(data, 4, ary, 1);
    TS_ASSERT_EQUALS(ary[0], 0x87);
    TS_ASSERT_EQUALS(ary[1], 0xFF);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xFF);
    TS_ASSERT_EQUALS(ary[4], 0xFF);

    data[0] = 0x0F;
    unpack(data, 4, ary, 1);
    TS_ASSERT_EQUALS(data[0], 0x00);

    data[0] = 0x0F;
    unpack((int32_t*) data, 4, ary, 1);
    TS_ASSERT_EQUALS(data[0], 0x00);

    /*
     * Case3: One byte right shift
     */
    data[0] = 0xFF;
    memset(ary, 0x00, sizeof(ary));
    pack_impl(data, 8, ary, 4);
    TS_ASSERT_EQUALS(ary[0], 0x0F);
    TS_ASSERT_EQUALS(ary[1], 0xF0);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x00);
    TS_ASSERT_EQUALS(ary[4], 0x00);

    data[0] = 0x00;
    unpack(data, 8, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0xFF);

    data[0] = 0x00;
    unpack((int32_t*) data, 8, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0xFF);

    //Same as above, but bits are reversed.
    data[0] = 0x00;
    memset(ary, 0xFF, sizeof(ary));
    pack_impl(data, 8, ary, 4);
    TS_ASSERT_EQUALS(ary[0], 0xF0);
    TS_ASSERT_EQUALS(ary[1], 0x0F);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xFF);
    TS_ASSERT_EQUALS(ary[4], 0xFF);

    data[0] = 0xFF;
    unpack(data, 8, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0x00);

    data[0] = 0xFF;
    unpack((int32_t*) data, 8, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0x00);

    /*
     * Case4: Four bytes no shift
     */
    data[0] = 0xFF;
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0xFF;
    memset(ary, 0x00, sizeof(ary));
    pack_impl(data, 32, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0xFF);
    TS_ASSERT_EQUALS(ary[1], 0xFF);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xFF);
    TS_ASSERT_EQUALS(ary[4], 0x00);

    data[0] = 0x00;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    unpack(data, 32, ary, 0);
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
    pack_impl(data, 32, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0x00);
    TS_ASSERT_EQUALS(ary[1], 0x00);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x00);
    TS_ASSERT_EQUALS(ary[4], 0xFF);

    data[0] = 0xFF;
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0xFF;
    unpack(data, 32, ary, 0);
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
    pack_impl(data, 28, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0xFF);
    TS_ASSERT_EQUALS(ary[1], 0xFF);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xF0);
    TS_ASSERT_EQUALS(ary[4], 0x00);

    data[0] = 0xF0;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    unpack(data, 28, ary, 0);
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
    pack_impl(data, 28, ary, 0);
    TS_ASSERT_EQUALS(ary[0], 0x00);
    TS_ASSERT_EQUALS(ary[1], 0x00);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x0F);
    TS_ASSERT_EQUALS(ary[4], 0xFF);

    data[0] = 0x0F;
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0xFF;
    unpack(data, 28, ary, 0);
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
    pack_impl(data, 32, ary, 4);
    TS_ASSERT_EQUALS(ary[0], 0x0F);
    TS_ASSERT_EQUALS(ary[1], 0xFF);
    TS_ASSERT_EQUALS(ary[2], 0xFF);
    TS_ASSERT_EQUALS(ary[3], 0xFF);
    TS_ASSERT_EQUALS(ary[4], 0xF0);

    data[0] = 0x00;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    unpack(data, 32, ary, 4);
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
    pack_impl(data, 32, ary, 4);
    TS_ASSERT_EQUALS(ary[0], 0xF0);
    TS_ASSERT_EQUALS(ary[1], 0x00);
    TS_ASSERT_EQUALS(ary[2], 0x00);
    TS_ASSERT_EQUALS(ary[3], 0x00);
    TS_ASSERT_EQUALS(ary[4], 0x0F);

    data[0] = 0xFF;
    data[1] = 0xFF;
    data[2] = 0xFF;
    data[3] = 0xFF;
    unpack(data, 32, ary, 4);
    TS_ASSERT_EQUALS(data[0], 0x00);
    TS_ASSERT_EQUALS(data[1], 0x00);
    TS_ASSERT_EQUALS(data[2], 0x00);
    TS_ASSERT_EQUALS(data[3], 0x00);
  }

  void test_pack_uint64(void)
  {
    unsigned char buffer[9] = { 0 };

    /*
     * Case1: Positive value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 64; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a number that has all bits set.
      uint64_t data = 0xFFFFFFFFFFFFFFFF;

      //We shift data to the right as the bit size decreases.  This ensures
      //the number is within range for the bit size.
      data >>= (64 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0x00; //Since the front of data is '1' use '0' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0x00;            //Since the end of data is '1' use '0' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        uint64_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }            //for: bit_offset
    }  //for: bit_size
  }  //test_pack_uint64

  void test_pack_uint32(void)
  {
    unsigned char buffer[9] = { 0 };

    /*
     * Case1: Positive value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 32; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a number that has all bits set.
      uint32_t data = 0xFFFFFFFF;

      //We shift data to the right as the bit size decreases.  This ensures
      //the number is within range for the bit size.
      data >>= (32 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0x00; //Since the front of data is '1' use '0' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0x00;            //Since the end of data is '1' use '0' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        uint32_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }            //for: bit_offset
    }  //for: bit_size
  }  //test_pack_uint32

  void test_pack_uint16(void)
  {
    unsigned char buffer[9] = { 0 };

    /*
     * Case1: Positive value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 16; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a number that has all bits set.
      uint16_t data = 0xFFFF;

      //We shift data to the right as the bit size decreases.  This ensures
      //the number is within range for the bit size.
      data >>= (16 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0x00; //Since the front of data is '1' use '0' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0x00;            //Since the end of data is '1' use '0' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        uint16_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }            //for: bit_offset
    }  //for: bit_size
  }  //test_pack_uint16

  void test_pack_uint8(void)
  {
    unsigned char buffer[9] = { 0 };

    /*
     * Case1: Positive value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 8; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a number that has all bits set.
      uint8_t data = 0xFF;

      //We shift data to the right as the bit size decreases.  This ensures
      //the number is within range for the bit size.
      data >>= (8 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0x00; //Since the front of data is '1' use '0' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0x00;            //Since the end of data is '1' use '0' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        uint8_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }            //for: bit_offset
    }  //for: bit_size
  }  //test_pack_uint8

  void test_pack_int64(void)
  {
    unsigned char buffer[9] = { 0 };

    /*
     * Case1: Positive value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 64; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a positive number that has all bits set.
      int64_t data = 0x7FFFFFFFFFFFFFFF;

      //We shift data to the right as the bit size decreases. This ensures
      //data is positive for all bit sizes.
      data >>= (64 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0xFF; //Since the front of data is '0' use '1' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0x00;            //Since the end of data is '1' use '0' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        int64_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }
    }

    /*
     * Case2: Negative value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 64; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a negative number that only has its signed bit set.
      int64_t data = 0x8000000000000000;

      //We shift data to the right as the bit size decreases.  Remember that
      //a right shift for a signed type will fill in 1's on the left side for.
      //negative numbers. This ensures data is negative for all bit sizes.
      data >>= (64 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0x00; //Since the front of data is '1' use '0' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0xFF;        //Since the end of data is '0' use '1' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        int64_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }        //for: bit_offset
    }        //for: size_in_bits
  }        //test_pack_int64

  void test_pack_int32(void)
  {
    unsigned char buffer[5] = { 0 };

    /*
     * Case1: Positive value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 32; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a positive number that has all bits set.
      int32_t data = 0x7FFFFFFF;

      //We shift data to the right as the bit size decreases. This ensures
      //data is positive for all bit sizes.
      data >>= (32 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0xFF;        //Since the front of data is '0' use '1' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0x00;        //Since the end of data is '1' use '0' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        int32_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }
    }

    /*
     * Case2: Negative value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 32; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a negative number that only has its signed bit set.
      int32_t data = 0x80000000;

      //We shift data to the right as the bit size decreases.  Remember that
      //a right shift for a signed type will fill in 1's on the left side for.
      //negative numbers. This ensures data is negative for all bit sizes.
      data >>= (32 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0x00;        //Since the front of data is '1' use '0' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0xFF;        //Since the end of data is '0' use '1' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        int32_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }        //for: bit_offset
    }        //for: bit_size
  }        //test_pack_int32

  void test_pack_int16(void)
  {
    unsigned char buffer[3] = { 0 };

    /*
     * Case1: Positive value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 16; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a positive number that has all bits set.
      int16_t data = 0x7FFF;

      //We shift data to the right as the bit size decreases. This ensures
      //data is positive for all bit sizes.
      data >>= (16 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0xFF;        //Since the front of data is '0' use '1' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0x00;        //Since the end of data is '1' use '0' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        int16_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }
    }

    /*
     * Case2: Negative value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 16; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a negative number that only has its signed bit set.
      int16_t data = 0x8000;

      //We shift data to the right as the bit size decreases.  Remember that
      //a right shift for a signed type will fill in 1's on the left side for.
      //negative numbers. This ensures data is negative for all bit sizes.
      data >>= (16 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0x00;        //Since the front of data is '1' use '0' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0xFF;        //Since the end of data is '0' use '1' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        int16_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }        //for: bit_offset
    }        //for: bit_size
  }        //test_pack_int16

  void test_pack_int8(void)
  {
    unsigned char buffer[3] = { 0 };

    /*
     * Case1: Positive value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 8; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a positive number that has all bits set.
      int8_t data = 0x7F;

      //We shift data to the right as the bit size decreases. This ensures
      //data is positive for all bit sizes.
      data >>= (8 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0xFF;        //Since the front of data is '0' use '1' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0x00;        //Since the end of data is '1' use '0' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        int8_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }
    }

    /*
     * Case2: Negative value
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bits = 8; size_in_bits >= 1; --size_in_bits)
    {
      //We will use a negative number that only has its signed bit set.
      int8_t data = 0x80;

      //We shift data to the right as the bit size decreases.  Remember that
      //a right shift for a signed type will fill in 1's on the left side for.
      //negative numbers. This ensures data is negative for all bit sizes.
      data >>= (8 - size_in_bits);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0x00;        //Since the front of data is '1' use '0' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0xFF;        //Since the end of data is '0' use '1' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        int8_t val = 0;
        unpack(&val, size_in_bits, buffer, buffer_offset);
        TS_ASSERT_EQUALS(data, val);

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }        //for: bit_offset
    }        //for: bit_size
  }        //test_pack_int8

  void test_pack_uchar(void)
  {
    unsigned char buffer[BIT_PACK_MAX_STRING_LENGTH + 1] = { 0 };

    /*
     * Case1: Default case
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bytes = BIT_PACK_MAX_STRING_LENGTH; size_in_bytes >= 1; --size_in_bytes)
    {
      int size_in_bits = size_in_bytes * 8;

      //We will use a string that has all bits set.
      unsigned char data[BIT_PACK_MAX_STRING_LENGTH] = { 0 };
      memset(data, 0xFF, size_in_bytes);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0x00, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0x00; //Since the front of data is '1' use '0' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0x00;            //Since the end of data is '1' use '0' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        unsigned char val[BIT_PACK_MAX_STRING_LENGTH] = { 0 };
        unpack(val, size_in_bits, buffer, buffer_offset);
        for (int i = 0; i < BIT_PACK_MAX_STRING_LENGTH; ++i)
        {
          TS_ASSERT_EQUALS(data[i], val[i]);
        }

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }            //for: bit_offset
    }  //for: bit_size
  }  //test_pack_uchar

  void test_pack_char(void)
  {
    unsigned char buffer[BIT_PACK_MAX_STRING_LENGTH + 1] = { 0 };

    /*
     * Case1: Default case
     */
    //We will test all bit sizes that can be packed by this data type.
    for (int size_in_bytes = BIT_PACK_MAX_STRING_LENGTH; size_in_bytes >= 1; --size_in_bytes)
    {
      int size_in_bits = size_in_bytes * 8;

      //We will use a string that has all bits cleared.
      char data[BIT_PACK_MAX_STRING_LENGTH] = { 0 };
      memset(data, 0x00, size_in_bytes);

      //We will also test all bit offsets that can be used by the pack method.
      for (int buffer_offset = 0; buffer_offset < 8; ++buffer_offset)
      {
        //Clear out the contents of buffer.
        memset(buffer, 0xFF, sizeof(buffer));

        //To ensure pack() does not overlap other data in the buffer,
        //we will also pack bits in front of data.  If a buffer offset
        //is used in pack(), that means there will be unused bits in
        //the first byte that data isn't using.
        int8_t head = 0xFF; //Since the front of data is '0' use '1' for head.
        if (buffer_offset != 0)
        {
          pack(head, buffer_offset, buffer, 0);
        }

        //Now pack data into the buffer.
        pack(data, size_in_bits, buffer, buffer_offset);

        //We will also pack bits into the unused portion of the
        //last byte.  This is another test to ensure pack() doesn't
        //overlap any bits within buffer.
        int tail_offset = (size_in_bits + buffer_offset) % 8;
        int tail_size = 8 - tail_offset;
        int tail_byte_offset = (buffer_offset + size_in_bits) / 8;
        int8_t tail = 0xFF;            //Since the end of data is '0' use '1' for tail.
        pack(tail, tail_size, buffer + tail_byte_offset, tail_offset);

        //Unpack the 'unused' head bits.  Ensure it matches what was packed.
        if (buffer_offset != 0)
        {
          int8_t head_val;
          unpack(&head_val, buffer_offset, buffer, 0);
          TS_ASSERT_EQUALS(head, head_val);
        }

        //Unpack data and ensures it matches what was packed.
        char val[BIT_PACK_MAX_STRING_LENGTH] = { 0 };
        unpack(val, size_in_bits, buffer, buffer_offset);
        for (int i = 0; i < BIT_PACK_MAX_STRING_LENGTH; ++i)
        {
          TS_ASSERT_EQUALS(data[i], val[i]);
        }

        //Unpack the 'unused' tail bits.  Ensure it matches what was packed.
        int8_t tail_val;
        unpack(&tail_val, tail_size, buffer + tail_byte_offset, tail_offset);
        TS_ASSERT_EQUALS(tail, tail_val);
      }            //for: bit_offset
    }  //for: bit_size
  }  //test_pack_char

}
;
