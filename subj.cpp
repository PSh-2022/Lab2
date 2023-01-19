#include "subj.h"

void ASubject::Notify(bool fileExist, int size, QString fileName)
{
    for (int i = 0; i < list.size(); i++)//для всех наблюдаемых
    { if (list[i] != nullptr)//если не пуст
        {list[i]->Update(fileExist, size, fileName);//обновление информации о состоянии файла
        }}
}

