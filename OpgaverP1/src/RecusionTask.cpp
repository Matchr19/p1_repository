#include <iostream>


int udregner(int n)
{
    
    for(int i = 1; i<=n; i++)
    {
        n *= (n-i);
    }

    return n;

}




int main()
{
    int n {};
    std::cout << "n: "; std::cin >> n;

    std::cout << "\nn! = " << udregner(n) << std::endl;

    return 0;
}