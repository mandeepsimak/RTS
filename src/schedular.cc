/**
 *       \file       schedular.cc
 *
 *       \brief      Class definition for RMS Scheduling
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, simakmandeep@gmail.com
 *       \license    GNU General Public License Version 2\n
 *       \copyright  Copyright (c) 2014, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#include "header/schedular.h"

Schedular :: Schedular()
{
   maxProUtilization = 0; 
}

/**
 *      \class  Schedular
 *      \fn     Schedular :: ProcessorUtilization(int maxTask)
 *      \brief  Processor Utilization Rule requires that processor utilization
 *              be calculated based upon the period and execution time of
 *              each task.
 *              
 *              The processor utilization can be calculated as follows:
 *
 *              Utilization = 0
 *
 *              for index = 1 to maximum_tasks
 *
 *              Utilization = Utilization + (Time(index)/Period(index))
 *
 *      \param  maxTask Total no of task for scheduling
 */

void Schedular :: ProcessorUtilization(int maxTask)
{
    for(auto i = 0; i < maxTask; i++)
    {
        taskUtiliation[i] = (taskExeTime[i] / taskPeriod[i]) ;

        maxProUtilization += taskUtiliation[i];    
    }
}

/**
 *      \class  Schedular
 *      \fn     Schedular :: IsTaskSchedulable(int maxProUtilization, 
 *              int maxTask)
 *      \brief  To insure schedulability even under transient overload
 *              
 *              The processor utilization must adhere to the following rule:
 *
 *              Utilization = maximum_tasks * (2(1/maximum_tasks) - 1)
 *
 *      \param  maxProUtilization  Max. processor utilization by all tasks
 *      \param  maxTask Max. no of tasks
 *      \retrn  Returns true if tasks are schedulable otherwise false
 */

bool Schedular :: IsTaskSchedulable(float maxProUtilization, int maxTask)
{
    float two = 2, one = 1;
    /* 
    cout << "1/maxtask: " << (1/(float)maxTask) << "\t 2*result: " ;
            float val = (((float)2 * (1/(float)maxTask)));
            cout  <<  "val "  <<  val <<  endl;
    cout << " \t -1 "  <<(float) ( (float)maxTask * (float)(val) )
//            << (float) ( ((float)maxTask * (2 * (1/(float)maxTask))) -1) 
            << endl;
*/
    cout  << (float) ((float)3 * (float)((float)2 * (float)(1/(float)3) - (float)1))  <<  endl;
    overloadProUtilization = ((float)maxTask * (float)((two * (one / (float)maxTask)) - one));

    cout << "max: " << maxProUtilization << "\t over:" << overloadProUtilization << endl;
    
    if(maxProUtilization < overloadProUtilization)
        return true;
    else
        return false;
}


/**
 *      \class  Schedular
 *      \fn     Schedular :: Main()
 *      \brief  Main function for calling other functions and implementing
 *              schedular
 */

void Schedular :: Main()
{
/*     cout << "\nRate Monotonic Schedular" << endl
         << "\nEnter maximum no. of tasks: ";*/
    cin >> maxTask;

    taskPeriod.resize(maxTask);
    taskPriority.resize(maxTask);
    taskExeTime.resize(maxTask);
    taskUtiliation.resize(maxTask);

//    cout << "Enter details of task:" << endl;

    for(auto i = 0; i < maxTask; i++)
    {
//        cout << "Task " << (i + 1) << endl
//             << "Priority (H:High | M:Medium | L:Low): ";
//        cin >> taskPriority[i];
//        cout << "Period: ";
        cin >> taskPeriod[i];
//        cout << "Execution Time: ";
        cin >> taskExeTime[i] ;
    }

    ProcessorUtilization(maxTask);
   
    if(IsTaskSchedulable(maxProUtilization, maxTask))
    {
        cout << "\n Tasks are schedulable!" << endl;
    }
    else
        cout << "\n Tasks are not schedulable!" << endl;
}

Schedular :: ~Schedular()
{

}

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */ 
