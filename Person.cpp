#include "Person.h"
#include <iostream>

Person::Person(string name, int age) : name(std::move(name)), age(age) {}

void Person::print() const {

    cout << "Name: " << name << ", Age: " << age << "\n";

}

int Person::getAge() const {

    return age;
}

Student::Student(string name, int age, string university)
        : Person(std::move(name), age), university(std::move(university)) {}

void Student::print() const {

    cout << "Name: " << name << ", Age: " << age << ", University: " << university << "\n";

}

GradStudent::GradStudent(string name, int age, string university, string researchTopic)
        : Student(std::move(name), age, std::move(university)), researchTopic(std::move(researchTopic)) {}

void GradStudent::print() const {

    cout << "Name: " << name << ", Age: " << age
              << ", University: " << university
              << ", Research Topic: " << researchTopic << "\n";

}