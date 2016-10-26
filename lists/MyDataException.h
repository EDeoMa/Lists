#pragma once

#include <exception>

struct myDataException :std::exception {
	char const *what() const noexcept {
		return "Wrong position";
	}
};