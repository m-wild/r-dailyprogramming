#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;

int main () {
	string buff;

	getline(cin, buff, 'd');
	int rolls = atoi(buff.c_str());
	getline(cin, buff);
	int sides = atoi(buff.c_str());

	srand (time(NULL));

	while (rolls > 0) {
		cout << ( rand() % sides + 1 ) << " ";
		rolls--;
	}
	cout << endl;

	return 0;
}
