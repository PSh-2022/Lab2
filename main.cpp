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
    return 0;
}
/*Команды в консоли:
 * 1. при запуске - файл не существует
 * 2. touch test.txt - есть пустой файл
 * 3. echo "TEST" >> test.txt - файл существует, не пуст*/
