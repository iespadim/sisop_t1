#include <iostream>
#include "Utils.h"
#include <sstream>
using namespace std;


int main() {
    const string file1 = "prog1.txt";
    const string file2 = "prog2.txt";

    vector<string> file1Contents = Utils::readFile(file1);
    vector<string> file2Contents = Utils::readFile(file2);

    Process p1 = Utils::parseAssemblyFile(file2,1);

    cout << p1.code_[0] << endl;
    cout << p1.data_[0]<< endl;
    return 0;
}
