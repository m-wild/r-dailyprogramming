#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main () {
	string input;
	getline(cin, input);

	int numTests = atoi(input.c_str()), testType [numTests];
	string testInput [numTests], testOutput [numTests];

	for (int i = 0; i < numTests; i++) {
		getline(cin, input, ' ');
		testType[i] = atoi(input.c_str());
		getline(cin, testInput[i], ' ');
		getline(cin, testOutput[i]);
	}
	cout << endl;

	for (int i = 0; i < numTests; i++) {
		if (testType[i] == 0)
			testInput[i] = string(testInput[i].rbegin(), testInput[i].rend());
		else if (testType[i] == 1)
			std::transform(testInput[i].begin(), testInput[i].end(), testInput[i].begin(), ::toupper);
                if (testInput[i].compare(testOutput[i]) == 0) cout << "Good test data\n";
                else cout << "Mismatch! Bad test data\n";
	}
	return 0;
}
