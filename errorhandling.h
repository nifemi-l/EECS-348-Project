#ifndef ErrorHandling
#define ErrorHandling
    #include <stdio.h>
    #include <iostream>
    #include <exception>
    #include <string>
    using namespace std;

    class ErrorHandling {
        public: 
            ErrorHandling(const std::string& message);
            const char* what();
        private:
            std::string message_;
    };

#endif