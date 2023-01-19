#include "subj.h"
#include "Observer.h"
#include <chrono>
#include <thread>
#include <iostream>
int main()
{
    QString fileName = "C:\\Lab2\\file.txt";
    QFile File(fileName);
    ConcretFile test;//реализация объекта - наблюдаемого для существующего файла
    ConsoleFile::instance();//реализация объекта - наблюдателя
    test.Attach(&ConsoleFile::instance());// присоединяем наблюдателя 2
    test.Notify(File.exists(),File.size(), fileName);// первое обновление данных в наблюдателях - файл считается измененным
    while(true) // отслеживаем состояние файла с временным промежутком
       {
               std::this_thread::sleep_for(std::chrono::milliseconds(500));
               test.Notify(File.exists(),File.size(), fileName);
       }
    return 0;
}
