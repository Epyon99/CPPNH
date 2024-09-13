#include <iostream>
#include <pqxx/connection>
#include <pqxx/pqxx>

int main()
{
    try
    {
        pqxx::connection conn("dbname=nhcppdb user=moiseschirinos password=Asdf12345678\\# host=nhcppdb.postgres.database.azure.com port=5432");
        if (conn.is_open())
        {
            std::cout << "Conexión exitosa a PostgreSQL" << std::endl;
            pqxx::work tx(conn);
            pqxx::result res = tx.exec("select * from Personas;");
            for (const auto &row : res)
            {
                std::cout << row["id"].as<std::string>();
                std::cout << ";";

                std::cout << row["nombre"].as<std::string>();
                std::cout << ";";

                std::cout << row["nacionalidad"].as<std::string>();
                std::cout << ";";

                std::cout << row["edad"].as<std::string>();
                std::cout << std::endl;
            }
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
