#pragma once

#include <exception>
#include <functional>
#include <iostream>

/* ����������, ������������� ������, ����� �������� ����� �� ������������ ����������������*/
class AssertionException : public std::exception
{

};

template<typename T>
inline void assert_equals(T expected, T actual)
{
	// �� "��������" ��������� ��������� ����� �������� ��� ���������, � ��� ��������
	// �������� ��� ����������
	if (expected != actual)
		throw AssertionException();
}


/*������� ��� ������� ������ ��������� ������
  ������������ ����� ����������, ����� ����� ������� ����������� ����������� ���� ������
  � �� ������ �� ����� ������*/
inline void run_test(std::function<void()>  testFunction) {
	// 
	try
	{
		testFunction();
		// �������� framework ��� �� ����� �������� �����
		std::cout << "TEST OK" << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception running tests: " << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exception running tests!" << std::endl;
		throw;
	}
}