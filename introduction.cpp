#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace this_thread;
using namespace chrono;

struct item
{
    vector<string>name;
    vector<string>description;
    vector<int>cost;
    vector<int>atk, hp , def;
};

struct entity
{
    vector<string>name;
    vector<int>atk, hp, price;
};

void viewStats(int numStats, int attributes[], int potato, string attNames[]);
void viewTasks(vector<string>& AllTasks, vector<int>& diff, vector<int>& status);
void displayShop(int& potato, int attributes[], int numStats);
void buy(int& potato, int userChoice, item itemType, int attributes[], int numStats);
void createTask(string& newtask, vector<string>& AllTasks, vector<int>& diff, vector<int>& status);
void casino(int &potato);
void playSlotMachine(int &potato);
void playDiceRoll(int &potato);
void menu();
void displaySlots(int slot1, int slot2, int slot3);
/*vector<string> */void inventory(string& item); // just putting as void to avoid errors
void doTask(vector<string>& AllTasks, vector<int>& diff, vector<int>& status, int& potato);
void adventure(int attributes[], int &potato);
int intCheck(string& input, int min, int max);
int ynCheck(string& input);// these definitions are subject to change, function types or arguments will probably change

int MAX_STAT = 1000;

int main() // (view stats, view completed tasks, [casino], shop, make a new task, do a task)
{
    const int numStats = 3; // these can be changed if want
    int choice, potato = 1000, attributes[numStats] = {0, 0, 100};
    string attNames[numStats] = { "ATK", "DEF", "HP" };
    vector<string> AllTasks, items;
    vector<int> diff; // AllTasks[0] will correlate with difficulty of the task diff[0] and completed[0]
    vector<int> status;
    string newTask = "";
    do
    {
        system("cls");
        menu();
        string menuNumber;
        getline(cin, menuNumber);
        choice = intCheck(menuNumber, 1, 9);
        switch (choice)
        {
        case 1: viewStats(numStats, attributes, potato, attNames);
            break;

        case 2: viewTasks(AllTasks, diff, status);
            system("pause");
            break;

        case 3: displayShop(potato, attributes, numStats);
            break;

        case 4: createTask(newTask, AllTasks, diff, status);
            break;

        case 5: casino(potato);
            break;

        case 6: doTask(AllTasks, diff, status, potato);
            break;

        case 7: adventure(attributes, potato);
            break;

        default:
            break;
        }

    } while (choice != 8);
    cout << "Thanks for playing!";
    return 0;

}
void menu()
{
    cout << "\nTASK-TRACK-RPG.\n";
    cout << "1.  View Your Stats.\n";
    cout << "2.  View All Tasks.\n";
    cout << "3.  Visit the Shop.\n";
    cout << "4.  Create a New Task.\n";
    cout << "5.  Visit the Casino\n";
    cout << "6.  Attempt a Task\n";
    cout << "7.  Start an Adventure\n";
    cout << "8.  Exit the game.\n";
    cout << "Enter your choice(1-8): ";
}
int intCheck(string& input, int min, int max)
{
    bool valid;
    do
    {
        valid = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (valid && !(stoi(input) >= min && stoi(input) < max))
        {
            valid = 0;
        }
        if (valid == 1)
        {
            return stoi(input);
        }
        else
        {
            cout << "Invalid input... Enter this value again. (" << min << "-" << max - 1 << ")\n";
            getline(cin, input);
        }

    } while (!valid);
}
int ynCheck(string& input)
{
    while (true)
    {
        if (!(input.size() == 1))
        {
            cout << "Invalid input, enter this again. (y/n) \n";
            getline(cin, input);
        }
        else if (!(input[0] == 'y' || input[0] == 'Y' || input[0] == 'n' || input[0] == 'N'))
        {
            cout << "Invalid input, enter this again. (y/n) \n";
            getline(cin, input);
        }
        else
        {
            return 0;
        }
    }
}
void viewStats(int numStats, int attributes[], int potato, string attNames[])
{
    system("cls");
    cout << "\nSTATS.\n";
    for (int i = 0; i < numStats; i++)
    {
        cout << attNames[i] << ": " << attributes[i] << endl; // names for attributes will be set accordingly
    }
    cout << "Potatoes: " << potato << endl << endl;
    system("pause");

}
void viewTasks(vector<string>& AllTasks, vector<int>& diff, vector<int>& status)
{
    system("cls");
    if (AllTasks.size() == 0)
    {
        cout << "\nThere are no tasks available. Please create a task.\n";
        return;
    }
    cout << endl << left << setw(30) << "Task" << setw(15) << "Difficulty" << setw(10) << "Status" << endl;
    for (int i = 0; i < AllTasks.size(); i++)
    {
        string statusAsText;
        switch (status[i])
        {
        case 0: statusAsText = "Not Attempted";
            break;
        case 1: statusAsText = "Completed";
            break;
        case 2: statusAsText = "Attempted";
            break;
        }
        cout << left << setw(30) << AllTasks[i] << setw(15) << diff[i] << setw(10) << statusAsText << endl;
    }
}

