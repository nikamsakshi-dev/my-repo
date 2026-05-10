#include<iostream>
using namespace std;
char b[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row;
int cloumn;
bool draw=false;
void disB()
{
	system("cls");
	cout<<"X and O game...!"<<endl;
	cout<<"Player1 [X] \nPlayer2 [O] \n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<b[0][0]<<"  |  "<<b[0][1]<<"  |  "<<b[0][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<b[1][0]<<"  |  "<<b[1][1]<<"  |  "<<b[1][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<b[2][0]<<"  |  "<<b[2][1]<<"  |  "<<b[2][2]<<"  \n";
	cout<<"\t\t     |     |     \n";

}
void playerTurn()
{
	int ch;
	if(turn=='X')
	{
		cout<<"Player1[X] turn: ";
	}
	else 
	{
		cout<<"Player2[O] turn: ";
	}
	cin>>ch;
	switch(ch)
	{
		case 1: row=0;cloumn=0; break;
		case 2: row=0;cloumn=1; break;
		case 3: row=0;cloumn=2; break;
		case 4: row=1;cloumn=0; break;
		case 5: row=1;cloumn=1; break;
		case 6: row=1;cloumn=2; break;
		case 7: row=2;cloumn=0; break;
		case 8: row=2;cloumn=1; break;
		case 9: row=2;cloumn=2; break;
	    default:
	    	    {
	    	    	cout<<"Invalid Choice...";
				}
				break;    
	}
	if(turn=='X' && b[row][cloumn]!='X'&&b[row][cloumn]!='O')
	{
		b[row][cloumn]='X';
		turn='O';
	}
	else if(turn=='O' && b[row][cloumn]!='X'&&b[row][cloumn]!='O')
	{
		b[row][cloumn]='O';
		turn='X';
	}
	else 
	{
		cout<<"Box already filled!\n Try again...\n\n";
		playerTurn();
	}
	disB();
}
bool gameOver()
{
	for(int i=0;i<3;i++)
	{
	if(b[i][0]==b[i][1] && b[i][0]==b[i][2] || b[0][i]==b[1][i] && b[0][i]==b[2][i])	
	return false;
	if(b[0][0]==b[1][1]&&b[0][0]==b[2][2] || b[0][2]==b[1][1]&&b[2][0]==b[0][2])
	return false;
    }
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	{
	if(b[i][j]!='X' && b[i][j]!='O')
	return true;
    }
    draw=true;
    return false;
}
int main()
{
	while(gameOver())
	{
	  disB();
      playerTurn();
      gameOver();  	
	}
	if(turn =='X'&& draw==false)
	cout<<"Player2 [O]Wins...!\n";
    else if (turn =='O' && draw==false)
    cout<<"Player1 [X]Wins...!\n";
    else
    cout<<"GAME DRAW...";
}

