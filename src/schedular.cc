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
#include <cmath>

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

void Schedular :: ProcessorUtilization(float maxTask)
{
    for(float i = 0; i < maxTask; i++)
    {
        taskUtilization[i] = (taskExeTime[i] / taskPeriod[i]) ;

        maxProUtilization += taskUtilization[i];
        
        
        overloadProUtilization = ((i+1) * (pow (2.0, 1 / (i+1)) - 1));

        if(maxProUtilization > overloadProUtilization)
        	unschedulableEvent = i+1;	
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
 *              Utilization = maximum_tasks * (2^(1/maximum_tasks) - 1)
 *	
 *      \param  maxProUtilization  Max. processor utilization by all tasks
 *      \param  maxTask Max. no of tasks
 *      \retrn  Returns true if tasks are schedulable otherwise false
 */

bool Schedular :: IsTaskSchedulable(float maxProUtilization, float maxTask)
{
    if(!unschedulableEvent)
		return true;

    else
    {
    	cout<<"\nTasks not Schedulable by Processor Utilization Rule";
    	cout<<"\nApplying the First Deadline Principal"<<endl;

    	float a0=0,a1,check=0;

    	for(auto i = 0; i < unschedulableEvent; i++)
    		a0 += taskExeTime[i];

    		for(int z = 0; z < unschedulableEvent; z++)
			{				
				a1=0;
				
				for(int j=0; j<(unschedulableEvent-1); j++)
					a1 += (ceil(a0/taskPeriod[j]))*taskExeTime[j];
				a1 += taskExeTime[unschedulableEvent-1];
				
				if(a1==a0)
					{
						check=1;
						goto label;
					}
				else
					a0=a1;
			}

			label:
			if(check==1)	
				return true;
			else	
				return false;
    }
}

/**
 *      \class  Schedular
 *      \fn     Schedular :: Timeline(float maxTask)
 *      \brief  If the tasks are schedulable then
 *				Sort the tasks according to priority(1/period)
 *
 *				Generate a timeline for all the tasks
 *
 *      \param  maxTask Max. no of tasks
 */

void Schedular :: Timeline(float maxTask)
{

	for(float i=0; i<maxTask; i++)
	{
        auto min=i;
        
        for(float j=i+1;j<maxTask;j++)
        {
        	if(taskPeriod[min] > taskPeriod[j])
            {
                min=j;
            }
        }

        auto tmp = taskPeriod[min];
        taskPeriod[min] = taskPeriod[i];
        taskPeriod[i] = tmp;

        auto tmp1 = taskExeTime[min];
        taskExeTime[min] = taskExeTime[i];
        taskExeTime[i] = tmp1;

        auto tmp2 = taskPriority[min];
        taskPriority[min] = taskPriority[i];
        taskPriority[i] = tmp2;
    }

    cout<<"\nTask Prority is as follows(Decreasing order):";
    for(float i=0; i<maxTask; i++)
    	cout<<"task"<<taskPriority[i]<<" ";
    	cout<<endl;

    cout<<"\n\tTIMELINE"
    	<<"\nTask\tFrom\tTo";

    auto timeCheck=0;
    vector<int> periodCheck;
    periodCheck.resize(maxTask);

    for(float i=0; i<maxTask; i++)
    {
    	cout<<"\n"<<taskPriority[i]
    		<<"\t"<<timeCheck
    		<<"\t"<<timeCheck+taskExeTime[i];

    	timeCheck += taskExeTime[i];
    	periodCheck[i]=1;
    }

    while(timeCheck < taskPeriod[maxTask-1])
    {
    	for (auto i = 0; i < maxTask; ++i)
    	{ 
    		if(timeCheck >= taskPeriod[i]*periodCheck[i])
    		{
    			cout<<"\n"<<taskPriority[i]
    				<<"\t"<<timeCheck
    				<<"\t"<<timeCheck+taskExeTime[i];

    			timeCheck += taskExeTime[i];			
    			periodCheck[i]++;
    		}	
    	}
    }
}

/**
 *      \class  Schedular
 *      \fn     Schedular :: Main()
 *      \brief  Main function for calling other functions and implementing
 *              schedular
 */

void Schedular :: Main()
{
    cout << "\nRate Monotonic Schedular" << endl
          << "\nEnter maximum no. of tasks: ";
    cin >> maxTask;

    taskPeriod.resize(maxTask);
    taskPriority.resize(maxTask);
    taskExeTime.resize(maxTask);
    taskUtilization.resize(maxTask);


    for(auto i = 0; i < maxTask; i++)
    {
    	cout<<"\nEnter Period";
        cin >> taskPeriod[i];

        cout<<"\nEnter Exe time";
        cin >> taskExeTime[i] ;

        taskPriority[i]=i+1;
    }

    ProcessorUtilization(maxTask);
   
    if(IsTaskSchedulable(maxProUtilization, maxTask))
    {
        cout << "\n Tasks are schedulable!" << endl;
    
        Timeline(maxTask);
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
