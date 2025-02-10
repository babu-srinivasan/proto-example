#include <fstream>
#include <iostream>
#include "lib/proto/person.pb.h"
#include "lib/person_wrapper.h"


using namespace std;
using namespace proto_example;

int main(){
    cout<<"ProtoBuf example starting ..."<<endl;

    Person person;
    PersonWrapper personWrapper;

    person.set_id(1);
    person.set_name("John Doe");
    person.set_email("johndoe@example.com");

    cout<<endl<<"Writing to file ..."<<endl;
    personWrapper.writeToFile((const char*)"/tmp/person.pb",&person);

    Person person2;
    personWrapper.readFromFile((const char*)"/tmp/person.pb",&person2);
    cout<<endl<<"Read from file ..."<<endl;

    cout<<"Id :"<<person2.id()<<endl;
    cout<<"Name :"<<person2.name()<<endl;
    cout<<"Email :"<<person2.email()<<endl;
    
    google::protobuf::ShutdownProtobufLibrary();
}