#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H
#include <iostream>
//структура для отслеживания состояния конкретного файла
struct FileState {
    //оператор для оповещения Наблюдателей об изменениях состояния файла
    bool operator!=( const FileState& other ) {
        if( this == &other ) {
            return false;
        }
        return exists != other.exists || size != other.size;
    }
    bool exists;//существование файла
    int size;//размер файла
};

//класс Наблюдатель
//интерфейсный класс Наблюдателя
class FileObserver {
public:
    virtual ~FileObserver() { }//виртуальный деструктор
    virtual void onFileChanged( const FileState& state ) = 0;//изменение в состоянии файла
};
//класс Наблюдатель
class ConsoleFileObserver : public FileObserver {
public:
    ~ConsoleFileObserver(){};//деструктор
    void onFileChanged( const FileState& state );//изменение в состоянии файла
};

void ConsoleFileObserver::onFileChanged( const FileState& state ) {
    std::cout << std::endl;
    std::cout << "File state changed " << std::endl;//состояние изменено
    std::cout << "  File exist " << std::endl;//файл существует
    std::cout << "  Size: " << state.size << std::endl;//размер файла
    std::cout << std::endl << std::endl;
}

#endif // FILEOBSERVER_H
