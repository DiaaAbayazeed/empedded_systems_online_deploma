
# Round Robin-based Real Time Operating System 

In this project I used CMSIS_V5 from ARM for porting the required hardware







## Support

Feel Free to contact me, just message me at

linkedin: https://www.linkedin.com/in/diaa-aba-yazeed-74538218b/.


## MY-RTOS Features

- Support The basic operation of any RTOS.
- Scheduler based on priority - Highest Priority Should Run First-
- Support Round-Robin Scheduling when two or more tasks have the same priority.
- The IDLE task enter sleep mode and waiting for an event.


## User API Reference

#### MYRTOS_init
- The first function needed to be run
- This function is used to initialize the os by porting the required hardware, creating the main stack for the os and creating the idle task with it is stack.

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `Nothing` | `void` |  |

#### MYRTOS_STARTOS
- The second function needed to be run
- This function is used to to update the os state, start the systick time, activate the idle task and make the sp to shadow to psp of idle task instead of msp.

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `Nothing`      | `void` | |

#### MYRTOS_CreateTask

- This function is used to to create the task by creating a TCB for the task ,add the TCB to OS table and reserve the required stack for the task.

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `Task`      | `Task_ref*` |The user need to conigure some properties of the task and pass the Task_ref as a pointer  |

#### MYRTOS_ActivateTask
After creating the task you need to activate it ,this function update the task state ,and make a svc call then the svc update scheduling table based on priority and determine the next task to be run then the dispatcher make the appropriate task run using the pendsv interrupt and making all the required context switch. 

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `Tref`    | `Task_ref*` |  |

#### MYRTOS_TerminateTask
This funcion is used to terminate task by updating the task state ,and make a svc call then the svc update scheduling table based on priority and the state then determine the next task to be run then the dispatcher make the appropriate task run using the pendsv interrupt and making all the required context switch.  

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `Tref`    | `Task_ref*` |  |


#### MYRTOS_TaskWait
This funcion is used to make the task for a number of mile seconds by updating the task state ,enabling the blocking property ,set the number of ticks the task will wait then systick is responsible to enable the task again after the number of ticks determined.   

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `SelfTref`  | `Task_ref*` |  |
| `NoTICKS`   | `u32` | The number of mile-seconds the task need to wait |


## Task Priority Example
Task1 priority < Task2 priority < Task3 priority < Task4 priority

![Task Priority](https://github.com/DiaaAbayazeed/empedded_systems_online_deploma/blob/main/MY_RTOS/priorities.png)

## Round Robin Example
Task1 priority == Task2 priority == Task3 priority == Task4 priority  

![Round Robin](https://github.com/DiaaAbayazeed/empedded_systems_online_deploma/blob/main/MY_RTOS/roundrobin.png)

## Task Waiting With High Pirority Example
Task3 is the highest piority it run for a while then waited until the time of wating end throw this time task 1
and task 2 run 

![Priority Inversion ](https://github.com/DiaaAbayazeed/empedded_systems_online_deploma/blob/main/MY_RTOS/Task%20wating%20%20analyzer.png)
