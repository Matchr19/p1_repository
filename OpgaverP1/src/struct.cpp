#include <iostream>
#include <string>

struct person
{
    std::string name;
    int year;
    float height;

    int getAge(int currentYear)
    {
        return currentYear - year;
    }

};



int main()
{

    person p;

    p.name = "Jacob";
    p.year = 2000;
    p.height = 1.87;

    std::cout << "Person data:\nName: " << p.name << "\nYear: " << p.year << "\nAge: " << p.getAge(2019) << "\nHeight: " << p.height << std::endl;
    return 0;
}