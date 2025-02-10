#include <iostream>
#include <fstream>
#include "person_wrapper.h"

using namespace std;

namespace proto_example {

bool PersonWrapper::readFromFile(const char* filename, Person* person) {
    fstream ifile(filename, ios::in | ios::binary);
    if (!person->ParseFromIstream(&ifile)) {
        cerr << "Error reading file" << endl;
        return -1;
    }
    cout << "read successfully" << endl;
    ifile.close();
    return true;
}

bool PersonWrapper::writeToFile(const char* filename, Person* person) {

    fstream ofile(filename, ios::out | ios::binary);
    if (!person->SerializeToOstream(&ofile)) {
        cerr << "error writing to file" << endl;
        return false;
    }
    cout << "written successfully " << endl;
    ofile.close();
    return true;
}
}