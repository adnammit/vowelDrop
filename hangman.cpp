
//**********************************************************************************
//
//	THE HANGMAN GAME
//  Portland State University :: Computer Science 162
//	7/18/13
//  AMANDA RYMAN :: amanda.ryman@gmail.com
//  
//**********************************************************************************
//  
//	This is a really simple program -- this is your only source file :)
//	
//  ALGORITHM:
// 	:: A small function welcomes the players to the game.
// 	:: Play begins. Each round will go until one of the players scores 5 points.
// 		+ The first player is prompted to type in a word of 20 characters 
//		  or less.
// 		+ The screen is cleared by outputting 100 new lines.
// 		+ The computer replaces all vowels with underscores and displays 
//		  the modified word.
// 		+ Player two gets three guesses. If they are right, they get a point. 
// 	:: The program returns to the original play loop. 
//		+ The final scores are displayed and the winner is declared.
// 	:: The computer asks if they would like to keep playing.
//	:: If the players want to play again, the loop continues.
//	:: If the players are done playing, a "goodbye" message is displayed.
//
//*******************************************************


#include <iostream>
#include <cstring>

using namespace std;

void welcome();
void playLoop();
void getWord(char word[]);
int guessWord(char word[],int score);
void noVowels(char word[]);
void whoWon(int score1,int score2);
void goodbye();


int main()
{

	welcome();
	playLoop();
	goodbye();

	return 0;
}




//********************************************************************************
//  WELCOME!

void welcome()
{
	cout << "\nWELCOME TO THE VOWEL DROP!"
		<< "\n\tYou and your opponent take turns picking a word."
		<< "\n\tThe computer will drop the vowels from the word "
		<< "\n\tYou will have three tries to guess what the word is without its vowels!";

}


//********************************************************************************
//  FUNCTION: PLAY THE GAME!

void playLoop()
{
	char isGood='y';
	do 
	{
		int score1=0;
		int score2=0;	
		do
		{

			char word1[21];					// word1 and word2 reset each loop
			char word2[21];					// the array 'word' will hold 20 letters and \0

// FIRST: PLAYER ONE SETS THE WORD.
//  PLAYER TWO GUESSES:

			cout << "\n\nPLAYER ONE! You're up."
				<< "\n\tEnter a word that is less than 20 letters long,"
				<< "\n\tand don't let that sneak Player Two see what it is:";

			getWord(word1);								

			cout << "PLAYER TWO!" 
				<< "\n\tHere's the word -- what do you think it is?";

			noVowels(word1);
			score2=guessWord(word1,score2);		

// SECOND: PLAYER TWO SETS THE WORD.
//  PLAYER ONE GUESSES:

			cout << "\n\nPLAYER TWO!" 
				<< "\n\tYour turn to pick a word."
				<< "\n\tJust be sure that it is less than 20 letters long."
				<< "\n\tPlayer One always tries to cheat, so be careful:";

			getWord(word2); 

			cout << "Okay, now you're up, PLAYER ONE!" 
				<< "\n\tHere's the word without its vowels."
				<< "\n\tTake a stab at it... or three.";

			noVowels(word2);
			score1=guessWord(word2,score1);

// REPEAT UNTIL SOMEONE SCORES 5PTS

		}while (score1<5 && score2<5);
		whoWon(score1,score2);

// PLAY AGAIN?

		cout << "\nWould you like to play again? [Y/N] \t";
		cin >> isGood;
		cin.ignore(100,'\n');
		if (tolower(isGood)=='n')
			isGood='n';
	}while (isGood!='n');
}



//********************************************************************************
//  FUNCTION: GET THE WORD

void getWord(char word[])
{
	cout << "\n";
	cin.get(word,21,'\n');
	cin.ignore(100,'\n');
	for (int i=0; i<strlen(word); i++)
	{
		word[i]=toupper(word[i]);
	}

// 100 BLANK SPACES 
// TO CLEAR THE SCREEN:
	for (int i=0; i<100; i++)			
	{
		cout << "\n";
	}
}


//********************************************************************************
// FUNCTION: GUESS THE WORD

int guessWord(char word[],int score)
{
	int tries=0;
	char guess[21];
	do
	{
		cin.get(guess,21,'\n');
		cin.ignore(100,'\n');

		for (int i=0; i<21; i+=1)
		{
			guess[i]=toupper(guess[i]);
		}

		if (strcmp(guess,word)==0)			
		{	
			cout << "\nYou got it!";
			score+=1;
			// RETURN used to end play when the correct word is guessed	
			return score;							
		}
		else
			if (tries==2)
			{
				tries+=1;
			}
			else
			{
				tries+=1;
				cout << "Close, but completely wrong. Try again!\t";
			}
	}while (tries<3);

	cout << "\nUh oh, you ran out of guesses!"
		<< "\n\tThe word is:"
		<< "\t" << word;	
			
	return score;
}



//********************************************************************************
// FUNCTION: REMOVE THE VOWELS

void noVowels(char word[])
{
	cout << "\n\t\t";
	for (int i=0; i<21 && word[i]!='\0'; i+=1)
	{
		if(word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U')
			cout << " _";
		else
			cout << ' ' << word[i];
	}

	cout << "\n";
}



//********************************************************************************
// FUNCTION: WHO WON?

void whoWon(int score1, int score2)
{
	cout << "\n\nFINAL SCORE:"
		<< "\n\tPlayer One: \t" << score1
		<< "\n\tPlayer Two: \t" << score2 << '\n';
	if (score1>score2)
		cout << "\nCongratulations Player One, you won!!";
	if (score1<score2)
		cout << "\nCongratulations Player Two, you won!!";
	if (score1==score2)
		cout << "\nWe have a tie! Players, you are exceptional guessers.";
	cout << endl;
}



//********************************************************************************
// FUNCTION: GOODBYE!

void goodbye()
{
	cout << "\nThanks for playing! Come back soon with more words.";
	cin.get();
}


//********************************************************************************
// SMILE. YOU DONE!


