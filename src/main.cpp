#include <iostream>

#include "scs-r.h"

using namespace std;

int main(int argc, char** argv) {
    if(argc != 0) {
        if (argv[0][0] == 'f') {
        }
    } else {
        int num_of_strings;
        cin >> num_of_strings;

        char** strs = new char*[num_of_strings];

        for(int i = 0; i < num_of_strings; i++) {
            cin >> strs[i];
        }

        cout << greedy_r(strs, num_of_strings) << endl;
    }
    return 0;
}
