#include <iostream>
using namespace std;

#define max 20

class Stack
{
	public:
	int top = -1;
	char arr[max];
	string postfix;
	
	// the function to push character variable to the stack
	void push(char op)
	{
		if(top >= (max-1))
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
		{cout << "pop__stack is empty " << endl;}
		else
		{
			arr[top] = 0;
			top--;
		}
	}
	
	
	// the function to display the top of the stack
	char peep()
	{
		if(top == -1)
		{cout << "peep__stack is empty" << endl;}
		else
		{
			return arr[top];
		}
	}
	
	// the function to assign precedence to the operators
	int precedence(char ch)
	{
		
		if(ch == '^')
		{return 3;}
		else if(ch == '*' || ch == '/')
		{return 2;}
		else if(ch == '+' || ch == '-')
		{return 1;}	
		else
		{return -1;}
	}
	
	
	void infix_to_postfix(char a)
	{
		// if "a" is an operand add to postfix 
		if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
		{
			postfix += a;
		}
		
		// if "a" is "(" push to stack
		else if(a == '(')
		{
			push(a);
		}
		
		// if "a" is ")" add all operator to postfix until "a" = "("
		else if(a == ')')
		{
			while((peep() != '(') && (top != -1))
			{
				postfix += peep();
				pop();
			}
			
			if(peep() == '(')
			{
				pop();
			}
		
		}
		
		// if "a" is an operator
		else if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
		{
			
			if(top == -1)
			{
				push(a);
			}
			else
			{
				if(precedence(a) > precedence(peep()))
				{	
					push(a);
				}
				else
				{
					while((top != -1) && (precedence(a) <= precedence(peep())))
					{
						postfix += peep();
						pop();
					}
					push(a);	
				}
			}
			
			
		}

}
	// the function to display the stack
	
	/*void display()
	{
		if(top == -1)
		{cout << "display stack is empty" << endl;}
		else
		{
			for(int i = 0;i <= top;i++)
			{
				cout <<"arr stack:"<< arr[i] << endl;
			}
		}
	}*/
};


int main()
{

	Stack s;

	string infix;
	cout << "enter infix expression:";
	cin >> infix;
	
	// add character by character to infix_to_postfix function
	for(int i = 0; infix[i] != '\0'; i++)
	{
		s.infix_to_postfix(infix[i]);	
	}
	
	// emptying the stack by poping and adding the operator to the postfix
	while(s.top != -1)
	{
		s.postfix += s.peep();
		s.pop();
	}
	
	// printing the result
	cout << "postfix:" << s.postfix << endl;
	
	return 0;	
}
