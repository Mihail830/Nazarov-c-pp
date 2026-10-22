#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
        out << "Name: " << student.name_ << std::endl;
        out << "Group: " << student.group_ << std::endl;
        out << "Marks: ";
        for (int mark : student.marks_)
        {
            out << mark << " ";
        }
        out << "Average score: " << student.averageScore_ << std::endl;
        return out;
    }
};

int main()
{
    Student first("Daniil", "612");
    first.addMark(5);
    first.addMark(3);

    Student second("Mikhail", "613");
    second.addMark(4);
    second.addMark(5);

    Student third("Nikita", "611");
    third.addMark(3);
    third.addMark(3);

    std::vector<Student> students = {first, second, third};

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b)
    {
        return a < b;
    });

    for (const Student& student : students)
    {
        std::cout << student << std::endl;
    }
    
    return 0;
}