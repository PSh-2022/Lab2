#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "FileObserver.h"
#include "Observable.h"
#include <iostream>
#include <chrono>
#include <thread>

#include <sys/stat.h>
 //класс-Источник, использует класс Observable, посылает Наблюдателям сообщения о произошедших с файлом изменениях
class FileMonitor : public Observable< FileObserver > {
public:
    FileMonitor( const char* fileName )://конструктор, принимает имя файла, состояние которого нужно отслеживать
        m_fileName( fileName ), m_prevFileState( getFileState( m_fileName ) ) //также инициализируется переменная m_prevFileState, сохраняющая состояние файла, которое было на момент создания объекта класса
    {};
    void checkFile() //функция проверки состояния файла
    {
        FileState fileState = getFileState( m_fileName );//получаем состояние файла, возвращает заполненную структуру FileState
        if( fileState != m_prevFileState )//если изменилось состояние
        {
            notifyObservers( &FileObserver::onFileChanged, fileState );//уведомляем Наблюдателей
            m_prevFileState = fileState;//перезаписываем состояние
        }
    };
private:
    static FileState getFileState( const std::string& fileName )//функция, показывающая состояние файла
    {
        FileState fileState;
        struct stat statBuf;
        fileState.exists = stat( fileName.c_str(), &statBuf ) == 0;//используем функцию стандартной библиотеки
        fileState.size = fileState.exists ? statBuf.st_size : 0;//заполняем поле размера файла - с помощью statBuf, если файл существует, иначе 0
        return fileState;//возвращаем заполненную структуру
    };
private:
    std::string m_fileName;//имя файла
    FileState m_prevFileState;//структура состояния файла
};

#endif // FILEMONITOR_H
