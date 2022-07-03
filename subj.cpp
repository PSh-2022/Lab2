#include "subj.h"

void Subject::Notify(bool fileExist, int size)
{
    //наблюдатели обновляются независимо
    for (int i = 0; i < list.size(); i++)
    { if (list[i] != nullptr)//если не нулевой
        {list[i]->Update(fileExist, size);//обновление файла
        }}
}

