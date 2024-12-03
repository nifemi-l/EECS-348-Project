#include <stdio.h>
#include <iostream>
#include "errorhandling.h"
using namespace std;

ErrorHandling::ErrorHandling(const std::string& message)
    : message_(message) {}

const char* ErrorHandling::what() const noexcept {
    return message_.c_str();
}
