#pragma once

// User-built template exception
template <typename T>
class CustomException 
{
public:
   CustomException(const T& msg) 
   {
      message = msg;
   } 

   T what() const 
   { 
      return message; 
   }
private:
   T message_;
};

