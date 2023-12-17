/*
 * YRI_CPP_MONITOR_TRACE_EVENT.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */


#include "YRI_CPP_MONITOR_TRACE_EVENT.hpp"

#include "YRI_CPP_MONITOR_EVENT.hpp"



bool YRI_CPP_MONITOR_TRACE_EVENT::is_in_TRACE_EVENT(QString &A_TRACE_EVENT)
{
    YRI_CPP_MONITOR_EVENT *cur_Event_TO_CHECK = 0;

    for (int k = 0; k < _TRACE_EVENTS.size(); ++k)
    {
        cur_Event_TO_CHECK = _TRACE_EVENTS.at(k);

        if (0 != cur_Event_TO_CHECK)
        {
            if (cur_Event_TO_CHECK->get_EVENT_TOKEN() == A_TRACE_EVENT)
            {
                return true;
            }
        }
    }
    return false;
}
