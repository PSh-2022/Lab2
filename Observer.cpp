#include "Observer.h"
#include <QTextStream>

void FileObserver::Update(bool _fileExist, int _size) // обновление файла
{
    QTextStream cout(stdout); // поток для вывода в консоль
    if(_fileExist) // если файл существует
    {if (size == _size) //если размер файла не изменился
        {if(_size!=0) //если файл не пустой
            {cout<< "File " << name << " exists and is not empty\n"<< "Size: " << _size<< '\n';}}
     else//если размер изменился
        {cout<< "File " << name << " exists, has been modified\n"<< "Size: " << _size<<'\n';}
    }
    else//если файл не существует
    {cout<< "File " << name << " does not exist\n"; }
    size=_size;
    fileExist=_fileExist;
}
