#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

#include <string>
using namespace std;

// User-built template exception
template <typename T>
class CustomException 
{
 private:
    T message;
 public:
    CustomException(const T& msg) 
    {
      message = msg;
    } 
    T what() const { return m_message; }
};

#endif
