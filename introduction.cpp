#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <time.h>
using namespace std;

void viewStats(int numStats, int attributes[], int potato, string attNames[]);
void viewTasks(vector<string> &AllTasks, vector<int> &diff, vector<int> &status);
void displayShop(int &potato);
void createTask(string &newtask, vector<string> &AllTasks, vector<int> &diff, vector<int> &status);
void casino();
void menu();
void doTask(vector<string> &AllTasks, vector<int> &diff, vector<int> &status, int &potato);
void adventure();
int intCheck(string &input, int min, int max); 
int ynCheck(string &input);// these definitions are subject to change, function types or arguments will probably change

int MAX_STAT = 100;

int main() // (view stats, view completed tasks, [casino], shop, make a new task, do a task)
{
    const int ATT = 3; // these can be changed if want
    int choice, potato = 0, attributes[ATT] = {0};
    string attNames[ATT] = {"ATK", "DEF", "HP"};
    vector<string> AllTasks; 
    vector<int> diff; // AllTasks[0] will correlate with difficulty of the task diff[0] and completed[0]
    vector<int> status;
    string newTask = "";
    do
	{
		menu();
        string menuNumber;
        getline(cin, menuNumber);
        choice = intCheck(menuNumber, 1, 8);
		switch (choice)
		{
		case 1: viewStats(ATT, attributes, potato, attNames);
			break;

		case 2: viewTasks(AllTasks, diff, status);
			break;

		case 3: displayShop(potato);
			break;

		case 4: createTask(newTask, AllTasks, diff, status);
			break;

        case 5: casino();
            break;

        case 6: doTask(AllTasks, diff, status, potato);
            break;

        case 7: adventure();
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
    cout << "1.  View Your Statas.\n";
	cout << "2.  View All Tasks.\n";
	cout << "3.  Visit the Shop.\n";
    cout << "4.  Create a New Task.\n";
    cout << "5.  Visit the Casino\n";
    cout << "6.  Attempt a Task\n";
    cout << "7.  Start an Adventure\n";
    cout << "8.  Exit the game.\n";
    cout << "Enter your choice(1-8):  ";
}
int intCheck(string &input, int min, int max)
{
    bool valid;
    do
    {
        valid = 1;
        for (int i = 0; i < input.size(); i++)
        {
            if (!(input[i] >= '0' && input[i] <= '9'))
            {
                valid = 0;
            }
        }
        if (valid == 1 && !(stoi(input) >= min && stoi(input) <= max))
        {
            valid = 0;
        }
        if (valid == 1)
        {
            return stoi(input);
        }
        else
        {
            cout << "Invalid input... Enter this value again. (" << min << "-" << max << ")\n";
            getline(cin, input);
        }
    
    } while (!valid);
}
int ynCheck(string &input)
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
    cout << "\nSTATS.\n";
    for (int i = 0; i < numStats; i++)
    {
        cout << attNames[i] << ": " << attributes[i] << endl; // names for attributes will be set accordingly
    }
    cout << "Potatoes: " << potato << endl;

}
void viewTasks(vector<string> &AllTasks, vector<int> &diff, vector<int> &status)
{
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

void displayShop(int &potato)
{
    struct item
    {
        vector<string>name;
        vector<string>description;
        vector<int>cost;
    };

    item weapon;
    weapon.name = {"Lapis", "Mecha Penn", "Penn", "Founder's Pen"};
    weapon.description = {
        "Everyone starts with a trusty weapon. Not you though. You get a wooden pencil :p\n",
        "It's just a pencil...A pencil made of metal... And it shoots graphite bullets...\n",
        "Not only does this damage a monster, it can also slow them down and make them weaker!\n",
        "The Founder's Pen was said to contain the oldest knowledge known to man.\
        Some people believe that it has existed moments after the universe was created.\n",
    };
    weapon.cost = {0, 100, 500, 1000};

    int weaponChoiceInt;
    string userChoice, weaponChoice;
    cout << "\nShop\n"
         << "Potatoes: " << potato << endl
         << "1. Weapons " << endl
         << "2. Armor " << endl
         << "3. Artifacts " << endl
         << "4. Potions/Consumables " << endl
         << "5. Back " << endl
         << "Pick (1-5): ";
    
    getline(cin, userChoice); cout << endl;

    if (userChoice == "1") {
        string userWeaponView, buyWeapon;
        for (int i = 1; i < weapon.name.size() + 1; i++) {
            cout << i << ") " << weapon.name[i-1] << endl; 
        }
        cout << "5) Back\n";
        cout << "Which weapon would you like to buy? "; getline(cin, userWeaponView); cout << endl;
        switch (intCheck(userWeaponView, 1, 5))
        {
        case 1:
            cout << weapon.name[0] << endl
                 << "Description: Everyone starts with a trusty weapon. Not you though. You get a wooden pencil :p\n"
                 << "Cost: Free!\n"
                 << "Buy (y/n)? ";
            getline(cin, buyWeapon); cout << endl;
            ynCheck(buyWeapon);
            if(buyWeapon == "y") {
                if(potato < weapon.cost[0]) {
                    cout << "You don't have enough money... womp womp\n";
                    break;
                }
                cout << "You now have " << weapon.name[0] << "!" << endl;
                potato -= weapon.cost[0];
                cout << "You now have: " << potato << " Potatoes";
            }

            break;
        
        case 2:
            cout << weapon.name[1] << endl
                 << "Description: It's just a pencil...A pencil made of metal... It also shoots graphite bullets hehe...\n"
                 << "Cost: 100 Potatoes\n"
                 << "Buy (y/n)? ";
            getline(cin, buyWeapon); cout << endl;
            ynCheck(buyWeapon);
            if(buyWeapon == "y") {
                if (potato < weapon.cost[1]) {
                    cout << "You don't have enough money... womp womp\n";
                    break;
                }
                cout << "You now have " << weapon.name[1] << "!" << endl;
                potato -= weapon.cost[1];
                cout << "You now have: " << potato << " Potatoes";
            }
            break;

        case 3:
            cout << weapon.name[2] << endl
                 << "Description: Not only does this damage a monster, it can also slow them down and make them weaker!\n"
                 << "Cost: 500 Potatoes\n"
                 << "Buy (y/n)? ";
            getline(cin, buyWeapon); cout << endl;
            ynCheck(buyWeapon);
            if(buyWeapon == "y") {
                if (potato < weapon.cost[2]) {
                    cout << "You don't have enough money... womp womp\n";
                    break;
                }
                cout << "You now have " << weapon.name[2] << "!" << endl;
                potato -= weapon.cost[2];
                cout << "You now have: " << potato << " Potatoes";
            }
            break;

        case 4:
            cout << weapon.name[3] << endl
                 << "Description: The Founder's Pen was said to contain the oldest knowledge known to man.\n" 
                 << "Some people believe that it has existed moments after the universe was created.\n"
                 << "Cost: 1000 Potatoes\n"
                 << "Buy (y/n)? ";
            getline(cin, buyWeapon); cout << endl;
            ynCheck(buyWeapon);
            if(buyWeapon == "y") {
                if (potato < weapon.cost[3]) {
                    cout << "You don't have enough money... womp womp\n";
                    break;
                }
                cout << "You now have " << weapon.name[3] << "!" << endl;
                potato -= weapon.cost[3];
                cout << "You now have: " << potato << " Potatoes\n";
            }
            break;  

        default:
            break;
        } 

    }

}

void createTask(string &newtask, vector<string> &AllTasks, vector<int> &diff, vector<int> &status)
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
        if (AllTasks.size() !=0)
        {
            for (int i = 0 ; i < AllTasks.size(); i++)
            {
                if (newtask == AllTasks[i])
                    {
                        sure = 0;
                        cout << "This task already exists.";
                    }
            }
        }
    } while (!sure);
    AllTasks.push_back(newtask);
    string assignDiff;
    cout << "Please assign a difficulty to this task. (1-100)\n";
    getline(cin, assignDiff);
    intCheck(assignDiff, 1, MAX_STAT);
    diff.push_back(intCheck(assignDiff, 1, MAX_STAT));
    status.push_back(0); // 0 denotes an unfinished task, 1 a finished task, 2 a failed task
}
void casino()
{
    cout << "\ncasino\n";
    /* pseudocode/ideas
        this function should take money as an argument, then we can implement a 
        game based on randomness (random number guessing, etc.)
    */
}
void doTask(vector<string> &AllTasks, vector<int> &diff, vector<int> &status, int &potato)
{
    if (AllTasks.size() == 0)
    {
        cout << "There are no tasks to attempt. Please create a new task";
        return;
    }
    string taskInput, statusInput;
    bool valid = 0, redo = 0;
    do
    {
        viewTasks(AllTasks, diff, status);
        cout << "\nEnter the name of a task to attempt:\n";
        getline(cin, taskInput);
        for (int i = 0; i < AllTasks.size(); i++)
        {
            if(taskInput == AllTasks[i])
            {
                valid = 1;
                if(status[i] == 1)
                    redo = 1;
            }
        }
        if(redo)
        {
            string yn;
            cout << "This task has already been completed. Would you like to re-do this task? (y/n)\n";
            getline(cin, yn);
            ynCheck(yn);
            if (yn[0] == 'N' || yn[0] == 'n')
                valid = 0;
        }
        if(!valid && !redo)
            cout << "This is not in the task list. Please check your spelling and enter the task name again.\n";
    } while(!valid);
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
        double seconds = (clock() - time)/double(CLOCKS_PER_SEC);
        cout << "Nice job! You completed the task " << taskInput << " in " << seconds << " seconds!";
        for (int i = 0; i < AllTasks.size(); i++)
        {
            if(taskInput == AllTasks[i])
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
            if(taskInput == AllTasks[i])
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
}
    /* pseudocode/ideas
        this function is the core of the program, so these are some very rough ideas:
            1. print out the contents of the string vector AllTasks in a menu (this can be its own function) done
            2. get the user to choose a task (if there are no tasks, then the user must make a new task) done
            3. we CAN track time elapsed using the clock function https://cplusplus.com/reference/ctime/clock/ done
            4. Depending on how we determine success/failure/ we can modify attributes or other values done
                - failure would lose money and/or debuff some attributes
                - success would gain money and/or buff attributes

    */
void adventure()
{
    cout << "adventure";
}