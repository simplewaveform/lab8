#ifndef PERSON_H
#define PERSON_H

#include "IPrintable.h"
#include <string>

using namespace std;

class Person : public IPrintable {
protected:
    string name;
    int age;

public:
    Person(string name, int age);
    void print() const override;
    [[nodiscard]] int getAge() const;

};

class Student : public Person {
protected:
    string university;

public:
    Student(string name, int age, std::string university);
    void print() const override;

};

class GradStudent : public Student {
private:
    string researchTopic;

public:
    GradStudent(string name, int age, string university, string researchTopic);
    void print() const override;

};

#endif