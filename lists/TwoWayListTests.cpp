
#include "TwoWayList.h"
#include "TestFramework.h"
#include "TwoWayListTests.h"

/* ѕровер€ем две функции (push_back и []) в св€зке
лучше провер€ть все по отдельности, но в данном случае
чтобы что-то найти в списке надо что-то туда положить,
а чтобы проверить, что что-то положилось, надо оттуда вз€ть
*/
void test_push_back_and_index_access() {
	// Arrange
	TwoWayList list;

	// Act
	const int SIZE = 10;
	for (int i = 0; i < SIZE; ++i)
	{
		list.push_back(i + 10);
	}

	// Assert
	assert_equals(SIZE, list.size());
	for (int i = 0; i < SIZE; ++i)
	{
		assert_equals(i + 10, list[i]);
	}

}

void test_list_create_new() {
	// Act
	TwoWayList list;

	// Assert
	assert_equals(0, list.size());
}

/* ѕровер€ем, что при попытке обратитьс€ по индексу, превышающему длину
списка, получаем исключение
*/
void test_index_access_throws_on_too_big_index() {
	// Arrange
	TwoWayList list;
	const int SIZE = 10;
	for (int i = 0; i < SIZE; ++i) {
		list.push_back(i + 10);
	}

	// Act
	bool wasException = false;

	try {
		int el = list[SIZE + 1];
	}
	catch (myDataException& ex)
	{
		wasException = true;
	}

	// Assert
	assert_equals(true, wasException);

}

void test_list_erase() {
	// Arrange
	TwoWayList mlist;

	// Act
	for (int i = 0; i < 10; i++) {
		mlist.push_back(i);
	}
	int i1 = mlist[5], i2 = mlist.erase(5);;
	// Assert
	assert_equals(i1, i2);
	assert_equals(9, mlist.size());
	assert_equals(6, mlist[5]);
}

void test_list_insert() {
	// Arrange
	TwoWayList mlist;

	// Act
	for (int i = 0; i < 10; i++) {
		mlist.push_back(i);
	}
	mlist.insert(6, 15);
	// Assert
	assert_equals(11, mlist.size());
	assert_equals(15, mlist[6]);
}

void run_list_tests() {
	run_test(test_list_create_new);
	run_test(test_list_erase);
	run_test(test_list_insert);
	run_test(test_push_back_and_index_access);
	run_test(test_index_access_throws_on_too_big_index);
}