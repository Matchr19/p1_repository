#include <iostream>
#include <vector>
#include <stdlib.h>



void generatevector(std::vector<int>& tal, int high)
{
    
    for(int i = 0; i<tal.size(); i++)
    {
        int nummer {};
        nummer = rand() % high;
        tal[i] = nummer;

    }
    std::cout << "\nFør: " << std::endl;
    for(int i = 0; i<tal.size(); i++)
        {
            std::cout  << tal[i] << ", ";
        }

}





void Sort(std::vector<int>& tal)
{
    int ien {};
    int ito {};
    for(int i = 0; i < tal.size()-1; i++)
    {
        

    for(int i = 0; i<tal.size()-1; i++)
    {
        if(tal[i] > tal[1+i])
        {
            ien = tal[i];
            ito = tal[1+i];

            tal[1+i] = ien;
            tal[i] = ito;
            std::cout << "\nBytter [" << i << " & " << i+1 << "] Som er: [" <<  tal[i+1] << " & " << tal[i] << "] ";
        }
    }

    
        
    }

    std::cout << "\nEfter: " << std::endl;
        for(int i = 0; i<tal.size(); i++)
        {
            std::cout  << tal[i] << ", ";
        }
    
}




int main()
{
    int randtal {};
    int high {};
    std::cout << "Antal tal i vektoren? "; std::cin >> randtal;
    std::cout << "\nHøjest mulige tal? "; std::cin >> high; 
    srand(time(NULL));
    std::vector<int> tal(randtal);
   generatevector(tal, high);
   
   Sort(tal);

std::cout << "\n" << std::endl;

    return 0;
    

}