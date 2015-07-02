#include <iostream>
using namespace std;

char Matrix[9] = {'1','2','3','4','5','6','7','8','9'};
char Player = 'X';

void Draw() {
	system("cls");
	cout<<"\t\t-----T I C - T A C - T O E----- \t\t by Anurup Dey.\n\n";
	cout<<"\n\t\t\t -------------\n";
	for (int i = 0; i<3; ++i) {
		cout<<"\t\t\t";////
		for (int j = 0; j<3; ++j) {

			cout<<" | "<<Matrix[(i*3)+j]<<"";

		}
		cout<<" |\n\t\t\t -------------\n";
	}
}

void TogglePlayer( ) {
	if (Player=='X') Player = 'O';
	else Player = 'X';
}

bool PlayTurn(int cell) {
	if (cell < 1 || cell > 9) return false;

	if (Matrix[cell-1]!='X'||Matrix[cell-1]!='O') {
		Matrix[cell-1] = Player;
		return true;
	} else return false;
}

int There_is_a_winner( ) {
	//Simple checking.
	
	for (int i = 0; i<3; i += 3) { //first we check the rows.
		if (Matrix[i]=='X' && Matrix[i+1]=='X' && Matrix[i+2]=='X') {
			return 1;
		}
		if (Matrix[i]=='O' && Matrix[i+1]=='O' && Matrix[i+2]=='O') {
			return 2;
		}
	}

	for (int j = 0; j<3; ++j) { //we check the colunms
		if (Matrix[(0*3)+j]=='X' &&Matrix[(1*3)+j]=='X' &&Matrix[(2*3)+j]=='X')
			return 1;
		if (Matrix[(0*3)+j]=='O' &&Matrix[(1*3)+j]=='O' &&Matrix[(2*3)+j]=='O')
			return 2;
	}
	
	return 0;
}

int main( ) {
	bool endGame = false;
	while (!endGame) {
		Draw( );
		cout<<"\nIt is "<<Player<<"'s chance.\n\n\n"
			<<"Enter the number of the cell you want to aquire.\n(or enter 0 to quit)\n\n>> ";
		
		int cell;
		cin>>cell;

		if (cell==0)  break; 
		
		if (PlayTurn(cell)) {
			
			TogglePlayer( );
			if (There_is_a_winner( )) {
				Draw( );
				cout<<" THERE IS A WINNER!\n\n";
				
				system("pause");
				endGame = true;
			}
		} else {
			cout<<"Invalid move, try again.\n";
			system("pause");
		}
	}
}