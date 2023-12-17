/*
 * YRI_CPP_MONITOR_ERP-database.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#include "YRI_CPP_MONITOR_ERP-database.hpp"


const QString YRI_CPP_MONITOR_ERP_database::MYSQL("MySQL");


QString YRI_CPP_MONITOR_ERP_database::_db_type("");

QString YRI_CPP_MONITOR_ERP_database::_db_name("");

QString YRI_CPP_MONITOR_ERP_database::_db_ip_address("");

QString YRI_CPP_MONITOR_ERP_database::_db_user_name("");

QString YRI_CPP_MONITOR_ERP_database::_db_user_pwd("");

QString YRI_CPP_MONITOR_ERP_database::_db_connection_options("");


YRI_CPP_MONITOR_ERP_database::YRI_CPP_MONITOR_ERP_database()
{
    set_db_name(YRI_CPP_MONITOR_ERP_database::_db_name);
    set_db_ip_address(YRI_CPP_MONITOR_ERP_database::_db_ip_address);
    set_db_user_name(YRI_CPP_MONITOR_ERP_database::_db_user_name);
    set_db_user_pwd(YRI_CPP_MONITOR_ERP_database::_db_user_pwd);
    set_db_type(YRI_CPP_MONITOR_ERP_database::_db_type);
    set_db_connection_options(YRI_CPP_MONITOR_ERP_database::
                              _db_connection_options);

    if (YRI_CPP_UTILS::
            isEqualsCaseInsensitive(YRI_CPP_MONITOR_ERP_database::MYSQL,
                                   YRI_CPP_MONITOR_ERP_database::_db_type))
    {
        //logger << "++ main(): QMYSQL" << "\n";
        _database = QSqlDatabase::addDatabase("QMYSQL");
    }

    _database.setDatabaseName(_db_name);
    _database.setHostName(_db_ip_address);
    _database.setUserName(_db_user_name);
    _database.setPassword(_db_user_pwd);
    _database.setConnectOptions(_db_connection_options);
}


void YRI_CPP_MONITOR_ERP_database::set_db_name(const QString &db_name)
{
    _db_name = db_name;
    _database.setDatabaseName(_db_name);
}


void YRI_CPP_MONITOR_ERP_database::set_db_ip_address(const QString &db_ip_address)
{
    _db_ip_address = db_ip_address;
    _database.setHostName(_db_ip_address);
}


void YRI_CPP_MONITOR_ERP_database::set_db_user_name(const QString &db_user_name)
{
    _db_user_name = db_user_name;
    _database.setUserName(_db_user_name);
}


void YRI_CPP_MONITOR_ERP_database::set_db_user_pwd(const QString &db_user_pwd)
{
    _db_user_pwd = db_user_pwd;
    _database.setPassword(_db_user_pwd);
}


void YRI_CPP_MONITOR_ERP_database::set_db_connection_options(const QString &
                                                            db_connection_options)
{
    _db_connection_options = db_connection_options;
    _database.setConnectOptions(_db_connection_options);

}


QString YRI_CPP_MONITOR_ERP_database::toString()
{
    QString ret;

    if (_database.isValid())
    {
        ret.append(QString("db_type: %1\n"
                           "db_name: %2\n"
                           "db_ip_address: %3\n"
                           "db_connection_options: %4").arg(_db_type,
                                                            _database.
                                                            databaseName(),
                                                            _database.
                                                            hostName(),
                                                            _database.
                                                            connectOptions
                                                            ()));
    }
    else
    {
        ret.append(QString("db_type: %1\n"
                           "db_name: %2\n"
                           "db_ip_address: %3\n"
                           "db_connection_options: %4").arg(_db_type,
                                                            YRI_CPP_MONITOR_ERP_database::
                                                            _db_name,
                                                            YRI_CPP_MONITOR_ERP_database::
                                                            _db_ip_address,
                                                            YRI_CPP_MONITOR_ERP_database::
                                                            _db_connection_options));
    }

    return ret;
}
