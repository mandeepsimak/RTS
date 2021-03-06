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
        int maxTask,                                           /**< Max Task */
            unschedulableEvent;

        float maxProUtilization,          /**< Total Processor Utilization 
                                              by all tasks */
              overloadProUtilization,          /**< processor utilization 
                                                 under transient overload*/
              deadlineTime;               /**<time to check if tasks meet
                                            their deadlines in case they exceed
                                            processor utilization Upper Limit*/


        FLOAT_VEC taskExeTime,                      /**< Task Execution Time */
                  taskPeriod,                               /**< Task Period */
                  taskUtilization;                 /**< Processor Utilization */
                  
          INT_VEC taskPriority;                        /**< Task's Priority */

    public:
        Schedular();
        void ProcessorUtilization(float maxTask);
        bool Theorem2(float maxTask);
        bool ResponseTimeMethod(float maxTask);
        void Main();
        void Timeline(int);
        
        ~Schedular();
};

#endif   /* #ifndef SCHEDULAR_H */

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */ 
