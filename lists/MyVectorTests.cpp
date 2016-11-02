#include "MyVector.h"
#include "TestFramework.h"
#include "MyVectorTests.h"

void test_vector_capacity() {
	// Arrange
	MyVector mvector;

	// Act
	assert_equals(0, mvector.size());
	for (int i = 0; i < 11; i++) {
		mvector.push_back(i);
	}

	// Assert
	assert_equals(20, mvector.capacity());
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
	assert_equals(9, mvector.size());
}

void run_vector_tests() {
	run_test(test_vector_capacity);
	run_test(test_vector_push_back);
	run_test(test_vector_index_access_throws_on_too_big_index);
	run_test(test_vector_pop_back);
}