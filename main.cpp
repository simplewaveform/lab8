#include "Person.h"
#include "Container.h"
#include "Sorter.h"
#include "Logger.h"
#include "Factory.h"

///////////////////////////////////////    main application with demo examples     /////////////////////////////////////
int main() {

    auto people = Container<Person>();

    auto person1 = Factory::createPerson("Ваня", 18);
    auto person2 = Factory::createStudent("Андрей", 19, "БГУиР");
    auto person3 = Factory::createGradStudent("Петров", 17, "БНТУ", "Приборы");

    people.add(person1);
    people.add(person2);
    people.add(person3);

    Logger::log("Список людей:");
    people.printAll();

    Logger::log("\nСписок после сортировки по возрасту:");
    people.sort(Sorter::compareByAge);
    people.printAll();

    Logger::log("\nУдаление первого элемента:");
    auto it = people.begin();
    people.remove(it);
    people.printAll();

    Logger::log("\nСравнение итераторов:");
    auto it1 = people.begin();
    auto it2 = people.begin();
    ++it2;
    if (it1 == it2) Logger::log("Итераторы равны.");
    else Logger::log("Итераторы не равны.");


    Logger::log("\nПостфиксный инкремент итератора:");
    it1 = people.begin();

    Logger::log("Текущий элемент:");
    (*it1)->print();

    Logger::log("После постфиксного инкремента:");
    it1++;
    (*it1)->print();


    Logger::log("\nДекремент итератора:");
    auto reverseIt = people.end();
    --reverseIt;

    Logger::log("Обратный обход:");
    for (; reverseIt != people.begin(); --reverseIt) (*reverseIt)->print();
    (*reverseIt)->print();

    return 0;
}