/*vector<string> */void inventory(string& items) {
    item weapon, armor, artifact;
    vector<string>equipped;
    weapon.name = { "Lapis", "Mecha Penn", "Penn", "Founder's Pen" };
    weapon.description = {
        "Everyone starts with a trusty weapon. Not you though. You get a wooden pencil :p\n",
        "It's just a pencil...A pencil made of metal... And it shoots graphite bullets...\n",
        "Not only does this damage a monster, it can also slow them down and make them weaker!\n",
        "The Founder's Pen was said to contain the oldest knowledge known to man.\
        Some people believe that it has existed moments after the universe was created.\n",
    };
    weapon.atk = { 0, 30, 100, 1000 };

    for (int i = 0; i < weapon.name.size(); i++) {
        if (weapon.name[i] == items) {
            equipped.push_back(weapon.name[i]);
        }
    }

    artifact.name = { "Sharpener", "Reizer", "Knoife", "Just a line\n" };
    artifact.description = {
        "When things get dull, you gotta make a point.\n",
        "There's not enough EDGE.\n",
        "They said never bring a gun to a knife fight... right?\n",
        "It's just a line. Nothing more to it.\n"
    };
}


void displayShop(int& potato, int attributes[], int numStats)
{
    item weapon;

    weapon.name = { "Lapis", "Mecha Penn", "Penn", "Founder's Pen" };
    weapon.description = {
        "Everyone starts with a trusty weapon. Not you though. You get a wooden pencil :p\nDoesn't do anything special. It's just to attack\n",
        "It's just a pencil...A pencil made of metal... And it shoots graphite bullets...\nIncreases ATK by 30.\n",
        "Not only does this damage a monster, it can also slow them down and make them weaker!\nIncreases ATK by 100 and weakens the attack power of the monster.\n",
        "The Founder's Pen was said to contain the oldest knowledge known to man.\
        Some people believe that it has existed moments after the universe was created.\nATK increased by 1000. Monster will be stunned for 3 turns.\n",
    };
    weapon.cost = { 0, 100, 200, 100 };
    weapon.atk = {20, 40, 100, 1000}; weapon.def = {0,0,0,0}; weapon.hp = {0,0,0,0};

    item armor;
    armor.name = { "Pajamas", "Tin Can", "Steel Plate", "Paper"};
    armor.description = {"Wear this to battle to have maximum comfort at the price of having little to no defense.\n+1 HP",
                         "It ain't much but it's honest work.\n+50 HP",
                         "Very basic type of armor. Shiny and dependable!\n+100 HP",
                         "The strongest material to have ever existed. It will protect you from fatal blows!\n+1000 HP"};
    armor.cost = {20, 100, 500, 1000};
    armor.atk = { 0,0,0,0 }; armor.def = { 0,0,0,0 };  armor.hp = {1, 50, 100, 1000};

    item artifact;
    artifact.name = { "Sharpener", "Reizer", "Knoife", "Just a line" };
    artifact.description = { "When things get dull, you gotta make a point.\nAdds 100 ATK",
                            "There's not enough EDGE.\nAdds 50 ATK",
                            "They said never bring a gun to a knife fight... right?\nAdds 200 ATK",
                            "It's just a line. Nothing more to it.\nAdds 100 HP" };
    artifact.cost = { 50, 200, 500, 500 }; 
    artifact.atk = { 100,50,200,0 }; artifact.def = { 0,0,0,0 }; artifact.hp = { 0,0,0,100 };

    item potion;
    potion.name = { "Eraser" };
    potion.description = { "Cleanses impurities and heals injuries sustained from a monster's attack.\nHeals 30% of player's Max HP" };
    potion.cost = { 100 };
    potion.atk = { 0,0,0,0 }; potion.def = { 0,0,0,0 }; potion.hp = { 0,0,0,0 };
    string userChoice, weaponChoice;
    system("cls");
    cout << "\nShop\n"
        << "Potatoes: " << potato << endl
        << "1. Weapons " << endl
        << "2. Armor " << endl
        << "3. Artifacts " << endl
        << "4. Potions/Consumables " << endl
        << "5. Back " << endl
        << "Pick (1-5): ";

    getline(cin, userChoice); cout << endl;
    int shopChoice = intCheck(userChoice, 1, 6); system("cls");
    switch (shopChoice)
    {
    case 1: buy(potato, shopChoice, weapon, attributes, numStats);
        break;
    case 2: buy(potato, shopChoice, armor, attributes, numStats);
        break;
    case 3: buy(potato, shopChoice, artifact, attributes, numStats);
        break;
    case 4: buy(potato, shopChoice, potion, attributes, numStats);
        break;
    default:
        break;
    }
}

