#include <iostream>
#include <string>
#include <vector>

class Student
{
private:
    std::string name_;
    std::string group_;
    std::vector<int> marks_;
    double averageScore_;

public:
    Student(const std::string& name, const std::string& group) : name_(name), group_(group), averageScore_(0.0) {}

    void addMark(int mark)
    {
        marks_.push_back(mark);

        int sum = 0;
        for (int currentMark : marks_)
        {
            sum += currentMark;
        }
        averageScore_ = static_cast<double>(sum) / marks_.size();
    }
    
    
    
    const std::vector<int>& getMarks() const
    {
        return marks_;
    }

    double getAverageScore() const
    {
        return averageScore_;
    }




};

int main()
{
    
    
    
    
    return 0;
}