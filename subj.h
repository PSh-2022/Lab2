#ifndef SUBJ_H
#define SUBJ_H
#include <iostream>
#include <vector>
#include "Observer.h"
#include <QFile>
#include <QString>
/*Этот класс отслеживает всех наблюдателей и
предоставляет возможность добавлять или удалять
наблюдателей.
Кроме того, именно класс отвечает за обновление
наблюдателей при любых изменениях.
Предлагается внутри объекта Subject хранить список ссылок на объекты
наблюдателей,
При этом Subject не должен вести список подписки самостоятельно.
Он предоставляет методы, с помощью которых наблюдатели могли бы
добавлять или убирать себя из списка.
Когда в Subject будет происходить важное событие, он будет
проходиться по списку подписчиков и оповещать их об этом, вызывая
определённый метод объектов-наблюдателей.*/
class Subject
{
    std::vector<IObserver*> list;
public:
    void Attach(IObserver *product) // метод для присоединения наблюдателя
    { list.push_back(product);//добавляем наблюдателя в list наблюдателей
    };
    void Detach(IObserver *product)//метод для отключения наблюдателя
    { list.erase(std::remove(list.begin(), list.end(), product), list.end());
    };
    void Notify(bool fileExist, int size); // метод, уведомляющий об обновлении данных
};
/*Этот класс является реальным классом, который
реализует Subject. Этот класс является сущностью, изменение которой
повлияет на другие объекты.*/
/*создает объекты ConcreteSubject и ConcreteObserver,а
затем регистрирует ConcreteObserver на обновления в
ConcreteSubject.*/
class FileSubject : public Subject
{
    QFile File; //поле, содержащее файл

public:
    FileSubject(const QString& fileName): File(fileName){}; // конструктор по умолчанию
    void updateObservers()//метод, уведомляющий об обновлении данных при работе с файлами
    { Notify(File.exists(),File.size());//уведомляем об обновлении данных
    };
};

#endif // SUBJ_H