void buy(int& potato, int userChoice, item itemType, int attributes[], int numStats)
{
    for (int i = 1; i < itemType.name.size() + 1; i++) {
        cout << i << ") " << itemType.name[i - 1] << endl;
    }
    cout << "5) Back\n";
    string userItemView, buyItem;
    cout << "Which weapon would you like to buy? "; getline(cin, userItemView); cout << endl; system("cls");
    int userItemChoice = intCheck(userItemView, 1, 6);
    for (int i = 0; i < 5; i++)
    {
        if ((userItemChoice) == i + 1)
        {
            cout << itemType.atk[i] << endl;
            cout << itemType.name[i] << endl
                << itemType.description[i] << endl
                << "Cost: " << itemType.cost[i] << " Potatoes." << endl
                << "Buy (y/n)?" << endl;
            getline(cin, buyItem);
            ynCheck(buyItem);
            if (buyItem == "y") {
                if (potato < itemType.cost[i]) {
                    cout << "You don't have enough money... womp womp\n";
                    system("\npause");
                    break;
                }
                cout << "You now have " << itemType.name[i] << "!" << endl;
                potato -= itemType.cost[i];
                cout << "You now have: " << potato << " Potatoes\n";
                if (itemType.atk[i] != 0) attributes[0] += itemType.atk[i];
                if (itemType.def[i] != 0) attributes[1] += itemType.def[i];
                if (itemType.hp[i] != 0) attributes[2] += itemType.hp[i];// attribute 0 = atk, 1 = hp, 2 = def
                system("\n\npause");
            }
        }
        else if (userItemChoice == 5) 
        {
            displayShop(potato, attributes, numStats);
            break;
        }
    }
}

void createTask(string& newtask, vector<string>& AllTasks, vector<int>& diff, vector<int>& status)
{
    bool sure = 0;
    do
    {
        cout << "\nPlease enter a new task.\n";
        getline(cin, newtask);
        cout << "\nYou entered: " << newtask << endl;
        string yn;
        cout << "\nPlease confirm that this is what you wanted to enter. (y/n): ";
        getline(cin, yn);
        ynCheck(yn);
        if (yn[0] == 'Y' || yn[0] == 'y')
            sure = 1;
        if (AllTasks.size() != 0)
        {
            for (int i = 0; i < AllTasks.size(); i++)
            {
                if (newtask == AllTasks[i])
                {
                    sure = 0;
                    cout << "This task already exists.";
                    sleep_for(seconds(1));
                }
            }
        }
    } while (!sure);
    AllTasks.push_back(newtask);
    string assignDiff;
    cout << "Please assign a difficulty to this task. (1-100)\n";
    getline(cin, assignDiff);
    intCheck(assignDiff, 1, MAX_STAT + 1);
    diff.push_back(intCheck(assignDiff, 1, MAX_STAT + 1));
    status.push_back(0); // 0 denotes an unfinished task, 1 a finished task, 2 a failed task
    cout << "The task has been created.";
    sleep_for(seconds(1));
}

