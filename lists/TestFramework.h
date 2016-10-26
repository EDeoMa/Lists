#pragma once

#include <exception>
#include <functional>
#include <iostream>

/* Исключение, выбрасываемое тестом, когда ожидание теста не соответсвует действительности*/
class AssertionException : public std::exception
{

};

template<typename T>
inline void assert_equals(T expected, T actual)
{
	// во "взрослом" фреймворе сообщение будет включать что ожидалось, а что получено
	// оставляю как упражнение
	if (expected != actual)
		throw AssertionException();
}


/*Обертка для запуска одного тестового метода
  обеспечивает ловлю исключений, давай таким образом возможности запуститься всем тестам
  а не упасть на самом первом*/
inline void run_test(std::function<void()>  testFunction) {
	// 
	try
	{
		testFunction();
		// взрослый framework еще бы писал название теста
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