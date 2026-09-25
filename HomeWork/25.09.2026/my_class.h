#pragma once
#include <string>

struct my_struct
{
    int field;
    int add(int x, int y);
public:
    
protected:
   
private:
    
};

class my_class
{
    int private_field;


public:
    my_class();
    my_class(int value, const std::string& str);
    ~my_class();
    my_class(const my_class& other);
    my_class(my_class&& other);
    my_class& operator=(const my_class& other);
    my_class& operator=(my_class&& other);
    
    virtual void print();
    
    int field;
    std::string my_string;
protected:

private:

};


class derivative_class : public my_class
{
public:
    derivative_class() : my_class() {
        field = 1;
        my_string = "";
    }
    virtual void print() override;
    
};