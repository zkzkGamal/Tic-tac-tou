#include <iostream>
#include<string>
#include <stdlib.h>
using namespace std;
class stackLN
{
    struct node
    {
        int data =0;
        int arr[3][3];
        node* next ;
    };
    node* top = NULL;
public:
    bool isEmpty()
    {
        if(top == NULL)
            return true;
        else
            return false;
    }
    void push(int val)
    {
        node* newnode = new node;
        newnode->data = val;
        newnode->next = NULL;
        if(isEmpty())
            newnode->next = NULL;
        else
            newnode->next = top;
        // save the new node
        top = newnode;
    }
    void pop()
    {
        if(isEmpty())
            return;
        node* temp = top;
        top = temp->next;
        delete temp;
    }
    void topval()
    {
        if(isEmpty())
            cout << "Stack is Empty";
        else
            cout << top->data;
    }
    void push_at_pos(int val,int pos)
    {
        node* newnode = new node;
        newnode->data = val;
        newnode->next = NULL;
        // check the posation is first
        if (pos == 0)
        {
            newnode->next = top;
            top = newnode;
            return;
        }
        node* temp = top;
        for(int i=0; i<pos-1 && temp->next != NULL ; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next =  newnode;
    }
};
struct node1
{
	char board[3][3];
	char player1;
	char cpu;
};



void inboard (char board[3][3])
{
	for (int i = 0;i<3;i++)
		for (int j = 0;j<3;j++)
			board[i][j] = '.';
}

// printing the board

void print(char board[3][3])
{
	for (int i = 0;i<3;i++)
	{
		cout << endl;
		for (int j = 0;j<3;j++)
		{
			cout<<"  ";
			cout<<board[i][j];
		}
	}
	cout<<endl<<endl;
}



char WinP(char board[3][3])
{
	// horizontal, vertical & diagonal through [0][0]
	if (board[0][0] != '.' && (board[0][0] == board[0][1] && board[0][0] == board[0][2] ||
		board[0][0] == board[1][0] && board[0][0] == board[2][0] ||
		board[0][0] == board[1][1] && board[0][0] == board[2][2]))
						return board[0][0];

	// horizontal, vertical & diagonal through [1][1]
	if (board[1][1] != '.' && (board[1][1] == board[1][0] && board[1][1] == board[1][2] ||
		board[1][1] == board[0][1] && board[1][1] == board[2][1] ||
		board[1][1] == board[2][0] && board[1][1] == board[0][2]))
						return board[1][1];

	// horizontal, vertical & diagonal through [2][2]
	if (board[2][2] != '.' && (board[2][2] == board[0][2] && board[2][2] == board[1][2] ||
		board[2][2] == board[2][0] && board[2][2] == board[2][1]))
						return board[2][2];
	return 0;
}



void placement(char board[3][3], char player)
{
	while (1)
	{
		string r, c;
		int row = 0, col = 0;
		while (1)
		{
			cout<<"Enter the row: ";
			cin>>r;
			row = atoi(r.c_str());
			if (row>=1 && row<=3)
				break;
			cout<<"Invalid Input (try between 1 and 3).\n";
		}
		while (1)
		{
			cout << "Enter the column: ";
			cin >> c;
			col = atoi(c.c_str());
			if (col>=1 && col<=3)
				break;
			cout << "Invalid Input (try between 1 and 3).\n";
		}
		if (board[row-1][col-1] == '.')
		{
			board[row-1][col-1] = player;
			break;
		}
		else
			cout<<"location already occupied, try again\n\n";
	}
}


int main()
{
    stackLN aa;
    node1 game;
    inboard(game.board);
    print(game.board);
}
