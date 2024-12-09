#include "Person.h"
#include <memory>

using namespace std;

class Factory {
public:
    static shared_ptr<Person> createPerson(const string& name, int age);
    static shared_ptr<Student> createStudent(const string& name, int age, const string& university);
    static shared_ptr<GradStudent> createGradStudent(const string& name, int age, const string& university, const string& researchTopic);

};