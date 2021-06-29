// Okay, so this game is a bit evil in terms of difficulty, but it was fun to develop at least! :-)
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void playGameAtDifficulty(int difficulty, int lives) 
{
	// Is the adventurer at the start of the temple, or in a chamber? Only difficulty will tell.
	string chamber;
	if (difficulty == 1)
	{
		chamber = "the temple entrance";
	}
	else
	{
		chamber = "chamber " + to_string(difficulty - 1);
	}

	cout << "You arrive at " << chamber << ". You are presented with a riddle: \n";

	// Riddle Setup and Difficulty Progression Mechanic
	int num1 = rand() % (5 * difficulty) + 1;
	int num2 = rand() % (5 * difficulty) + 1;
	int num3 = rand() % (5 * difficulty) + 1;

	int sum = num1 + num2 + num3;
	int prod = num1 * num2 * num3;

	string input;
	string rhyme;
	
	// Pick a rhyme for the riddle text (because not everything rhymes with 'be').
	switch (lives) 
	{
		case 5:
			rhyme = "by";
			break;
		case 4:
			rhyme = "go forth";
			break;
		case 3:
			rhyme = "be";
			break;
		case 2:
			rhyme = "through";
			break;
		case 1:
			rhyme = "carry on";
			break;
		default:
			rhyme = "pass";
	}

	cout << "'Solve my riddles two and my doors will open to let you through.'\n";
	cout << "'The product of my numbers three is " << prod << ".'\n";
	cout << "'The sum of my numbers three results in " << sum << ".'\n\n";
	cout << "'Choose correctly and I'll let you " << rhyme << ". Do not waste your chances " << lives << ".'\n";

	// Set things up for the adventurer and gather his input.
	int trialSum = 0;
	int trialProd = 1;
	while (cin >> input) 
	{
		if (input == "x") 
		{
			break;
		}
		trialSum += stoi(input);
		trialProd *= stoi(input);
	}

	// Did he get things right? Let's hope so. 
	system("cls");
	if (trialSum == sum && trialProd == prod) 
	{
		cout << "'You have solved them all correctly. In the next chamber is the treasure you seek.'" << "\n\n";
		playGameAtDifficulty(++difficulty, lives);
	}
	else
	{
		cout << "'Your overconfidence has shown and one more failure you shall own.' " << "\n\n";
		lives--;
		if (lives <= 0)
		{
			cout << "'You have failed five times too many! Now face my consequences like the failures many!' " << "\n";
			cout << "Game Over! \n";
		}
		else
		{
			playGameAtDifficulty(difficulty, lives);
		}
	}
}

// The start of the game (and the main method).
int main()
{
	// Generates a new seed based on the time of day.
	srand(time(NULL));

	cout << "You are an adventurer in search of the next big artifact.\n";
	cout << "You hear rumors of an artifact known as the Ring of Infinity, located in the Gaia Temple.\n";
	cout << "You set off on your quest to the Gaia Temple.\n\n";
	playGameAtDifficulty(1, 5);

	return 0;
}
