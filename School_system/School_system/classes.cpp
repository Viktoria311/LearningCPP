#include <iostream>
#include <string>
#include <array>
#include <classes.h>

Person::Person(const std::string &first_name, const std::string &last_name) :
    first_name_(first_name),
    last_name_(last_name) {}
Person::~Person() {}
std::string Person::enter_name() const
{
    std::string str;
    std::getline(std::cin, str);
    return str;
}
void Person::change_name()
{
    std::cout << "Enter the first name: ";
    first_name_ = enter_name();
    std::cout << "Enter the last name: ";
    last_name_ = enter_name();
}
const std::string & Person::first_name() const
{
    return first_name_;
}
const std::string & Person::last_name() const
{
    return last_name_;
}
void Person::show_occupation() const
{
    std::cout << "Nothing to say" << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Worker::Worker(std::string first_name, std::string last_name, double salary) :
    Person(first_name, last_name),
    salary_(salary) {}
Worker::~Worker() {}
double Worker::get_salary() const
{
    return salary_;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const std::array<std::pair<int, std::string>, 7> classes = { std::make_pair(0, "Maths"),
                                                    std::make_pair(1, "English"),
                                                    std::make_pair(2, "History"),
                                                    std::make_pair(3, "Art"),
                                                    std::make_pair(4, "Chemistry"),
                                                    std::make_pair(5, "Physics"),
                                                    std::make_pair(6, "gym")};
std::string Teacher::occupation = "teacher";
Teacher::Teacher(const std::string &first_name, const std::string &last_name, double salary) :
    Worker(first_name, last_name, salary)
{
    set_class();
}
Teacher::~Teacher() {}
void Teacher::show_occupation() const
{
    std::cout << "occupation: " << occupation << std::endl;
}
const std::string & Teacher::get_occupation() const
{
    return occupation;
}
bool is_correct_class_num(int class_num)
{
    if (class_num >= 0 && class_num<= 6)
        return true;
    return false;
}
void Teacher::set_class()
{
    std::cout << "Enter what class does " << this->first_name() << " " << this->last_name() << " teach?" << std::endl;
    for(auto pair_ : classes)
    {
        std::cout << pair_.second << " - " << pair_.first << std::endl;
    }
    while(!(std::cin >> class_) || !is_correct_class_num(class_))
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Try again to enter a class number: ";
    }
}
void Teacher::show_job() const
{
    show_occupation();
    std::cout << "Salary: " << get_salary() << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string Admin::occupation = "admin";

Admin::Admin(const std::string & first_name, const std::string & last_name, double salary) :
    Worker(first_name, last_name, salary)
{
    set_position();
}
Admin::~Admin() {}
void Admin::show_occupation() const
{
    std::cout << "occupation: " << occupation << std::endl;
}
const std::string & Admin::get_occupation() const
{
    return occupation;
}
void Admin::set_position()
{
    std::cout << "Enter what position has " << first_name() << " " << last_name() << " got?" << std::endl;
    while(!(std::cin >> position_))
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Try again to enter a position number: ";
    }
}
void Admin::show_job() const
{
    show_occupation();
    std::cout << "Salary: " << get_salary() << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string Student::occupation = "student";

Student::Student(const std::string &first_name, const std::string &last_name) :
    Person(first_name, last_name) {}
Student::~Student() {}
void Student::show_occupation() const
{
    std::cout << "occupation: " << occupation << std::endl;
}
void Student::set_jornal()
{
    int class_;
    int grade_;
    std::cout << "what classes has this student? enter a numbers, q to quit" << std::endl;
    std::cout << "0 - Maths, 1 - English, 2 - History, 3 - Art, 4 - Chemistry, 5 - Physics, 6 - gym.";
    while(std::cin >> class_)
    {
        std::cin.get();
        std::cout << "Enter a grade for " << classes[class_].second << " : ";
        while(!(std::cin >> grade_))
        {
            std::cin.ignore(100, '\n');
            std::cout << "Error, try to enter a grade for " << classes[class_].second << " again: ";
        }
        jornal.push_back({class_, grade_});
    }
    std::cin.ignore(100, '\n');
}

void Student::show_jornal() const
{
    //first class
    //second grade
    std::cout << first_name() << " " << last_name() << " grades:" << std::endl;
    for(auto pair_ : jornal)
    {
        std::cout << classes[pair_.first].second << " - " << pair_.second << std::endl;
    }
}
const std::string & Student::get_occupation() const
{
    return occupation;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
School::School(const std::string &school_name) :
    school_name_(school_name) {}
School::~School() {}
void School::add_admin()
{
    admins_.emplace_back(Admin());

    admins_[teachers_.size() - 1].change_name();

    admins_[teachers_.size() - 1].set_position();
}
void School::add_teacher()
{
    teachers_.emplace_back(Teacher());

    teachers_[teachers_.size() - 1].change_name();

    teachers_[teachers_.size() - 1].set_class();
}
void School::add_student()
{
    students_.emplace_back(Student());

    students_[students_.size() - 1].change_name();

    students_[students_.size() - 1].set_jornal();
}
std::string School::get_school_name() const
{
    return school_name_;
}
int School::get_quantity_of_admins() const
{
    return admins_.size();
}
int School::get_quantity_of_teachers() const
{
    return teachers_.size();
}
int School::get_quantity_of_workers() const
{
    return get_quantity_of_teachers() + get_quantity_of_admins();
}
int School::get_quantity_of_students() const
{
    return students_.size();
}
void School::show() const
{
    std::cout << "School name: " << get_school_name() << std::endl;
    std::cout << "Quantity of all workers: " << get_quantity_of_workers() << std::endl;
    std::cout << "Teachers: " << get_quantity_of_teachers() << std::endl;
    std::cout << "Admins: " << get_quantity_of_admins() << std::endl;
    std::cout << "Students: " << get_quantity_of_students() << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
