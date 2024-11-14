#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
using namespace std;

void viewStats();
void viewCompleted();
void shop();
void createTask();
void menu();
int getChoice(); 

int main() // (view stats, view completed tasks, [casino], shop, make a new task)
{
    int choice;
    string newTask = "";
    	do
	{
		menu();
		choice = getChoice();

		switch (choice)
		{
		case 1: viewStats();
			break;

		case 2: viewCompleted();
			break;

		case 3: shop();
			break;

		case 4: createTask();
			break;

		default:
			break;
		}

	} while (choice != 5);

}
void menu()
{
    cout << "TASK-TRACK-RPG.\n";
    cout << "1.  View Your Stats.\n";
	cout << "2.  View Tasks Completed.\n";
	cout << "3.  Visit the Shop.\n";
    cout << "4.  Create a New Task.\n";
    cout << "5.  Exit the Program.\n";
    cout << "Enter your choice(1-5):  ";
}
int getChoice()
{
    string number;
    getline(cin, number);
    while (true)
    {
        bool valid = 1;
        if (size(number) > 1)
        {
            valid = 0;
        }
        else if (!(number[0] >= '1' && number[0] <= '5'))
        {
            valid = 0;
        }
        if (valid == 1)
        {
            return stoi(number);
        }
        else
        {
            cout << "Invalid input... This must be an integer value between 1 and 5.\n";
            getline(cin, number);
        }

    }
}
void viewStats()
{
    cout << "stats\n";
}
void viewCompleted()
{
    cout << "viewcompleted\n";
}
void shop()
{
    cout << "shop\n";
}
void createTask()
{
    cout << "createtask\n";
}