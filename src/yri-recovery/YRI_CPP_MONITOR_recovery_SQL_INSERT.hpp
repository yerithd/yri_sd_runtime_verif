/*
 * YRI_CPP_MONITOR_recovery_SQL_INSERT.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#ifndef _YRI_CPP_MONITOR_RECOVERY_SQL_INSERT_
#define _YRI_CPP_MONITOR_RECOVERY_SQL_INSERT_


#include "YRI_CPP_MONITOR_recovery_Object.hpp"


class YRI_CPP_MONITOR_STATE;


/**
 * WE ONLY SUPPORT "MISSING DATABASE TABLE COLUMN VALUE DEFINITION" as
 * DESCRIBED IN yerith_qvge user's guide (https://zenodo.org/record/8387240).
 */

class YRI_CPP_MONITOR_recovery_SQL_INSERT : public YRI_CPP_MONITOR_recovery_Object
{
	Q_OBJECT


public:

    YRI_CPP_CLASS_OPERATORS


    inline YRI_CPP_MONITOR_recovery_SQL_INSERT(YRI_CPP_MONITOR        *A_RUNTIME_MONITOR,
                                              YRI_CPP_MONITOR_STATE  *a_source_state,
                                              YRI_CPP_MONITOR_STATE  *a_target_state)
    :YRI_CPP_MONITOR_recovery_Object(A_RUNTIME_MONITOR,
                                    a_source_state,
                                    a_target_state)
    {
    }


    virtual inline ~YRI_CPP_MONITOR_recovery_SQL_INSERT()
    {
    }


    virtual bool RUN_SQL_query_string();


    virtual QString build_SQL_QUERY_STRING_for_ERROR_STATE_SAFE_RECOVERY();


protected:

    inline YRI_CPP_MONITOR_recovery_SQL_INSERT()
    :YRI_CPP_MONITOR_recovery_Object()
    {
    }


    QString ___SQL_INSERT_QUERY_for_ERROR_STATE_SAFE_RECOVERY;
};



#endif // _YRI_CPP_MONITOR_RECOVERY_SQL_INSERT_
