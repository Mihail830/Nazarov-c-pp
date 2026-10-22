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

    bool operator<(const Student& other) const
    {
        return averageScore_ < other.averageScore_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& student)
    {
        out << "Имя: " << student.name_ << std::endl;
        out << "Группа: " << student.group_ << std::endl;
        out << "Оценки: ";
        for (int mark : student.marks_)
        {
            out << mark << " ";
        }
        out << "Средний балл: " << student.averageScore_ << std::endl;
        return out;
    }




};

int main()
{
    
    
    
    
    return 0;
}