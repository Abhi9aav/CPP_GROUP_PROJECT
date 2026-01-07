#pragma once

// User-built template exception
template <typename T>
class CustomException 
{
public:
  explicit CustomException(const T& msg) : message_(msg)
   {
   } 

   const T& what() const 
   { 
      return message_; 
   }
   
private:
   T message_;
};

