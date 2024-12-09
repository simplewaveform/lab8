#include <iostream>

using namespace std;

class Logger {
public:
    static void log(const string& message) {
        cout << message << endl;
    }

};