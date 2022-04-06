#include <iostream>
using namespace std;

#define max 20

class Stack
{
	public:
	int top = -1;
	int arr[max];
	
	// the function to push integer variable to the stack
	void push(int op)
	{
		if(top == (max -1))
		{cout << "stack is full" << endl;}
		else
		{
			top++;
			arr[top] = op;
		}
	}
	
	// the function to pop integer variable from the stack
	int pop()
	{
		if(top <= -1)
		{cout << "stack is empty" << endl;}
		else
		{
			int a = arr[top];
			top--;
			return a;
		}
	}
	
};

int main()
{
	Stack s;
	
	int flag = 0;
	float deci;
	
	cout << "Enter the decimal value:";
	cin >> deci;
	if(deci == 0)
	{flag++;}
	
	
	for(int i = 0;(int)deci != 0; i++)
	{
	
		float rem;
		
		rem = deci = deci/2;
	
		// if it's a perfect integer push "0" to stack
		if(rem == (int)deci)
		{
			s.push(0);
		}	
		else // else push "1" to the stack
		{
			deci = (int)deci;
			s.push(1);
		}
		
	}
	
	cout << "binary:";
	// if the decimal value is "0" print output = "0" 
	if(flag == 1)
	{cout << "0";}
	
	// pop and print the output
	while(s.top != -1)
	{
		cout << s.pop();
	}
	cout <<"\n";

	return 0;
}



