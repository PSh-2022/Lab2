#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>
#include <vector>

template< class Observer >
class Observable //шаблонный класс с параметром Observer
{
public:
    virtual ~Observable() {}//предполагается наследование
    void registerObserver( Observer* observer )//создание связи с Наблюдателем
    {
        //m_count - счетчик входа в цикл, если m_count != 0, то добавление Наблюдателя невозможно
        if( m_count != 0 ) {
            m_requests.push_back( ObserverRequest { &Observable< Observer >::registerObserver, observer } );// запоминаем запрос на добавление Наблюдателя
        } else if( observer ) {
            m_observers.insert( observer );//добавляем Наблюдателя
        }
    }
    void unregisterObserver( Observer* observer ) //прекращение связи с Наблюдателем
    {
        //m_count - счетчик входа в цикл, если m_count != 0, то удаление Наблюдателя невозможно
        if( m_count != 0 ) {
            m_requests.push_back( ObserverRequest { &Observable< Observer >::unregisterObserver, observer } );// запоминаем запрос на удаление Наблюдателя
        } else if( observer ) {
            m_observers.erase( observer );//удаляем Наблюдателя
        }
    }

protected:
    Observable() : m_count( 0 ) {}

    template< typename F, typename... Args >
    void notifyObservers( F f, Args... args ) //уведомление Наблюдателей
    {
        ++m_count;
        for( Observer* o : m_observers ) {
            ( o->*f )( args... );//вызываем функцию-член f с аргументами args
        };
        --m_count;

        if( m_count == 0 ) //если m_count == 0 - можем пройти по всем запросам, которые могли поступить, и убрать/добавить Наблюдателей
        {
            for( const ObserverRequest& r : m_requests ) {
                ( this->*r.operation )( r.observer );
            };
            m_requests.clear();
        }
    }

private:
    struct ObserverRequest //структура, выражающая запросы на добавление/удалление Наблюдателя
    {
        void ( Observable< Observer >::*operation )( Observer* );//указатель на функцию-член класса Observable. Сигнатура указателя соответствует функциям registerObserver() и unregisterObserver()
        Observer* observer;//указатель на наблюдателя, для которого вызываем функцию-член из первого поля
    };

    std::set< Observer* > m_observers;//класс хранит указатели на объекты-Наблюдатели в множестве, чтобы предотвратить создание дублирующих
    int m_count;//счетчик входа в цикл
    std::vector< ObserverRequest > m_requests;//вспомогательный вектор для хранения запросов на добавление/удаление
};
#endif // OBSERVABLE_H
