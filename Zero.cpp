// In Practice, You should use the statndard input/output
// in order to receive a score properly.
// Do not use file input and output. Please be very careful. 

#include<iostream>

using namespace std;
int N, Answer, a;
int Select[10];

int check()
{
	int sum =1;
	int k =1;
	a=0;
	for (int i=1; i<N; i++)
	{

		switch (Select[i])
		{
		case 0:
			{
				k = k*10 + i +1;
			}
			break;
		default:
			{
				
				if (i >=2)
				{
					if( Select[a] ==1) sum= sum+k;
					if( Select[a] ==2) sum = sum -k;
					if( Select[a] ==0) sum = k;
					a =i;
				}
				else a =i;
				k =i+1;
			}
			break;
		}
	}

	if (a == 0) sum =k;
	else
		if( Select[a] ==1) sum= sum+k;
		else sum = sum -k;

	return sum;
}

void loop(int x)
{
	if (x == N)
	{
		if (check() == 0) Answer++;
	}
	else
	{
		for (int i =0; i<= 2; i++)
		{
			Select[x] =i;
			loop(x+1);
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
		cin >>N;
		loop(1);
		// Print the answer to standard output(screen).
		cout << "#" << test_case << " " << Answer << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}