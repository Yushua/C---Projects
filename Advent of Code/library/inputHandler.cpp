#include "Library.h"

vector<string> read_input(const string& input_file) {
    ifstream file(input_file);
    if (!file.is_open()) {
        cerr << "Error opening file: " << input_file << endl;
        exit(1);
    }

    vector<string> input;
    string line;
    while (getline(file, line)) {
        input.push_back(line);
    }

    file.close();
    return input;
}
