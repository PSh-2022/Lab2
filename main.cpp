#include "subj.h"
#include "Observer.h"
#include <chrono>
#include <thread>
#include <iostream>
int main()
{
    QString fileName1 = "C:\\Lab2\\file1.txt", fileName = "C:\\Lab2\\file.txt";//названия файлов. fileName - существует, fileName1 - нет
   /* //существующий файл
    FileSubject test(fileName);//новый объект-файл для существующего файла
    FileObserver fo2(fileName);//новый наблюдатель
    test.Attach(&fo2);// присоединяем наблюдателя 2
    test.updateObservers();// первое обновление данных в наблюдателях - файл считается измененным
    while(true) // отслеживаем состояние файла
       {
               std::this_thread::sleep_for(std::chrono::milliseconds(1000));
               test.updateObservers();
       }*/
    //несуществующий файл
    FileSubject test(fileName1);//новый объект-файл для существующего файла
    FileObserver fo1(fileName1);//новый наблюдатель
    test.Attach(&fo1);// присоединяем наблюдателя 1
    test.updateObservers();// первое обновление данных в наблюдателях - файл считается измененным
    return 0;
}
/*Команды в консоли:
 * 1. при запуске - файл не существует
 * 2. touch test.txt - есть пустой файл
 * 3. echo "TEST" >> test.txt - файл существует, не пуст*/
