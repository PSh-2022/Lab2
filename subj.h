#ifndef SUBJ_H
#define SUBJ_H
#include <iostream>
#include <vector>
#include "Observer.h"
#include <QFile>
#include <QString>

//класс отслеживает наблюдателей, позволяет добавлять и удалять их
class Subject
{
    std::vector<IObserver*> list; // список адресов наблюдателей
public:
    void Attach(IObserver *product) // метод для присоединения наблюдателя
    { list.push_back(product);//фиксируем запрос на добавление
    };
    void Detach(IObserver *product)//метод для отключения наблюдателя
    { list.erase(std::remove(list.begin(), list.end(), product), list.end());
    };
    void Notify(bool fileExist, int size); // метод, уведомляющий об обновлении данных
};

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
