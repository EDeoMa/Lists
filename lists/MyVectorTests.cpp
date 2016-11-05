#include "MyVector.h"
#include "TestFramework.h"
#include "MyVectorTests.h"

void test_vector_create_new() {
	// Act
	MyVector mvector;

	// Assert
	assert_equals(0, mvector.size());
}

void test_vector_erase() {
	// Arrange
	MyVector mvector;
	for (int i = 0; i < 10; i++) {
		mvector.push_back(i);
	}
	// Act
	int result1 = mvector[5];
	int result2 = mvector.erase(5);
	// Assert
	assert_equals(result1, result2);
	assert_equals(9, mvector.size());
	assert_equals(6, mvector[5]);
}

void test_vector_insert() {
	// Arrange
	MyVector mvector;
	for (int i = 0; i < 10; i++) {
		mvector.push_back(i);
	}
	// Act
	mvector.insert(6, 15);
	// Assert
	assert_equals(20, mvector.capacity());
	assert_equals(11, mvector.size());
	assert_equals(15, mvector[6]);
}

void test_vector_push_back() {
	// Arrange
	MyVector mvector;
	
	// Act
	for (int i = 0; i < 10; i++) {
		mvector.push_back(i);
	}

	// Assert
	assert_equals(9, mvector[9]);
}

void test_vector_index_access_throws_on_too_big_index() {
	
	// Arrange
	MyVector mvector;
	for (int i = 0; i < 10; i++) {
		mvector.push_back(i);
	}
	bool wasException = false;

	// Act
	try {
		int el = mvector[mvector.size() + 1];
	}
	catch (myDataException& ex)
	{
		wasException = true;
	}

	// Assert
	assert_equals(true, wasException);

}

void test_vector_pop_back() {

	// Arrange
	MyVector mvector;
	for (int i = 0; i < 10; i++) {
		mvector.push_back(i);
	}

	// Act
	mvector.pop_back();

	// Assert
	assert_equals(8, mvector[mvector.size()-1]);
}

void run_vector_tests() {
	run_test(test_vector_create_new);
	run_test(test_vector_erase);
	run_test(test_vector_insert);
	run_test(test_vector_push_back);
	run_test(test_vector_index_access_throws_on_too_big_index);
	run_test(test_vector_pop_back);
}