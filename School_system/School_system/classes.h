#ifndef CLASSES_H_
#define CLASSES_H_

#include <string>
#include <array>
#include <vector>

class Person
{
private:
    std::string first_name_;
    std::string last_name_;
    std::string enter_name() const;
public:
    Person(const std::string &first_name = "name", const std::string &last_name = "sername");
    virtual ~Person();
    void change_name();
    const std::string & first_name() const;
    const std::string & last_name() const;
    virtual void show_occupation() const = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Worker: public Person
{
private:
    double salary_;
public:
    virtual void show_job() const = 0;
    double get_salary() const;
    Worker(std::string first_name = "name", std::string last_name = "last_name", double salary = 100.0);
    virtual ~Worker();
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern const std::array<std::pair<int, std::string>, 7> classes;

class Teacher: public Worker
{
private:
    static std::string occupation;
    int class_;
public:
    Teacher(const std::string &first_name = "name", const std::string &last_name = "last_name", double salary = 100.0);
    ~Teacher();
    friend bool is_correct_class_num(int class_num);
    void show_occupation() const;
    const std::string & get_occupation() const;
    void set_class();
    void show_job() const;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Admin: public Worker
{
private:
    static std::string occupation;
    int position_;
public:
    Admin(const std::string &first_name = "name", const std::string &last_name = "last_name", double salary = 120.0);
    ~Admin();
    void show_occupation() const;
    void set_position();
    const std::string & get_occupation() const;
    void show_job() const;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Student: public Person
{
private:
    static std::string occupation;
    std::vector<std::pair<int, int>> jornal;     //first class, second grade
public:
    Student(const std::string &first_name_ = "name", const std::string &last_name_ = "last_name");
    ~Student();
    void show_occupation() const;
    void set_jornal();
    void show_jornal() const;
    const std::string & get_occupation() const;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// name of the school, how many people work in the school, how many students,
///  how many people, how many administrative people.
///  I should also be able to see the list of all the students with their names,
/// and for each person I should be able to see their name, salary and occupation
class School
{
private:
    std::string school_name_;
    std::vector<Admin> admins_; // std::unordered_map
    std::vector<Teacher> teachers_;
    std::vector<Student> students_;
public:
    School(const std::string &school_name);
    ~School();
    void add_admin();
    void add_teacher();
    void add_student();
    std::string get_school_name() const;
    int get_quantity_of_admins() const;
    int get_quantity_of_teachers() const;
    int get_quantity_of_workers() const;
    int get_quantity_of_students() const;
    void show() const;
};

#endif
