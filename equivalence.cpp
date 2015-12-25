#include <iostream>
#include <array>
#include <vector>
using namespace std;
const size_t MAX_SIZE = 100;
array<vector<int>, MAX_SIZE> valence;
array<bool,MAX_SIZE> visited{false,};

void dfs(int i);

void equivalenc(int a,int b)
{
	valence.at(a).push_back(b);
	valence.at(b).push_back(a);
}

void printvalenc()
{
	for(size_t i = 0; i < MAX_SIZE; ++i)
	{
		if(!visited.at(i) && !valence.at(i).empty())
		{
			dfs(i);
			cout << endl;
		}
	}	
}

void dfs(int i)
{
	if(!visited.at(i))
	{
		visited.at(i)=true;
		cout<< i << " ";
		for(auto j = valence.at(i).cbegin(); j != valence.at(i).cend(); ++j)
		{
			if(!visited.at(*j))
			{
				dfs(*j);
			}	
		}
	}
}
int main(int argc, char **argv) {
	equivalenc(1,2);
	equivalenc(3,2);
	equivalenc(5,2);
	equivalenc(1,4);
	equivalenc(6,9);
	equivalenc(7,8);
	printvalenc();
	return 0;
}

