#pragma once

#include "TwoWayList.h"
#include "TestFramework.h"



inline void test_create_new() {
    // Act
    TwoWayList list;

    // Assert
    assert_equals(0, list.size());
}

/* ��������� ��� ������� (push_back � []) � ������
   ����� ��������� ��� �� �����������, �� � ������ ������
   ����� ���-�� ����� � ������ ���� ���-�� ���� ��������,
   � ����� ���������, ��� ���-�� ����������, ���� ������ �����
*/
inline void test_push_back_and_index_access() {
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

/* ���������, ��� ��� ������� ���������� �� �������, ������������ �����
   ������, �������� ����������
*/
inline void test_index_access_throws_on_too_big_index() {
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
	catch(myDataException& ex)
	{
		wasException = true;
	}	

	// Assert
	assert_equals(true, wasException);

}



inline void run_list_tests() {
	run_test(test_create_new);
	run_test(test_push_back_and_index_access);
	run_test(test_index_access_throws_on_too_big_index);
}



