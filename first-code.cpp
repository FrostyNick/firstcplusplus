#include <iostream>
#include <string>
#include <cctype>

// cin.get() is one way to pause input.

using namespace std;
// Future monster types: Zombie, mouse

const string monsterName = "mouse";
int monsterTotalHp = 100;
int monsterHp;

int userTotalHp = 100;
int userHp = 100;
unsigned int userXp = 0;
int userBattles = 0;
bool firstTime = true;

void ouch(int damage)
{
	cout << "You caused " << monsterName << " " << damage << " damage!";
	monsterHp -= damage;
}

void ouch2(int damage)
{
	cout << "The " << monsterName << " caused you " << damage << " damage!";
	userHp -= damage;
}

void buff()
{
	unsigned short extraNerf = userTotalHp / 10;
	userTotalHp += extraNerf;
	userHp += extraNerf;
	cout << "Your Total HP has been increased! +" << extraNerf << "\n";
	cout << "Automatically healed " << extraNerf << " HP!\n";
}

int monster()
{
	system("clear");
	cout << "You've enountered a " << monsterName << "!" << endl;
	string action;
	monsterHp = monsterTotalHp;
	int punches = 0;
	do {
		cout << monsterName << " HP: " << monsterHp << "/" << monsterTotalHp << "\n";
		cout << "My HP: " << userHp << "/" << userTotalHp << "\n";
		cout << "\nWhat will you do?\n\n" << "1) Punch\n2) Kick\n3) Run\n";
		getline (cin, action);
		// action = tolower(action);
		ouch2(40);
		if (action == "punch" or action == "1")
		{
			cout << "You chose punch!";
			ouch(40 + punches * 10);
			punches += 1;
		}
		else if (action == "kick" or action == "2")
		{
			cout << "You chose kick!";
			ouch(50);
		}
		else { cout << "Choose an option! You can't kick or run yet by the way."; }
		cout << "\n\n";
		system("clear");
	} while (monsterHp > 0 and userHp > 0);
	return userHp >= 0;
}

void findMonster()
{
	int result = monster();
    // cout << "Result ID: " << result << "\n\n"; // keep this to remind yourself what a bool is
    if (result)
    {
		string extraText;
		unsigned short earnedXp = 20;
		if (firstTime)
		{
			firstTime = false;
			earnedXp += 100;
			extraText = " (First kill! You got an extra combined 100 XP.)";
		}
		userXp += earnedXp;
		cout << "You won with " << userHp << " HP remaining. Your rewards are:\n\nXP: +" << earnedXp << extraText << "\n";
		if (userXp == 200 or userXp == 300 or userXp == 500)
		{
			buff();
		}
	}
	else
		cout << "You failed! Your punishment will be death >:[\n";
}

// Escape sequences are \epic
int main( )
{
	cout << "Type your username:";
	string username, ch;
	getline (cin, username);
	/*cout << "Confirm your username by pressing enter.";
	cin >> ch;
	cout << "\"" << ch << "\" is yes.";
	cin >> ch;
	cout << "RIGHT????";*/
	//cin.get();
	//cin >> ch; // "hello everyone" --> "hello"
	//string str 
	//auto a = 'n';
	//cout << sizeof("\\n") << "\n";
	/*short a;
	unsigned short b;
	int c;
	long d;
	 
	* float
	* double
	* long double 
	 
	  
	long long e;
	
    cout << "False: " << false << "\nsizeof(long long variable): " << sizeof(e) << "\nHello, Hello!\tWorld?\n" << "\n";*/
    system("clear");
    // cout << "Getting player data.." << endl;
    
    cout << "Attention: All responses must be lowercase or numerical without spaces.";
    do
    {
		cout << "\n\n#### Stats ####\n\nHP | " << userHp << "\nXP | " << userXp << "\n\n";
		cout << "Choose an action!\n\n1) Hunt for a monster\n2) Heal\n3) Quit" << "\n";
		string action;
		getline (cin, action);
		cout << "\n";
		if (action == "1" or action == "hunt for a monster")
		{
			findMonster();
			cout << "You have returned home.";
		}
		else if (action == "2" or action == "heal")
		{
			userHp = userTotalHp;
			cout << "You have been healed.";
		}
		else if (action == "3" or action == "quit")
		{
			cout << "Goodbye!";
			break;
		}
		else
			system("clear");
	} while (true);
	
    return 0;
}
