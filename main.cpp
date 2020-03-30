#include <bits/stdc++.h>

using namespace std;
bool is_winner();
bool filled_up();
void intro();
void take_turn();
void set_position();
void update_board();
void change_player();
void draw();
void result();
string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player=1;
int position=0;

int main()
{
play:cout<<"\t\t\tTic-Tac-Toe\n";
    intro();
    take_turn();
    result();
    char c,c1;
    cout<<"\tDo you want to play again??(y/n)\n";
    cin>>c;
    if(c=='y'){
            player=1;
            for(int i=0;i<9;i++)
                board[i]=" ";
            goto play;
    }
    return 0;
}
void intro()
{
    cout<<"\t\tWelcome to Tic-Tac-Toe!!\n";
    cout<<"\tTic-Tac-Toe consist of 2 players-Player1:X Player2:O\n\tThe player who gets a straight line of inputs(vertically/horizontally/diagonally) is the winner\n";
    cout<<"\n";
    cout<< "Here's the 3 x 3 grid:\n\n";

  cout<< "     |     |      \n";
  cout<< "  1  |  2  |  3   \n";
  cout<< "_____|_____|_____ \n";
  cout<< "     |     |      \n";
  cout<< "  4  |  5  |  6   \n";
  cout<< "_____|_____|_____ \n";
  cout<< "     |     |      \n";
  cout<< "  7  |  8  |  9   \n";
  cout<< "     |     |      \n\n";
}
void take_turn()
{
  while ( !is_winner() && !filled_up() )
    {
    set_position();
    update_board();
    change_player();
    draw();
  }
}

void set_position()
{
    if(player%2!=0)
    {
 here:  cout<<"Player1,Enter your choice {1-9}?\n";
        cin>>position;
        if(position<1 || position>9)
        {
            cout<<"Please enter a valid position\n";
            goto here;
        }
        cout<<"\n";
        if(board[position-1]!=" ")
        {
            cout<<"The block is already filled! Please try an another position\n";
            goto here;
        }
    }
    else
    {
        cout<<"Its computer's turn\n";
        srand(time(NULL));
random: position=rand()% 9;
        if(board[position]!=" ")
                goto random;
    }
}

void update_board()
{
    if(player%2!=0)
            board[position-1]="X";
    else
        board[position]="O";
}

void draw()
{

  cout << "     |     |      \n";
  cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  cout << "     |     |      \n";
  cout << "\n";
}

void change_player()
{
    player++;
}

bool is_winner()
{
      bool winner = false;
  // checking the rows
  if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ") {
    winner = true;
  } else if ((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ") {
    winner = true;
  } else if ((board[6] == board[7]) && (board[6] == board[8]) && board[6] != " ") {
    winner = true;
  }
  // checking the columns
  else if ((board[0] == board[3]) && (board[0] == board[6]) && board[0] != " ") {
    winner = true;
  } else if ((board[1] == board[4]) && (board[1] == board[7]) && board[1] != " ") {
    winner = true;
  } else if ((board[2] == board[5]) && (board[2] == board[8]) && board[2] != " ") {
    winner = true;
  } // checking the diagonals
  else if ((board[0] == board[4]) && (board[0] == board[8]) && board[0] != " ") {
    winner = true;
  }
  else if ((board[2] == board[4]) && (board[2] == board[6]) && board[2] != " ") {
    winner = true;
  }
  return winner;
}

bool filled_up()
{
    bool filled=true;
    for(int i=0;i<9;i++)
    {
        if(board[i]==" ")
            filled=false;
    }
    return filled;
}

void result()
{
    if(is_winner() && player%2!=1)
        cout<<"Player 1 wins!!\n";
    else if(is_winner())
        cout<<"Computer wins!!\nPlease try again!!\n";
    else if(filled_up()==true)
        cout<<"Its a tie\n";
    cout<<"\tGAME OVER\n";
}
