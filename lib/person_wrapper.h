#include<fstream>
#include <iostream>
#include "lib/person.pb.h"

using namespace std;

namespace proto_example {
class PersonWrapper{
    
  public:
    PersonWrapper(){};

    bool readFromFile(const char* , Person* );
    bool writeToFile(const char* , Person* );
};
}