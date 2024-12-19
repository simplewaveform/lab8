#include "Container.h"
#include "Person.h"
#include "Logger.h"

int main() {

    Container<std::shared_ptr<Person>> people;

    auto person1 = std::make_shared<Person>("Ваня", 18);
    auto person2 = std::make_shared<Student>("Андрей", 19, "БГУИР");
    auto person3 = std::make_shared<GradStudent>("Петров", 17, "БНТУ", "Приборы");

    std::cout << (people.empty() ? "Контейнер пуст": "Контейнер не пуст") << std::endl;
    people.printAll();

    people.add(person1);
    people.add(person2);
    people.add(person3);

    Logger::log("\nСписок людей до сортировки:");
    people.printAll();

    people.sort();

    Logger::log("\nСписок людей после сортировки:");
    people.printAll();

    Logger::log("\nРазмер контейнера:");
    std::cout << people.size() << std::endl;

    Logger::log("Удаление первого элемента:");
    auto it = people.begin();
    people.addActiveIterator(it);
    people.remove(it);
    people.printAll();
    (*it)->print();

    Logger::log("\nВозвращение к состоянию после сортировки:");
    people.clear();
    people.add(person1);
    people.add(person2);
    people.add(person3);
    people.printAll();

    Logger::log("Удаление последнего элемента (хвоста):");
    auto it1 = std::prev(people.end());
    people.addActiveIterator(it1);
    people.remove(it1);
    people.printAll();
    (*it1)->print();

    std::cout << (people.empty() ? "Контейнер пуст": "Контейнер не пуст") << std::endl;

    Logger::log("\nДобавление нового элемента после удаления:");
    auto person4 = std::make_shared<Person>("Сергей", 25);
    people.add(person4);
    people.printAll();

    return 0;
}