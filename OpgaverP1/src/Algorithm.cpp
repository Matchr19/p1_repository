#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

char getRandomCharacter()
{
    int randomNumber = rand() % 27;

    if(randomNumber == 0)
    {
        randomNumber = 32;
    }
    else
    {
        randomNumber = randomNumber + 64;
    }
    

    return randomNumber;
}


string initString(int size)
{
    string str = {""};

    for(int i = 0; i < size; i++)
    {
        str = str + getRandomCharacter();
    }

    return str;

}


int calculateScore(string guess, string target)
{
    int score {};
    

    for(int i = 0; i<target.length(); i++)
    {
        if(guess[i] == target[i])
        {
            score++;
        }
    }
    return score;
}

string mutate(string mutString)
{
    for(int i = 0; i < mutString.length(); i++)
    {
        if((rand() % 20) == 0)
        {
            mutString[i] = getRandomCharacter();
        }

    }

    return mutString;
}


int main()
{
    srand(time(NULL));
    cout << "Velkommen stranger, jeg kan gætte sætninger som du bestemmer." << endl << endl;
    cout << "Indtast nu hvad jeg skal finde frem til, brug kun store bogstaver, små er for de svage, undgå også Æ, Ø & Å: ";
    string Target = {""};
    getline(cin, Target);
    cout << endl;
    string generationString = initString(Target.length());

    string currentString = {generationString};

    int score {calculateScore(currentString, Target)};

    int x {};
    cout << "Generation " << x << ": " << currentString << ", Score: " << score << endl;

    while(score < Target.length())
    {
       for(int i = 0; i<100; i++)
       {
           string newCopy = generationString;
           newCopy = mutate(newCopy);
            int copyScore = calculateScore(newCopy, Target);
            if(copyScore > score)
            {
                currentString = newCopy;
                score = copyScore;
            }
            
       }
       generationString = currentString;
        cout << "Generation " << x++ << ": " << generationString << ", Score " << score << endl;
    }
    if(x < 100)
    {
        cout << "Pfff, det var jo nemt, det tog kun " << x <<  " forsøg, kom med noget sværere" << endl;
    }
    else if (x > 1000)
    {
        cout << "Se den var værre, " << x << " forsøg, men jeg klarede den" << endl;
    }
    else 
    {
        cout << "Nemt nemt nemt, " << x << " forsøg" << endl;
    }

    return 0;
}