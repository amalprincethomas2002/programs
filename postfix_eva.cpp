#include <iostream>
using namespace std;

int ctoi(char ch);

#define max 20

class Stack
{
	public:
	int top = -1;
	int arr[max];
	
	// the function to push character variable to the stack
	void push(char op)
	{
		if(top == (max -1))
		{cout << "stack is full" << endl;}
		else
		{
			top++;
			arr[top] = op;
		}
	}
	
	// the function to pop character variable from the stack
	void pop()
	{
		if(top <= -1)
		{cout << "stack is empty" << endl;}
		else
		{
			arr[top] = 0;
			top--;
		}
	}
	
	void postfix_eva(char alpha)
	{
		for(int i = 0;i < 1; i++)
		{
			// if it's a operand push to the stack
			if(alpha >= '0' && alpha <= '9')
			{
				push(ctoi(alpha));
				i++;
			}
			// if it's a operator do the following operation
			else if(alpha == '+' || alpha == '-' || alpha == '*' || alpha == '/')
			{
				int val = 0;
				int a = arr[top - 1];
				int b = arr[top];
				pop();
				pop();
			
				if(alpha == '+')
				{
					val += (a + b); 
				}
				else if(alpha == '-')
				{
					val += (a - b); 
				}
				else if(alpha == '*')
				{
					val += (a * b); 
				}
				else if(alpha == '/')
				{
					val += (a / b); 
				}
				else
				{
					cout << "invaild operator" << endl;
				}
				push(val);
			}
		}
	}
	
	// the function to display the stack
	/*void display()
	{
		if(top == -1)
		{cout << "stack is empty" << endl;}
		else
		{
			for(int i = 0;i <= top;i++)
			{
				cout << arr[i] << endl;
			}
		}
	} */
		
};

int main()
{
	Stack s;
	
	string postfix;
	cout << "enter postfix expression:";
	cin >> postfix;
	int i = 0;
	
	// add character by character to postfix_eva function
	while(postfix[i] != '\0')
	{	
		s.postfix_eva(postfix[i]);
		
		i++;
	}
	
	// printing the result
	cout << "result:" << s.arr[0] << endl;
	
	return 0;
}

// the function to convert character to integer values
int ctoi(char ch)
{
	int num;
	num = ch - '0';
	return num;
}






















