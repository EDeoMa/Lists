#include "MyVector.h"
#include "TestFramework.h"
#include "MyVectorTests.h"

void test_vector_capacity() {
	MyVector mvector;
	assert_equals(0, mvector.size());
	for (int i = 0; i < 11; i++) {
		mvector.push_back(i);
	}
	assert_equals(20, mvector.capacity());
}

void test_vector_push_back() {
	MyVector mvector;
	for (int i = 0; i < 10; i++) {
		mvector.push_back(i);
	}
	assert_equals(9, mvector[9]);
}

void test_vector_index_access_throws_on_too_big_index() {
	MyVector mvector;
	for (int i = 0; i < 10; i++) {
		mvector.push_back(i);
	}
	bool wasException = false;

	try {
		int el = mvector[mvector.size() + 1];
	}
	catch (myDataException& ex)
	{
		wasException = true;
	}

	assert_equals(true, wasException);

}

void test_vector_pop_back() {
	MyVector mvector;
	for (int i = 0; i < 10; i++) {
		mvector.push_back(i);
	}
	mvector.pop_back();
	assert_equals(9, mvector.size());
}

void run_vector_tests() {
	run_test(test_vector_capacity);
	run_test(test_vector_push_back);
	run_test(test_vector_index_access_throws_on_too_big_index);
	run_test(test_vector_pop_back);
}