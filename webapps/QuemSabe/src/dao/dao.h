#ifndef DAO_H
#define DAO_H

#include <memory>
#include <vector>
#include <iostream>
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

class Dao;
typedef shared_ptr<Dao> DaoPrt;

class Dao
{
    static DaoPrt instance;
    unique_ptr<sql::Connection> connection;
    Dao();
public:
    static DaoPrt getInstance();
    template<typename type> shared_ptr< vector<type> > select(string table, string where="", string options="")
    {
        shared_ptr< vector<type> > vec(new vector<type>);
        string sql = "SELECT * FROM "+table;
        sql += where.empty()?where:" WHERE "+where;
        sql += options.empty()?options:" OPTIONS "+options;
        unique_ptr<sql::Statement> stmt( connection->createStatement() );
        unique_ptr<sql::ResultSet> rs( stmt->executeQuery(sql) );
        while (rs->next()) {
            vec->push_back( type(*rs) );
        }
        rs->close();
        return vec;
    }

    template<typename type> long long insert(type obj)
    {
        long long id = -1;
        string sql = "INSERT INTO ";
        obj >> sql;
        unique_ptr<sql::Statement> stmt( connection->createStatement() );
        stmt->executeUpdate(sql);
        unique_ptr<sql::ResultSet> rs( stmt->executeQuery("SELECT LAST_INSERT_ID()") );

        if (rs->next())
            id = rs->getInt(1);
        rs->close();

        return id;
    }
};

#endif // DAO_H
