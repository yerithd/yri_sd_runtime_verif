/*
 * YRI_CPP_MONITOR_recovery_Object.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#ifndef YRI_CPP_MONITOR_RECOVERY_OBJECT
#define YRI_CPP_MONITOR_RECOVERY_OBJECT


#include "src/YRI_CPP_MONITOR.hpp"

#include "src/YRI_CPP_MONITOR_object.hpp"


class YRI_CPP_MONITOR;

class YRI_CPP_MONITOR_STATE;


class YRI_CPP_MONITOR_recovery_Object : public YRI_CPP_MONITOR_object
{
	Q_OBJECT


public:

    YRI_CPP_CLASS_OPERATORS


    inline YRI_CPP_MONITOR_recovery_Object(YRI_CPP_MONITOR        *A_RUNTIME_MONITOR,
                                          YRI_CPP_MONITOR_STATE  *a_source_state,
                                          YRI_CPP_MONITOR_STATE  *a_target_state)
    :YRI_CPP_MONITOR_object(),
     _A_RUNTIME_MONITOR(0),
     _A_SOURCE_STATE(a_source_state),
     _A_TARGET_STATE(a_target_state)
    {
    }


    virtual inline ~YRI_CPP_MONITOR_recovery_Object()
    {
    }


    virtual inline bool RUN_SQL_query_string()
    {
        QDEBUG_STRING_OUTPUT_1("RUN_SQL_query_string: NO QUERY TO RUN SET.");
    }


protected:

    inline YRI_CPP_MONITOR_recovery_Object()
    :YRI_CPP_MONITOR_object(),
    _A_RUNTIME_MONITOR(0)
    {
    }


    YRI_CPP_MONITOR          *_A_RUNTIME_MONITOR;

    YRI_CPP_MONITOR_STATE    *_A_SOURCE_STATE;

    YRI_CPP_MONITOR_STATE    *_A_TARGET_STATE;
};



#endif // YRI_CPP_MONITOR_RECOVERY_OBJECT
