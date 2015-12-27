#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<char> infix;
stack<char> operat;

inline int clarity(char x)
{
	if(x=='+' || x=='-')
	{
		return 1;
	}	
	else if(x=='(')
		return 0;
	else
		return 2;
}

inline bool isoperate(char x)
{
	return (x=='+' || x=='-' || x=='*' || x=='/' || x=='('||x==')');
}

void postfix(string rhs)
{
	for(size_t i = 0; i < rhs.length(); ++i)
	{
		if(!isoperate(rhs[i]))
		{
			infix.push_back(rhs[i]);
		}	
		else
		{
			if(rhs[i]=='(')
			{
				operat.push(rhs[i]);
			}
			else if(rhs[i]==')')
			{
				while(operat.top()!='(')
				{
					infix.push_back(operat.top());
					operat.pop();
				}
				operat.pop();
			}	
			else if(operat.empty()||clarity(rhs[i])>clarity(operat.top()))
			{
				operat.push(rhs[i]);
			}
			else
			{
				infix.push_back(operat.top());
				operat.pop();
				operat.push(rhs[i]);
			}
		}
	}	
	while(!operat.empty())
	{
		infix.push_back(operat.top());	
		operat.pop();
	}
}

int main(int argc, char **argv) {
	postfix(static_cast<string>("(((a+b*c)-d)*f)-q"));
	for(auto i = infix.cbegin(); i != infix.cend(); ++i)
	{
		cout<<*i;
	}
	cout << endl;
	return 0;
}
