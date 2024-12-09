#include "Factory.h"

shared_ptr<Person> Factory::createPerson(const string& name, int age) {

    return make_shared<Person>(name, age);
}

shared_ptr<Student> Factory::createStudent(const string& name, int age, const string& university) {

    return make_shared<Student>(name, age, university);
}

shared_ptr<GradStudent> Factory::createGradStudent(const string& name, int age, const string& university, const string& researchTopic) {

    return make_shared<GradStudent>(name, age, university, researchTopic);
}