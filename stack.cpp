#include <iostream>
using namespace std;

#define max 5
class stack
{
	public:
	int top = -1;
	int arr[max];
	
	
	// the function to push character variable to the stack
	void push()
	{
		if(top >= (max - 1))
		{cout << "stack is full " << endl;}
		else
		{
			int num;
			cout << "pushing "<< endl << "enter the value:";
			cin >> num;
			
			top++;
			arr[top] = num;
		}
	}
	
	// the function to pop character variable from the stack
	void pop()
	{
		if(top <= -1)
		{cout << "stack is  empty" << endl;}
		else
		{
			cout << "poping" << endl;
			arr[top] = 0;
			top--;
		}
	}
	
	// the function to display the top of the stack
	void peep()
	{
		if(top == -1)
		{cout << "stack is empty" << endl;}
		else
		{
			cout << "peeping "<< arr[top] << endl;
		}
	}
	
	// the function to display the stack
	void display()
	{
		if(top == -1)
		{cout << "stack is empty" << endl;}
		else
		for(int i = 0; i <= top; i++)
		{
			cout << arr[i] << endl;
		}
	}

};

int main ()
{
	stack ob;
	
	cout << endl << "push__1" << endl << "pop__2" << endl << "peep__3" << endl << "display__4"<< endl <<"exit__5" << endl;
	
	while(1)
	{
	
		int n;
		cout << "enter your option:";
		cin >> n;
	
		switch(n)
		{
			case 1:
			ob.push();
			break;
			
			case 2:
			ob.pop();
			break;
		
			case 3:
			ob.peep();
			break;
			
			case 4:
			ob.display();
			break;
			
			case 5:
			exit (0);
			break;
		}
	}
	return 0;
}
