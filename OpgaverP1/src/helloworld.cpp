#include <iostream>

int main()
{
  

    int i {1};
int value1 {1};
int value2 {1};
int value3 {1};
std::cout << (value1 += i++, value2 += i++, value3 += i++) << std::endl;
    
    return 0;
}