void casino(int &potato){
    int choice;
    do{
        cout<<"\n---Casino--\n";
        cout<<"You have "<<potato<<" Potatoes.\n";
        cout<<"Choose a game to play:\n";
        cout<<"1. Slot Machine\n";
        cout<<"2. Dice Roll\n";
        cout<<"3. Exit Casino\n";
        cout<<"Enter your choice (1-3): ";
        string input;
        getline(cin, input);
        choice=intCheck(input, 1, 4); //validate input

        switch(choice){
            case 1:
                playSlotMachine(potato); //to play slot machine
                break;
            case 2:
                playDiceRoll(potato); //to play dice roll game
                break;
            case 3:
                cout<<"Leaving the casino. Come gamble again!\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    } while(choice !=3);
}

//slot machine is implemented//
void playSlotMachine(int &potato)
{
    cout << "\n---casino---\n";
    string bet;
    int validBet;
    cout << "You have "<< potato <<" Potatoes.\n";
    cout << "Enter your bet: ";
    getline(cin, bet);

    validBet = intCheck(bet, 1, potato + 1);

    potato -= validBet; //subtract bet from total potatoes//

    //generating random slots//
    int slot1=rand()%10+1;
    int slot2=rand()%10+1;
    int slot3=rand()%10+1;

    displaySlots(slot1, slot2, slot3); //this will display the slots//

    if(slot1 == slot2 && slot2 == slot3){
        int winnings=slot1*10; //jacket pot reward//
        cout<<"JACKPOT! You win "<< winnings <<" Potatoes!\n";
        potato += winnings;
    } else if (slot1 == slot2 || slot2 == slot3 || slot1 == slot3){
        int winnings=(slot1+slot2+slot3)*2; //partial slot reward for match//
        cout<<"GOOD but not bad! You win "<< winnings <<" Potatoes!\n";
        potato += winnings;
    } else {
        cout<<"GET OUTTA HERE!!! You're broke! GAME OVER!!\n";
    }
    sleep_for(seconds(2));
}

//Dice roll game implemented here//
void playDiceRoll(int &potato){
    string bet, playerGuess;
    int validBet, validGuess;
    cout<<"\n---Dice Roll---\n";
    cout<<"You have "<< potato <<" Potatoes.\n";
    cout<<"Enter your bet: ";
    getline(cin, bet);

    validBet = intCheck(bet, 1, potato + 1);

    cout<<"Guess the dice roll (1-6): ";
    getline(cin, playerGuess);

    validGuess = intCheck(playerGuess, 1, 7);

    potato -= validBet; //deduct bet from total potatoes//

    int diceRoll=rand()%6+1; //generate dice roll//
    cout<<"The dice rolls a "<<diceRoll<<".\n";

    if (validGuess==diceRoll){
        int winnings=validBet*6; //correct guess reward//
        cout<<"You guess correctly! You win "<<winnings<<" Potatoes!\n";
        potato += winnings;
    } else{
        cout<<"Sorry, better luck next time!\n";
    }
    sleep_for(seconds(2));
}

//displays slot machine rsults//
void displaySlots(int slot1, int slot2, int slot3){
    cout<<"-------------------\n";
    cout<<"|   "<<slot1<<"   |   "<<slot2<<"   |   "<<slot3<<"   |\n";
    cout<<"-------------------\n";
} 

void doTask(vector<string>& AllTasks, vector<int>& diff, vector<int>& status, int& potato)
{
    if (AllTasks.size() == 0)
    {
        cout << "There are no tasks to attempt. Please create a new task";
        sleep_for(seconds(1));
        return;
    }
    string taskInput, statusInput;
    bool valid = 0, redo = 0;
    do
    {
        viewTasks(AllTasks, diff, status);
        sleep_for(seconds(1));
        cout << "\nEnter the name of a task to attempt:\n";
        getline(cin, taskInput);
        for (int i = 0; i < AllTasks.size(); i++)
        {
            if (taskInput == AllTasks[i])
            {
                valid = 1;
                if (status[i] == 1)
                    redo = 1;
            }
        }
        if (redo)
        {
            string yn;
            cout << "This task has already been completed. Would you like to re-do this task? (y/n)\n";
            getline(cin, yn);
            ynCheck(yn);
            if (yn[0] == 'N' || yn[0] == 'n')
                valid = 0;
        }
        if (!valid && !redo)
            cout << "This is not in the task list. Please check your spelling and enter the task name again.\n";
    } while (!valid);
    cout << "You selected " << taskInput << "\nPlease attempt the task and indicate if you succeeded or failed. (type fail/success)\n";
    clock_t time = clock();
    do
    {
        getline(cin, statusInput);
        if (!(statusInput == "fail" || statusInput == "Fail" || statusInput == "success" || statusInput == "Success"))
        {
            valid = 0;
            cout << "Please check your spelling and enter this input again. (fail/success)\n";
        }
        else
            valid = 1;
    } while (!valid);
    if (statusInput == "success" || statusInput == "Success")
    {
        double seconds = (clock() - time) / double(CLOCKS_PER_SEC);
        cout << "Nice job! You completed the task " << taskInput << " in " << seconds << " seconds!";
        for (int i = 0; i < AllTasks.size(); i++)
        {
            if (taskInput == AllTasks[i])
            {
                status[i] = 1;
                cout << "\nPotatoes gained for completing this task: " << diff[i];
                potato += diff[i];
            }
        }
    }
    else
    {
        for (int i = 0; i < AllTasks.size(); i++)
        {
            if (taskInput == AllTasks[i])
            {
                if (status[i] != 1)
                    status[i] = 2;
                if (potato <= diff[i] / 2)
                {
                    cout << "You have failed this task and now have 0 Potatoes. You can always try again later";
                    potato = 0;
                }
                else
                {
                    cout << "You have failed this task. Potatoes lost from failure: " << diff[i] / 2;
                    potato -= diff[i] / 2;
                }
            }
        }
    }
    sleep_for(seconds(2));
}

void adventure(int attributes[], int &potato) //Only need elements 0 and 2 for enemy
{
    system("cls");
    srand(time(NULL));
    entity enemy;
    string playerChoice;
    int playerAtk, playerDef, playerHp, playerChoiceInt;
    int enemyRandomizer;
    enemy.name  = {"Slime", "Ajemo", "Louish"}; 
    enemy.atk   = {10, 30, 50}; 
    enemy.hp    = {100, 500, 1000}; 
    enemy.price = {40, 100, 100};


    enemyRandomizer = rand() % 3;

    playerAtk = attributes[0]; playerDef = attributes[1]; playerHp = attributes[2];

    cout << "You encountered: " << enemy.name[enemyRandomizer] << '!' << endl;
    do
    {
        cout << "\nPlayer HP: " << playerHp << endl;
        cout << enemy.name[enemyRandomizer] << " HP: " << enemy.hp[enemyRandomizer];
        cout << "\n\nWhat do you want to do?\n\n";
        cout << "1) Attack\n" << "2) Items\n" << "3) Run\n\n";
        cout << "-> "; getline(cin, playerChoice); 
        playerChoiceInt = intCheck(playerChoice, 1, 4);

        if (playerChoiceInt == 1 || playerChoiceInt == 2)
        {
            system("cls");
            cout << "\n\nYou dealt " << playerAtk << " damage to " << enemy.name[enemyRandomizer] << "!" << endl<< endl;
            system("pause");
            if ((enemy.hp[enemyRandomizer] - playerAtk) > 0)
            {
                system("cls");
                enemy.hp[enemyRandomizer] -= playerAtk;              
                cout << "\n" << enemy.name[enemyRandomizer] << " retaliated and dealt " << enemy.atk[enemyRandomizer] << " damage!\n\n";
                system("pause");
                playerHp -= enemy.atk[enemyRandomizer];
                    if (playerHp > 0) {
                        system("cls");
                        continue;
                    } else {
                        system("cls");
                        cout << "\nYou have died :( Better luck next time!\n"; sleep_for(seconds(2));
                        cout << "\nYou also lost " << potato * .20 << " Potatoes :p\n"; sleep_for(seconds(2));
                        potato -= potato * .20;
                        break;
                    }
            } else {
                system("cls");
                cout << "\nYou won!\n\n"; system("pause");
                system("cls");
                cout << "\nYou also gained " << enemy.price[enemyRandomizer] <<  " Potatoes!\n\n"; system("pause");
                potato += enemy.price[enemyRandomizer];
                break;
            }
        }

    } while (playerChoiceInt != 3 && (enemy.hp[enemyRandomizer] > 0 && playerHp > 0)); 

    // cout << "\n\nGoing for an adventure eh?\n\n"; sleep_for(seconds(2));
    // system("cls");

    // cout << "Good luck!\n"; sleep_for(seconds(2)); system("cls");
    // cout << "Don't die"; sleep_for(seconds(1)); cout << '.'; sleep_for(seconds(1)); cout << '.'; sleep_for(seconds(1)); cout << '.';
    // cout << endl; sleep_for(seconds(3));
    // system("cls");
}