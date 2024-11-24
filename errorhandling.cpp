/**Hannah Prosch */
/**Could also reside in Main, if too late to alter the software architecture. */
#include <stdio.h>
#include <iostream>
#include "errorhandling.h"
using namespace std;

ErrorHandling::ErrorHandling(const std::string& message)
    : message_(message) {}

const char* ErrorHandling::what() const noexcept {
    std::cout << "Error: " << message_ << std::endl;
    return message_.c_str();
}

/*Examples of code lines to add to throw these errors:*/
//throw ErrorHandling("There is divison by zero in this statement.");
//throw ErrorHandling("Quantity and/or direction of parenthesis does not match.");
//throw ErrorHandling("Please enter only valid numbers and operators."); //Example, someone enters ?, #, @, A, H, etc.  

//Can uncomment main below to test functionality with header file.
/*int main() {
    int x = 1;

    do {
        std::cout << "Enter 1 or 2 to test errors, 0 to end" << std::endl;
        std::cin >> x;

        if (x == 1) {
            throw ErrorHandling("Divison by zero!");
        }
        if (x == 2) {
            throw ErrorHandling("Quantity and/or direction of parenthesis does not match.");
        }

    } while (x != 0);

}*/

