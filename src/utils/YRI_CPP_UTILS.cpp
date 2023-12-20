/*
 * YRI_CPP_UTILS.CPP
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#include "YRI_CPP_UTILS.hpp"


#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QtCore/QDebug>
#include <QtCore/QProcess>


QString
YRI_CPP_UTILS::YRI_HEARDER_hpp_TEMPLATE_RUNTIME_MONITOR = "";

QString
YRI_CPP_UTILS::YRI_SOURCE_cpp_TEMPLATE_RUNTIME_MONITOR = "";


const QString YRI_CPP_UTILS::EMPTY_STRING("");


const QString YRI_CPP_UTILS::STRING_delete("DELETE");

const QString YRI_CPP_UTILS::STRING_insert("INSERT");

const QString YRI_CPP_UTILS::STRING_select("SELECT");

const QString YRI_CPP_UTILS::STRING_update("UPDATE");

const QString YRI_CPP_UTILS::STRING_DB_STMT_UNDEFINED("UNDEFINED");


QMap < uint, QString > YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString;


YRI_CPP_UTILS::YRI_CPP_UTILS()
{
    YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.
    insert(YRI_CPP_UTILS::DELETE, YRI_CPP_UTILS::STRING_delete);

    YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.
    insert(YRI_CPP_UTILS::INSERT, YRI_CPP_UTILS::STRING_insert);

    YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.
    insert(YRI_CPP_UTILS::SELECT, YRI_CPP_UTILS::STRING_select);

    YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.
    insert(YRI_CPP_UTILS::UPDATE, YRI_CPP_UTILS::STRING_update);

    YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.
    insert(YRI_CPP_UTILS::UNDEFINED_SQL_COMMAND,
           YRI_CPP_UTILS::STRING_DB_STMT_UNDEFINED);
}


void YRI_CPP_UTILS::YERITH_READ_FILE_CONTENT(QFile &file,
                                            QString &fileContentVar)
{
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);

        QString line;

        do
        {
            line = stream.readLine().trimmed();

            fileContentVar.append(line).append("\n");
        }
        while (!line.isNull());

        file.close();
    }
}


void YRI_CPP_UTILS::qDebugStrings(const QString &firstString,
                                 const QStringList &aStringList)
{
    qDebug() << QString("++ %1: ").arg(firstString) << aStringList;
}


void YRI_CPP_UTILS::qDebugStrings(const QString &firstString,
                                 const QString &secondString
                                 /* = YerothUtils::EMPTY_STRING */)
{
    qDebug() << QString("++ %1: %2").arg(firstString, secondString);
}


bool YRI_CPP_UTILS::execQuery(const QString &strQuery,
                             bool           dbg_MSG /* = false */)
{
    QSqlQuery query;

    query.prepare(strQuery);

    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (dbg_MSG)
    {
        QDEBUG_STRING_OUTPUT_2("YRI_CPP_UTILS::execQueryRowCount; execQuery",
                                query.executedQuery());
    }

    if (!success)
    {
        if (dbg_MSG)
        {
            qDebug() << "\t\t" << strQuery;

            qDebug() << "\t\t[reason for failing] "
                     << query.lastError().text();
        }
    }

    return success;
}


int YRI_CPP_UTILS::execQueryRowCount(const QString &strQuery,
                                     bool           dbg_MSG /* = false */)
{
    QSqlQuery query;

    query.prepare(strQuery);

    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (dbg_MSG)
    {
        QDEBUG_STRING_OUTPUT_2("YRI_CPP_UTILS::execQueryRowCount; execQuery",
                                query.executedQuery());
    }

    if (!success)
    {
        if (dbg_MSG)
        {
            qDebug() << "\t\t" << strQuery;

            qDebug() << "\t\t[reason for failing] "
                     << query.lastError().text();
        }
    }

    return query.size();
}


int
YRI_CPP_UTILS::start_PROCESS_AND_READ_PROCESS_output_INTO_FILE
(const QString &program_executable_location_full_path,
 const QString &output_file_full_path,
 const QStringList &program_executable_args)
{
    QProcess
    A_YEROTH_PROCESS;

    A_YEROTH_PROCESS.start(program_executable_location_full_path,
                           program_executable_args);

    if (!A_YEROTH_PROCESS.waitForFinished())
    {
        return -1;
    }

    QFile
    tmpFile(output_file_full_path);

    if (tmpFile.open(QFile::WriteOnly))
    {
        tmpFile.write(A_YEROTH_PROCESS.readAllStandardOutput().trimmed());
    }
    else
    {
        return -1;
    }

    int
    output_file_size = tmpFile.size();

    tmpFile.close();

    return output_file_size;
}
