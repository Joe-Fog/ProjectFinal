#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class DuplicatePlayerException : public std::exception { //starting to use std:: as namespace std is not recommended in header files
private:
    std::string msg;  // error message

public:

    DuplicatePlayerException(const std::string &name) //runs the exception and shows player trying to be added
      : msg("Player already exists: " + name) {}

    // Return the explanatory string
    const char* what() const noexcept override { //returns error message
        return msg.c_str();
    }
};

#endif // EXCEPTIONS_H
