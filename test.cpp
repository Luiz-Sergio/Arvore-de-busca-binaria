#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Read integers from in1
    string in1;
    getline(cin, in1);
    istringstream iss(in1);
    int num;
    while (iss >> num) {
        // Do something with num
        cout << num << endl;
    }
	cout<<"///////////////////////////"<<endl;
    // Read strings from in2
    string in2;
    while (cin >> in2) {
        // Do something with in2
        cout << in2 << endl;
    }

    return 0;
}
