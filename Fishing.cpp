// In Practice, You should use the statndard input/output
// in order to receive a score properly.
// Do not use file input and output. Please be very careful. 

#include<iostream>

using namespace std;
int Answer, N, d;
int Gate[2][4];
int Visit[100];
int Select[2][4];
int V[4];


void Nhet(int x, int y)
{
	int k=0;
	int u =Gate[0][x], v;
	if ( Visit[u] == 0)
		{
			Visit[u] =1;
			k++;
			d++;
		}
	while (k < Gate[1][x] && y == 1)
	{
		u--;
		if (u >=1 && k < Gate[1][x] && Visit[u] == 0)
		{
			Visit[u] =1;
			k++;
			d = d+ Gate[0][x] -u +1;
		}
		
		v = 2*Gate[0][x] - u;

		if (v <= N && k < Gate[1][x] && Visit[v] == 0)
		{
			Visit[v] =1;
			k++;
			d = d+ v - Gate[0][x] +1;
		}
	}

	while (k < Gate[1][x] && y == 2)
	{
		u++;
		if (u <= N && k < Gate[1][x] && Visit[u] == 0)
		{
			Visit[u] =1;
			k++;
			d = d+ u - Gate[0][x] +1;
		}
		
		v = 2*Gate[0][x] - u;

		if (v >= 1 && k < Gate[1][x] && Visit[v] == 0)
		{
			Visit[v] =1;
			k++;
			d = d+ Gate[0][x] -v +1;
		}
	}
}

void loop(int x)
{
	if (x > 3)
	{
		d =0;
		for(int i =1; i<=N; i++) Visit[i] =0;
		for(int i =1; i<=3; i++)
		{
			Nhet(Select[0][i], Select[1][i]);
		}
		if (d < Answer) Answer=d;
	}
	else
	{
		for (int i = 1; i<=3; i++)
			if (V[i] ==0)
			{
				V[i] =1;
				Select[0][x] =i;
				Select[1][x] = 1;
				loop(x+1);
				Select[1][x] = 2;
				loop(x+1);
				V[i] =0;
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
		Answer = 9999;
		d =0;
		cin >> N;
		for (int i=1; i<=3; i++)
		{
			cin >> Gate[0][i];
			cin >> Gate[1][i];
		}

		loop(1);

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case << endl << Answer << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}