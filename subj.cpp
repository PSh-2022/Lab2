#include "subj.h"

void Subject::Notify(bool fileExist, int size)
{
    for (int i = 0; i < list.size(); i++)//для всех наблюдаемых
    { if (list[i] != nullptr)//если не пуст
        {list[i]->Update(fileExist, size);//обновление информации о состоянии файла
        }}
}

