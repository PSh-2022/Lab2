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
    std::vector<IObserver*> list; //cписок всех наблюдателей
public:
    void Attach(IObserver *product) // присоединить наблюдателя
    { list.push_back(product);//фиксируем запрос на добавление
    };
    void Detach(IObserver *product)// отсоединить наблюдателя
    { list.erase(std::remove(list.begin(), list.end(), product), list.end());
    };
    void Notify(bool fileExist, int size); // уведомить об обновлении данных
};

class FileSubject : public Subject
{
    QFile File; // Объект файл

public:
    FileSubject(const QString& fileName): File(fileName){}; // Конструктор файла

    void updateObservers()// Обновление данных в наблюдателях
    { Notify(File.exists(),File.size());//уведомляем об обновлении данных
    };
};

#endif // SUBJ_H
