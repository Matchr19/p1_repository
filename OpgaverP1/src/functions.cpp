#include <iostream>
#include <vector>

double values[] {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1, 0.50};
int antal[11] {};

void calculate(double penge)
{
    
    
    for(int i=0; i<11; i++)
    {
        antal[i] = penge/values[i];
        penge -= values[i]*antal[i];
    }
    
    
}



int main()
{
    double penge {};
    std::cout << "Indtast hvor mange penge du har: ";
    std::cin >> penge;
    calculate(penge);

    std::cout << "Det svarer til at du har: \n";
    for(int i=0; i<11; i++)
    {
        std::cout << antal[i] << " stk. " << values[i] << "kr." << std::endl;
    }


    
    return 0;
} 


