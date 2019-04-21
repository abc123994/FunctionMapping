#include<iostream>
#include <map>
#include<functional>
using namespace std::placeholders;
using namespace std;

void MapFunctionA(int)
{
	cout << "Function A execute..."<<endl;
}
void MapFunctionB(int)
{
	cout << "Function B execute..." << endl;
}
int main(int argc, char* argv[])
{
	
	map<int, std::function<void(int)>> map_func;
	map_func.insert(std::pair<int, std::function<void(int)>>(1, bind(MapFunctionB,_1)));
	map_func.insert(std::pair<int, std::function<void(int)>>(2, bind(MapFunctionA, _1)));
	std::map<int, std::function<void(int)>>::iterator it;
	for (it=map_func.begin(); it != map_func.end();it++)
	{
		
		std::function<void(int)> t = it->second;
		t(it->first);
	}

	system("pause");
}