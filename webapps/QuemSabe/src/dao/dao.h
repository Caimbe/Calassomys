#ifndef DAO_H
#define DAO_H

#include <memory>
#include <cppdb/frontend.h>

using namespace std;

class Dao;
typedef shared_ptr<Dao> DaoPrt;

class Dao
{
    cppdb::session sql;
    static DaoPrt instance;
    Dao();
public:
    static DaoPrt getInstance();
    template<typename type> int insert(type obj)
    {
        cppdb::statement stat;
        stat = obj >> sql;
        stat.exec();
        return stat.last_insert_id();
    }
};

#endif // DAO_H
