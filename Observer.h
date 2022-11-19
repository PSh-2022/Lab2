#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include <QString>

class IObserver//интерфейс файла
{
public:
    virtual void Update(bool fileExist, int size) = 0; //метод,определяющий состояние файла
};

class FileObserver :public IObserver//создание файла
{
    QString name; //название файла
    bool fileExist; //отметка о существовании файла
    int size;  //размер файла

public:
    FileObserver(QString _name = ""){name=_name;fileExist = false;size = 0;  }; // конструктор
    void Update(bool fileExist, int size); // метод,определяющий состояние файла
};
#endif // OBSERVER_H
