#ifndef SUBJ_H
#define SUBJ_H
#include <iostream>
#include <vector>
#include "Observer.h"
#include <QFile>
#include <QString>
/*класс отвечает за уведомление
наблюдателей при любых изменениях.
Предлагается внутри объекта ASubject хранить список ссылок на объекты
наблюдателей,
При этом ASubject не должен вести список подписки самостоятельно.
Он предоставляет методы, с помощью которых наблюдатели могли бы
добавлять или убирать себя из списка.
Когда в ASubject будет происходить важное событие, он будет
проходиться по списку подписчиков и оповещать их об этом, вызывая
определённый метод объектов-наблюдателей.*/
class ASubject
{
protected:
    std::vector<IObserver*> list;
public:
    virtual void Attach(IObserver *sbj) // метод для присоединения наблюдателя
    { list.push_back(sbj);//добавляем наблюдателя в list наблюдателей
    };
    virtual void Detach(IObserver *sbj)//метод для отключения наблюдателя
    { list.erase(std::remove(list.begin(), list.end(), sbj), list.end());
    };
    virtual void Notify(bool fileExist, int size, QString fileName);
};
/*Этот класс является реальным классом, который
реализует ASubject. Этот класс является сущностью, изменение которой
повлияет на другие объекты.*/
/*создает объекты ConcretFile и ConsoleFile,а
затем регистрирует ConsoleFile на обновления в
ConcretFile.*/
class ConcretFile: public ASubject
{};

#endif // SUBJ_H
