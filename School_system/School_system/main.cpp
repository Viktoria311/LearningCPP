#include <iostream>
#include "classes.h"


int main()
{
    School some_school {"The name of this school"};

    int choise;
    while(true)
    {
        std::cout << "Do you want to add a teacher - 1, an admin - 2 or a student - 3? q to quit ";
        while(std::cin >> choise)
        {
            std::cin.ignore(100, '\n');
            switch(choise)
            {
            case 1:
                some_school.add_teacher();
                break;
            case 2:
                some_school.add_admin();
                break;
            case 3:
                some_school.add_student();
                break;
            }
        }
        if (!std::cin)
            break;
    }
    some_school.show();

    return 0;
}
