// In Practice, You should use the statndard input/output
// in order to receive a score properly.
// Do not use file input and output. Please be very careful. 

#include<iostream>

using namespace std;
int Answer, N, M, c, d, front, rear, turn;
int Map[100][100];
int Visit[100][100];
int Q[2][1000000];
bool F;

void enQueue(int x, int y)
{
	if (F == false && x >=0 && y>=0 && x <N && y <M && Visit[x][y] ==0 && Map[x][y] !=0)
	{
		Visit[x][y] =1;
		rear++;
		Q[0][rear] = x;
		Q[1][rear] = y;
		if (x == c && y == d) F = true;
	}
}

void Loang()
{
	int a, b;
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++) Visit[i][j] =0;
	front =-1;
	rear =0;
	Q[0][0] = N-1;
	Q[1][0] = 0;
	Visit[N-1][0] =1;
	while (front < rear && F== false)
	{
		front++;
		a = Q[0][front];
		b = Q[1][front];
		enQueue(a, b-1);
		enQueue(a, b+1);
		for (int i=1; i<= Answer; i++)
		{
			enQueue(a-i, b);
			enQueue(a+i, b);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	
	ios::sync_with_stdio(false);
	
	/* 
	The freopen function below opens input.txt in read only mode and 
	sets your standard input to work with the opened file. 
	When you test your code with the sample data, you can use the function
	below to read in from the sample data file instead of the standard input.
	So. you can uncomment the following line for your local test. But you
	have to comment the following line when you submit for your scores.
	*/

	freopen("input.txt", "r", stdin);
	cin >> T;

	/*
	   Read each test case from standard input.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		Answer = 0;
		F = false;
		cin >>N;
		cin >> M;
		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++) 				
			{
				cin >> Map[i][j];
				if (Map[i][j] == 3) 
				{
					c =i;
					d =j;
				}
			}

		while (F==false)
		{
			Answer++;
			Loang();
		}


		// Print the answer to standard output(screen).
		cout << "#" << test_case << " " << Answer << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}