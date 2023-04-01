#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;
 

class Hangman{
	private:
		string months[12] =
	{
		"january",
		"february",
		"march",
		"april",
		"may",
		"june",
		"july",
		"august",
		"september",
		"october",
		"november",
		"december"
	};
	
	string SecretMonths[12] =
	{
		"j--u--y",
		"-e-r---y",
		"--r-h",
		"a---l",
		"--y",
		"-u-e",
		"j--y",
		"-u--st",
		"--p-e---r",
		"o-t--e-",
		"n--e--er",
		"--c-m-er"
	};
	
	int NUM_TRY;
	string message;
	char ch;
	bool i;
	string month;// to store the generated month
	char letter;
	string smonth;   //to store the secretmonth version of the generated month  
	char GuessMonth[50];
	
	
	public:
		void main_menu();
		int checkGuess();
		bool CheckWin();
		int Driver();
		int figure(int);
		
		
	



};

	//****************************Main Menu************************************//

void Hangman :: main_menu()
{
	system("color B4");   //interface color
    system("cls");
 

cout<<"\n\t  ******************************************************\n";  
cout<<"\t\t\t-----------------------------"<<endl;
cout<<"\t\t\t|  H A N G M A N  G A M E   |"<<endl;
cout<<"\t\t\t-----------------------------";
cout<<"\n\t  ******************************************************\n";
cout << "\n\t\tYou have " << NUM_TRY << " tries to try and guess the month.";
cout<<"\n\n\t\t\t\t"<<" "<<message;
cout<<"\n\n\t  ******************************************************\n";
 
}

//*********************************Letter matching Function**************************//

int Hangman :: checkGuess()  //checking if the letter is matched with any of letter in the generated month
{
	int i;
	int matches=0;
	int len = month.length();
	for (i = 0; i<len+1; i++)
	{
		
		
		if (letter == month[i])
		{
			matches++;    //letter is matched!
			
		}
	}
	return matches;
}


//**********************************To check "game over" function****************************//

bool Hangman ::CheckWin(){
		if (GuessMonth==month)
		{
			cout<<GuessMonth;
			return true;   /*if either tries are zero or the completed month is matched with the generated mon
			                in both cases game is supposed to be over! */
			
		}
		
		else {
			
			return false;
		}
		

}
	
	//****************************** Driver Function of the game******************************//
		
int Hangman:: Driver() {

do{	
    NUM_TRY=3;
    message="Play!";
    
    // generating random index number
    srand(time(NULL));
	int n=rand()%12; 
	month=months[n];
	smonth=SecretMonths[n];
    
	//total length of the string
    int l=month.length();  
   
   
    
   
	for(int i=0; i<l+1; i++){
		GuessMonth[i]=smonth[i];   // to check month name character by character, storing it in a character array 
	}
	


	do {
	main_menu();
	
	cout<<"\t\t\t\t   ";
	for(int i=0; i<l+1; i++){
		cout<<GuessMonth[i];
	}
	
	cout << "\n\n\t\t\t\tGuess a letter: "<<endl<<endl;
	figure(NUM_TRY);
	cin >> letter;

	
		if (checkGuess()==0)   // if letter does not match with any of the letter of the generated month
		{
			message = "Incorrect letter.";
			NUM_TRY = NUM_TRY - 1;
		}
		else
		{
			message = "NICE! You guess a letter";
			for(int i=0; i<l+1; i++){   //replacing the dashes with that letter since the generated month contains that letter
				if(letter==month[i])
				GuessMonth[i]=letter;
			}
			}	
		
	
		
		
	i=CheckWin();

	}while(i==false && NUM_TRY!=0);
	
	if(i==true){
		message = "Congratulations! You got it!";
		main_menu();
		cout<<"\n\t\t\t  The Month was : "<<month;
	}
	
	else{
		message = "you've been hanged! RIP ";
		main_menu();
		figure(NUM_TRY);
		}

	cout<<"\n\n\t\t\tDo you want to play again? y/n ";
	cin>>ch;
	
	
	
	}while(ch=='y' || ch=='Y');

}

int Hangman::figure(int t){
	
	switch(t){
		case 3:
cout<<"            -------- "<<endl;
cout<<"            |      | "<<endl;
cout<<"            | "<<endl;
cout<<"            |      "<<endl;
cout<<"            |  "<<endl;
cout<<"            |  "<<endl;
cout<<"           ---"  <<endl;

	break;

		case 2:
cout<<"            -------- "<<endl;
cout<<"            |      | "<<endl;
cout<<"            |      O    "<<endl;
cout<<"            |      |  "<<endl;
cout<<"            |      | "<<endl;
cout<<"            |  "<<endl;
cout<<"           ---"  <<endl;
	break;

case 1:
	cout<<"            -------- "<<endl;
cout<<"            |      | "<<endl;
cout<<"            |      O    "<<endl;
cout<<"            |    \\ | / "<<endl;
cout<<"            |      | "<<endl;
cout<<"            |  "<<endl;
cout<<"           ---"  <<endl;
	break;

case 0:
	cout<<"            -------- "<<endl;
cout<<"            |      | "<<endl;
cout<<"            |      O    "<<endl;
cout<<"            |    \\ | /"<<endl;
cout<<"            |      | "<<endl;
cout<<"            |     / \\ "<<endl;
cout<<"           ---" <<endl;
	break; 

	}
}

int main(){
	Hangman p;
	
	p.Driver();
}


