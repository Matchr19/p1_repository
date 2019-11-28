#include <iostream>
#include <vector>
template <typename T>

double output(const std::vector<T>& tal)
{
    double average {};
    int total {};
    for(int i=0; i<tal.size(); i++)
    {
        total += tal[i];
    }
    average = total / tal.size();
    return average;
}

int main()
{
    int size {};
    int input {};
    std::vector<double> tal;
    std::cout << "Indtast nogle tal, afslut med enter:  ";
    while (input != 10)
    {
    std::cin >> input;
    tal.push_back(input);
    } 
    
    
    std::cout << "Gennemsnittet af de tal er: " << output(tal) << std::endl;
    
    std::cout << std::endl;




    return 0;
}