#include <iostream>
#include <string>
using namespace std;
/* 96 = "" -> 0 (96-96)
97 = "a" -> 1 (97-96)
98 = "b" -> 2 (98-96).... "char" - 96 will give int!
*/
void lettersum(string a)
{
	if (a == " ") {
		cout << "Sum: " << 0 << "\n";
	}

	else {
		int sum = 0;
		int val;
		for (int i = 0; i < a.size(); i++) {
			val = a[i] - 96;
			sum = sum + val;
		};

		cout << "Sum: " << sum << "\n";
	}
}
int main()
{
	string word;
	cout << "enter a word (lowercase plz): \n";
	cin >> word;

	lettersum(word);
	lettersum(" ");

	return 0;
}