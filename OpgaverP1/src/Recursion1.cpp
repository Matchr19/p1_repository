#include <iostream>



int exponentialIt(int a, int x)
{

int result {1};

for(;x>0;x--)
{
    result *= a;
}


return result;
}

int exponentRec(int a, int x)
{
    int result {};
    if(x == 0)
    {
        return 1;
    }
    else
    {
     return a*exponentRec(a, x-1);

    }
    
}


int main() 
{   

    char c {'c'};
    int a {}; int x {};
    do
    {
    std::cout << "a: "; std::cin >> a;
    std::cout << "\nx: "; std::cin >> x;
    std::cout << "\nExponentialIn: " << exponentialIt(a, x) << std::endl;
    std::cout << "\nExponentialRec: " << exponentRec(a, x) << std::endl;

    std::cout << "\nAgain? "; std::cin >> c;
    } while(c != 'n');
    return 0;
}