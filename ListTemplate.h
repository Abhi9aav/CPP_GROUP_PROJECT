#ifndef LISTTEMPLATE_H
#define LISTTEMPLATE_H

#include <vector>
#include <iostream>
using namespace std;

// Generic simple list 
template <typename T>
class ListTemplate 
{
 private:
    vector<T> m_items;
 public:

    void add(const T& item) 
    {
        m_items.push_back(item);
    }

    bool removeAt(size_t index) 
    {
        if (index >= m_items.size()) 
        {
            return false;
        }

        m_items.erase(m_items.begin() + index);
        return true;
    }

    size_t size() const 
    { 
        return m_items.size(); 
    }

    const vector<T>& all() const 
    { 
        return m_items;
    }

    
    void show() const 
    {
        for (const auto& it : m_items) 
        {
            cout << it << endl;
        }
    }
};

#endif

