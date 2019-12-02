#include "ArrayDictionary.h"
#include "gtest/gtest.h"

#define PRINT

TEST(dict, array_dict_basic) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(1, 2));
    ASSERT_EQ(hashTable.size(), 1);
    ASSERT_FALSE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(8, 4));
    ASSERT_EQ(hashTable.size(), 2);

    ASSERT_TRUE(hashTable.add(11, 4));
    ASSERT_EQ(hashTable.size(), 2);
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict, array_dict_add_overwrite) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 2));
    ASSERT_TRUE(hashTable.add(2, 4));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.size(), 1);
}

TEST(dict, array_dict_value_set_size) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.valueSetSize(5), 0);
    ASSERT_EQ(hashTable.valueSetSize(2), 2);
    ASSERT_EQ(hashTable.valueSetSize(3), 1);
}

TEST(dict, array_dict_add_get) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    int val = 0;
    ASSERT_TRUE(hashTable.get(2, val));
    ASSERT_EQ(val, 9);
    ASSERT_TRUE(hashTable.get(12, val));
    ASSERT_EQ(val, 8);
    ASSERT_TRUE(hashTable.get(3, val));
    ASSERT_EQ(val, 4);
    ASSERT_FALSE(hashTable.get(7, val));
    ASSERT_EQ(val, 4);
}

TEST(dict, contains) {
    // homework
    ArrayDictionary<int, int> hashTable1(0);

    ASSERT_FALSE(hashTable1.contain(-1));
    ASSERT_FALSE(hashTable1.contain(0));
    ASSERT_FALSE(hashTable1.contain(1));

    ArrayDictionary<int, int> hashTable2(1);
    hashTable2.add(0, 103);

    ASSERT_FALSE(hashTable2.contain(2));
    ASSERT_TRUE(hashTable2.contain(0));

    ArrayDictionary<int, int> hashTable3(2);
    hashTable3.add(0, 103);
    hashTable3.add(1, 105);

    ASSERT_TRUE(hashTable3.contain(0));
    ASSERT_TRUE(hashTable3.contain(1));
    ASSERT_FALSE(hashTable3.contain(2));
    ASSERT_FALSE(hashTable3.contain(3));

    ArrayDictionary<int, int> hashTable4(3);
    hashTable4.add(0, 103);
    hashTable4.add(1, 105);

    ASSERT_FALSE(hashTable4.contain(3));
    ASSERT_TRUE(hashTable4.contain(1));

    ArrayDictionary<int, int> hashTable5(3);
    hashTable5.add(0, 103);
    hashTable5.add(1, 105);
    hashTable5.add(2, 206);
    hashTable5.add(4, 407);

    ASSERT_TRUE(hashTable5.contain(1));
    ASSERT_TRUE(hashTable5.contain(4));
    ASSERT_FALSE(hashTable5.contain(7));
    ASSERT_FALSE(hashTable5.contain(8));


}

TEST(dict, remove) {
    // homework

    ArrayDictionary<int, int> hashTable(5);

    ASSERT_FALSE(hashTable.remove(0));

    hashTable.add(1, 100);

    ASSERT_FALSE(hashTable.remove(0));
    ASSERT_TRUE(hashTable.remove(1));

    hashTable.add(1, 100);
    hashTable.add(6, 101);

    ASSERT_TRUE(hashTable.remove(1));

    hashTable.add(1, 100);
    hashTable.add(6, 101);

    ASSERT_TRUE(hashTable.remove(1));

}
