#include "Container.h"
#include "Person.h"
#include "Sorter.h"
#include <iostream>

int main() {

    Container<std::shared_ptr<Person>> people;

    auto person1 = std::make_shared<Person>("Ваня", 18);
    auto person2 = std::make_shared<Student>("Андрей", 19, "БГУИР");
    auto person3 = std::make_shared<GradStudent>("Петров", 17, "БНТУ", "Приборы");

    people.add(person1);
    people.add(person2);
    people.add(person3);

    std::cout << "Список людей до сортировки:" << std::endl;
    people.printAll();

    people.sort();

    std::cout << "\nСписок людей после сортировки:" << std::endl;
    people.printAll();

    std::cout << "\nУдаление первого элемента:" << std::endl;
    auto it = people.begin();
    people.remove(it);
    people.printAll();

    std::cout << "\nУдаление последнего элемента (хвоста):" << std::endl;
    it = people.begin();
    ++it;
    people.remove(it);
    people.printAll();

    std::cout << "\nДобавление нового элемента после удаления:" << std::endl;
    auto person4 = std::make_shared<Person>("Сергей", 25);
    people.add(person4);
    people.printAll();

    return 0;
}