#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

#include <string>
using namespace std;

// User-built template exception
template <typename T>
class CustomException 
{
 private:
    T m_message;
 public:
    CustomException(const T& msg) : m_message(msg) {}
    T what() const { return m_message; }
};

#endif
