#include "pch.h"
#include "\Users\Dogge!\source\repos\Laba 2\RedBlackTreeClass.h"


TEST(MapTests, testInsertAndFind) {
	MyMap<int, int> testTree;
	Node<int, int>* testNode;
	testTree.insert(11, 1);
	testTree.insert(6, 2);
	testTree.insert(1, 3);
	testTree.insert(5, 4);
	testNode = testTree.find(11);
	EXPECT_EQ(testNode->returnKey(), 11);
	EXPECT_EQ(testNode->returnValue(), 1);
}

TEST(MapTests, testInsertMinusValue) {
	MyMap<int, int> testTree;
	Node<int, int>* testNode;
	testTree.insert(11, 1);
	testTree.insert(6, 2);
	testTree.insert(1, 3);
	testTree.insert(5, 4);
	testTree.insert(-32, -9);
	testNode = testTree.find(-32);
	EXPECT_EQ(testNode->returnKey(), -32);
	EXPECT_EQ(testNode->returnValue(), -9);
}

TEST(MapTests, testFindNonExisting) {
	MyMap<int, int> testTree;
	Node<int, int>* testNode;
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
	MyMap<int, int> testTree;
	testTree.insert(11, 1);
	testTree.insert(6, 2);
	testTree.insert(1, 3);
	testTree.insert(5, 4);
	testTree.clear();
	EXPECT_EQ(testTree.returnRoot(), nullptr);
	//EXPECT_EQ(testTree, nullptr);
}

TEST(MapTests, testRemove) {
	MyMap<int, int> testTree;
	Node<int, int>* testNode;
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
	MyMap<int, int> testTree;
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
	MyMap<int, int> testTree;
	MyList<int>* testList;
	MyList<int> testingList = { 6, 1, 5, 11 };
	testTree.insert(11, 1);
	testTree.insert(6, 2);
	testTree.insert(1, 3);
	testTree.insert(5, 4);
	testList = testTree.get_keys();
	EXPECT_TRUE(*testList == testingList);
}

TEST(MapTests, testGet_Values) {
	MyMap<int, int> testTree;
	MyList<int>* testList;
	MyList<int> testingList = { 2, 3, 4, 1 };
	testTree.insert(11, 1);
	testTree.insert(6, 2);
	testTree.insert(1, 3);
	testTree.insert(5, 4);
	testList = testTree.get_values();
	EXPECT_TRUE(*testList == testingList);
}


TEST(CharMapTests, testInsertAndFind) {
	MyMap<char, char> testTree;
	Node<char, char>* testNode;
	testTree.insert('h', 'a');
	testTree.insert('k', 'b');
	testTree.insert('a', 'c');
	testTree.insert('g', 'd');
	testNode = testTree.find('h');
	EXPECT_EQ(testNode->returnKey(), 'h');
	EXPECT_EQ(testNode->returnValue(), 'a');
}

TEST(CharMapTests, testInsertWrongValue) {
	MyMap<char, char> testTree;
	testTree.insert('h', 'a');
	testTree.insert('k', 'b');
	testTree.insert('a', 'c');
	testTree.insert('g', 'd');
	try {
		testTree.insert(0, 'e');
	}
	catch (invalid_argument error) {
		ASSERT_STRCASEEQ("Can not insert this type of key", error.what());
	}
}

TEST(CharMapTests, testFindNonExisting) {
	MyMap<char, char> testTree;
	Node<char, char>* testNode;
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
	MyMap<char, char> testTree;
	testTree.insert('h', 'a');
	testTree.insert('k', 'b');
	testTree.insert('a', 'c');
	testTree.insert('g', 'd');
	testTree.clear();
	EXPECT_EQ(testTree.returnRoot(), nullptr);
	//EXPECT_EQ(testTree.NIL, nullptr);
}

TEST(CharMapTests, testRemove) {
	MyMap<char, char> testTree;
	Node<char, char>* testNode;
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
	MyMap<char, char> testTree;
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
	MyMap<char, char> testTree;
	MyList<char>* testList;
	MyList<char> testingList = { 'h', 'a', 'g', 'k' };
	testTree.insert('h', 'a');
	testTree.insert('k', 'b');
	testTree.insert('a', 'c');
	testTree.insert('g', 'd');
	testList = testTree.get_keys();
	EXPECT_TRUE(*testList == testingList);
}

TEST(CharMapTests, testGet_Values) {
	MyMap<char, char> testTree;
	MyList<char>* testList;
	MyList<char> testingList = { 'a', 'c', 'd', 'b' };
	testTree.insert('h', 'a');
	testTree.insert('k', 'b');
	testTree.insert('a', 'c');
	testTree.insert('g', 'd');
	testList = testTree.get_values();
	EXPECT_TRUE(*testList == testingList);
}