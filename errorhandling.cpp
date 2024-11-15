/**Hannah Prosch */
/**Could also reside in Main, if too late to alter the software architecture. */

#include <stdio.h>
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class ErrorHandling : public std::exception {
public:
    ErrorHandling(const std::string& message) : message_(message) {}

    const char* what() const noexcept override {
        std::cout << "Error: " << message_.c_str() << std::endl;
        return message_.c_str();
    }

private:
    std::string message_;
};

/*Examples of code lines to add to throw these errors:*/
//throw ErrorHandling("There is divison by zero in this statement.");
//throw ErrorHandling("Quantity and/or direction of parenthesis does not match.");
//throw ErrorHandling("Please enter only valid numbers and operators."); //Example, someone enters ?, #, @, A, H, etc.  

