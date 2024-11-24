/*Hannah Prosch*/

#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

    #include <exception>
    #include <string>

    class ErrorHandling : public std::exception {

    public:
        explicit ErrorHandling(const std::string& message);

        const char* what() const noexcept override;

    private:
        std::string message_;
    };

#endif