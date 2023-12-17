/*
 * YRI_CPP_MONITOR_object.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */


#include "YRI_CPP_MONITOR_object.hpp"


uint
YRI_CPP_MONITOR_object::MONITOR_OBJECTS_CURRENT_ID_GENERATOR = 0;


YRI_CPP_MONITOR_object::~YRI_CPP_MONITOR_object()
{
    _MONITOR_OBJECT_ID = -1;
}
