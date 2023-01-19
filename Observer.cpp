#include "Observer.h"
#include <QTextStream>

QString ConsoleFile::name = "";
bool ConsoleFile::fileExist = 0;
int ConsoleFile::size = 0;

void ConsoleFile::Update(bool _fileExist, int _size, QString fileName) // метод обновления информации о существовании файла и его размере
{
    QTextStream cout(stdout); // поток для вывода в консоль
    name = fileName;
    static bool changed = 0, notexist = 0;
    if(_fileExist) // если файл существует
    {if (size == _size || !changed) //если размер файла не изменился и файл не пустой
        {
            if( _size != 0 && !changed)
                cout<< "File " << name << " exists and is not empty\n"<< "Size: " << _size<< '\n';
            changed = 1;
        }
     else//если размер изменился
        cout<< "File " << name << " exists, has been modified\n"<< "Size: " << _size<<'\n';
    size=_size;
    }
    else//если файл не существует
    {if(!notexist)
        {cout<< "File " << name << " does not exist\n";
        notexist = 1;
        changed = 0;}}

    fileExist=_fileExist;
}
