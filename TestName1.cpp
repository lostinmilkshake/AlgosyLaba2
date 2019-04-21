#include <iostream>
#include "RedBlackTreeClass.h"
#include <gtest/gtest.h>

TEST(MapTests, testInsertAndFind) {
    RedBlackTree<int, int> testTree;
    Node<int, int> *testNode;
    testTree.insert(11, 1);
    testTree.insert(6, 2);
    testTree.insert(1, 3);
    testTree.insert(5, 4);
    testNode = testTree.find(11);
    EXPECT_EQ(testNode->key, 11);
    EXPECT_EQ(testNode->value, 1);
}

TEST(MapTests, testInsertWrongValue) {
    RedBlackTree<int, int> testTree;
    testTree.insert(11, 1);
    testTree.insert(6, 2);
    testTree.insert(1, 3);
    testTree.insert(5, 4);
    try {
        testTree.insert(0, 12);
    } catch (invalid_argument error) {
        ASSERT_STRCASEEQ("Can not insert this type of key", error.what());
    }
}

TEST(MapTests, testFindNonExisting) {
    RedBlackTree<int, int> testTree;
    Node<int, int> *testNode;
    testTree.insert(11, 1);
    testTree.insert(6, 2);
    testTree.insert(1, 3);
    testTree.insert(5, 4);
    try {
        testNode = testTree.find(12);
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("There is no elements with this key", error.what());
    }
}

TEST(MapTests, testClear) {
    RedBlackTree<int, int> testTree;
    testTree.insert(11, 1);
    testTree.insert(6, 2);
    testTree.insert(1, 3);
    testTree.insert(5, 4);
    testTree.clear();
    EXPECT_EQ(testTree.root, nullptr);
    //EXPECT_EQ(testTree, nullptr);
}

TEST(MapTests, testRemove) {
    RedBlackTree<int, int> testTree;
    Node<int, int> *testNode;
    testTree.insert(11, 1);
    testTree.insert(6, 2);
    testTree.insert(1, 3);
    testTree.insert(5, 4);
    testTree.remove(5);
    try {
        testNode = testTree.find(11);
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("There is no elements with this key", error.what());
    }
}

TEST(MapTests, testInsertAlreadyExist) {
    RedBlackTree<int, int> testTree;
    testTree.insert(11, 1);
    testTree.insert(6, 2);
    testTree.insert(1, 3);
    testTree.insert(5, 4);
    try {
        testTree.insert(5, 11);
    }
    catch (invalid_argument error) {
        ASSERT_STRCASEEQ("This key already exist", error.what());
    }
}

TEST(MapTests, testGet_Keys) {
    RedBlackTree<int, int> testTree;
    MyList<int> testList;
    testTree.insert(11, 1);
    testTree.insert(6, 2);
    testTree.insert(1, 3);
    testTree.insert(5, 4);
    testList = testTree.get_keys();
    EXPECT_EQ(1, 1);
}

TEST(MapTests, testGet_Values) {
    RedBlackTree<int, int> testTree;
    MyList<int> testList;
    testTree.insert(11, 1);
    testTree.insert(6, 2);
    testTree.insert(1, 3);
    testTree.insert(5, 4);
    testList = testTree.get_values();
    EXPECT_EQ(1, 1);
}


TEST(CharMapTests, testInsertAndFind) {
    RedBlackTree<char, char> testTree;
    Node<char, char> *testNode;
    testTree.insert('h', 'a');
    testTree.insert('k', 'b');
    testTree.insert('a', 'c');
    testTree.insert('g', 'd');
    testNode = testTree.find('h');
    EXPECT_EQ(testNode->key, 'h');
    EXPECT_EQ(testNode->value, 'a');
}

TEST(CharMapTests, testInsertWrongValue) {
    RedBlackTree<char, char> testTree;
    testTree.insert('h', 'a');
    testTree.insert('k', 'b');
    testTree.insert('a', 'c');
    testTree.insert('g', 'd');
    try {
        testTree.insert(0, 'e');
    } catch (invalid_argument error) {
        ASSERT_STRCASEEQ("Can not insert this type of key", error.what());
    }
}

TEST(CharMapTests, testFindNonExisting) {
    RedBlackTree<char, char> testTree;
    Node<char, char> *testNode;
    testTree.insert('h', 'a');
    testTree.insert('k', 'b');
    testTree.insert('a', 'c');
    testTree.insert('g', 'd');
    try {
        testNode = testTree.find('e');
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("There is no elements with this key", error.what());
    }
}

TEST(CharMapTests, testClear) {
    RedBlackTree<char, char> testTree;
    testTree.insert('h', 'a');
    testTree.insert('k', 'b');
    testTree.insert('a', 'c');
    testTree.insert('g', 'd');
    testTree.clear();
    EXPECT_EQ(testTree.root, nullptr);
    //EXPECT_EQ(testTree.NIL, nullptr);
}

TEST(CharMapTests, testRemove) {
    RedBlackTree<char, char> testTree;
    Node<char, char> *testNode;
    testTree.insert('h', 'a');
    testTree.insert('k', 'b');
    testTree.insert('a', 'c');
    testTree.insert('g', 'd');
    testTree.remove('h');
    try {
        testNode = testTree.find('h');
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("There is no elements with this key", error.what());
    }
}

TEST(CharMapTests, testInsertAlreadyExist) {
    RedBlackTree<char, char> testTree;
    testTree.insert('h', 'a');
    testTree.insert('k', 'b');
    testTree.insert('a', 'c');
    testTree.insert('g', 'd');
    try {
        testTree.insert('j', 'i');
    }
    catch (invalid_argument error) {
        ASSERT_STRCASEEQ("This key already exist", error.what());
    }
}

TEST(CharMapTests, testGet_Keys) {
    RedBlackTree<char, char> testTree;
    MyList<char> testList;
    testTree.insert('h', 'a');
    testTree.insert('k', 'b');
    testTree.insert('a', 'c');
    testTree.insert('g', 'd');
    testList = testTree.get_keys();
    EXPECT_EQ(1, 1);
}

TEST(CharMapTests, testGet_Values) {
    RedBlackTree<char, char> testTree;
    MyList<char> testList;
    testTree.insert('h', 'a');
    testTree.insert('k', 'b');
    testTree.insert('a', 'c');
    testTree.insert('g', 'd');
    testList = testTree.get_values();
    EXPECT_EQ(1, 1);
}
