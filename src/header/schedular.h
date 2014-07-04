/**
 *       \file       schedular.h
 *
 *       \brief      Rate Monotonic Schedular Manager
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, simakmandeep@gmail.com
 *       \license    GNU General Public License Version 2\n
 *       \copyright  Copyright (c) 2014, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#ifndef  SCHEDULAR_H
#define  SCHEDULAR_H

#include "header.h"


/**
 *      \class  Schedular
 *      \brief  Implementing Rate Monotonic Scheduling Algorithm
 */

class Schedular
{
    private:
        int maxTask;                                           /**< Max Task */
        float maxProUtilization;           /**< Total Processor Utilization by
                                                all tasks */

        FLOAT_2DVEC taskExeTime,                     **< Task Execution Time */
                    taskPeriod,                              **< Task Period */
                    taskUtiliation;               /**< Processor Utilization */
        
        STRING_2DVEC taskPriority;                      /**< Task's Priority */

    public:        
        void ProcessorUtilization(int maxTask);
        bool IsTaskSchedulable(float maxUtilization);
}

#endif   /* #ifndef SCHEDULAR_H */

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */ 
