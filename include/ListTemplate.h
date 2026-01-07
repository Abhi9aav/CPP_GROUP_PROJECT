#pragma once

#include <vector>
#include <cstddef>

// Generic simple list 
template <typename T>  // so we can make students or faculty
class ListTemplate 
{
 public:

    void add(const T& item) 
    {
        items_.push_back(item);
    }

    bool removeAt(std::size_t index) 
    {
        if (index >= items_.size()) 
        {
            return false;
        }

        items_.erase(items_.begin() + index);
        return true;
    }

    std::size_t size() const 
    { 
        return items_.size(); 
    }

    const std::vector<T>& all() const 
    { 
        return items_;
    }

private:
    std::vector<T> items_;    
};

