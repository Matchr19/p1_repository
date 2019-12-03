#include <iostream>
#include <string>
#include <vector>

class player
{
    //Attributes
    std::string name;
    int health;
    int xp;
    //Methods
    void talk(std::string);
    bool is_dead();


};

class Account
{
//Attributes
std::string name;
double balance;


//Methods
bool withDraw(double);
bool deposit(double);


};


int main()
{
    Account Jacob_account;
    Account Far_account;


    player Jacob;
    player Hero;

    player players[] {Jacob, Hero};


    std::vector<player> player_vec{Jacob};
    player_vec.push_back(Hero);

    player *enemy{};
    enemy = new player;

    delete enemy;

    return 0;
}