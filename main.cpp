<<<<<<< HEAD
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
=======
#include "FileMonitor.h"
#include "FileObserver.h"
#include "Observable.h"
int main() {
    FileMonitor monitor( "test.txt" );//содаем объект-источник для отслеживания текстового файла
    ConsoleFileObserver observer;//создаем объект-Наблюдатель
    monitor.registerObserver( &observer );//связываем Наблюдателя с источником
    while( true ) {
        //обновляем состояние Источника каждые 300 миллисекунд
        monitor.checkFile();
        std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
    }
>>>>>>> master
    return 0;
}
/*Команды в консоли:
 * 1. при запуске - файл не существует
 * 2. touch test.txt - есть пустой файл
 * 3. echo "TEST" >> test.txt - файл существует, не пуст*/
