#include <iostream>
#include <pqxx/connection>
#include <pqxx/pqxx>
// ...

int main()
{
    try
    {
        pqxx::connection conn("dbname=nhcppdb user=moiseschirinos password=Asdf12345678\\# host=nhcppdb.postgres.database.azure.com port=5432");
        if (conn.is_open())
        {
            std::cout << "Conexión exitosa a PostgreSQL" << std::endl;
            pqxx::work tx(conn);
            tx.exec("INSERT INTO personas (nombre,nacionalidad,edad) VALUES ('moises',1,33)");
            tx.commit();
        }
        else
        {
            std::cout << "Error al conectar a PostgreSQL" << std::endl;
        }
        conn.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

// g++ postgresql.cpp -lpqxx -lpq
