<<<<<<< Updated upstream
#include <iostream>
=======
#include <iostream> //Louise
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
#include <random>
#include <ctime>
>>>>>>> Stashed changes
using namespace std;

int main() {
    cout << "Womp womp womp";
    cout << "ggs cooked";


    return 0;
<<<<<<< Updated upstream
}
=======

}
void menu()
{
    cout << "TASK-TRACK-RPG.\n";
    cout << "1.  View Your Stats.\n";
	cout << "2.  View Tasks Completed.\n";
	cout << "3.  Visit the Shop.\n";
    cout << "4.  Create a New Task.\n";
    cout << "5.  Visit the Casino\n";
    cout << "6.  Attempt a Task\n";
    cout << "7.  Exit the Program.\n";
    cout << "Enter your choice(1-7):  ";
}
int getChoice()
{
    string number;
    getline(cin, number);
    while (true)
    {
        bool valid = 1;
        if (sizeof(number) > 1)
        {
            valid = 0;
        }
        else if (!(number[0] >= '1' && number[0] <= '7'))
        {
            valid = 0;
        }
        if (valid == 1)
        {
            return stoi(number);
        }
        else
        {
            cout << "Invalid input... This must be an integer value between 1 and 7.\n";
            getline(cin, number);
        }

    }
}
void viewStats(int numStats, int attributes[])
{
    cout << "STATS.\n";
    for (int i = 0; i < numStats; i++)
    {
        cout << "Attribute " << i << ": " << attributes[i] << endl; // names for attributes will be set accordingly
    }

}
void viewCompleted()
{
    cout << "viewcompleted\n";
    /* pseudocode/ideas
        create a for loop for every element in the vector AllTasks to print the completed tasks
    */
}
void shop()
{
    cout << "shop\n";
    /* pseudocode/ideas
        this function will:
            1. take arguents such as money that the character has, and the attribute[] array
            2. display a shop of various items
            3. asks user what to buy or exit the shop
            4. if user wants to buy an item
                -check if they have enough currency (complain it if not)
                -ask if user is sure if they want to purchase it
                -upgrade certain attributes when an item is successfully bought
            5. Either do not display or mark items that are already bought in some way
    */
}
void createTask()
{
    cout << "createtask\n";
    /* pseudocode/ideas
        cin << an input
        print out what the user typed and ask if that is what they want to enter
        then, the user gives the task a numerical difficulty (probably 1-10 or 1-100)
    */
}
void casino()
{
    cout << "casino\n";
    /* pseudocode/ideas
        this function should take money as an argument, then we can implement a 
        game based on randomness (random number guessing, etc.)
    */
}
void doTask()
{
    cout << "dotask\n";
    /* pseudocode/ideas
        this function is the core of the program, so these are some very rough ideas:
            1. print out the contents of the string vector AllTasks in a menu (this can be its own function)
            2. get the user to choose a task (if there are no tasks, then the user must make a new task)
            3. we CAN track time elapsed using the clock function https://cplusplus.com/reference/ctime/clock/ 
            4. Depending on how we determine success/failure/partial success, we can modify attributes or other values
                - failure would lose money and/or debuff some attributes
                - success would gain money and/or buff attributes

    */
}
>>>>>>> Stashed changes
