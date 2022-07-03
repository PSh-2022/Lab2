#include "subj.h"
#include "Observer.h"
#include <chrono>
#include <thread>
#include <iostream>
int main()
{
    QString fileName1 = "C:\\Lab2\\file1.txt",fileName = "C:\\Lab2\\file.txt";//новый файл
    FileSubject test(fileName);//новый объект-файл
    FileObserver fo1(fileName1),fo2(fileName);//новый наблюдатель
    test.Attach(&fo1);// присоединяем наблюдателя 1
    test.Attach(&fo2);// присоединяем наблюдателя 2
    test.updateObservers();// обновление данных в наблюдателях
    test.Detach(&fo1);// отсоединяем наблюдателя 1
    test.updateObservers();// обновление данных в наблюдателях
    while(true) // отслеживаем состояние файла
       {
               std::this_thread::sleep_for(std::chrono::milliseconds(1000));
               test.updateObservers();
       }
    return 0;
}
