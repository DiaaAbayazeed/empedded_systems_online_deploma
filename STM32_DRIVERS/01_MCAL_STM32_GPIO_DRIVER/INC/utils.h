/*
 * utils.h
 *
 *  Created on: 5 May 2021
 *      Author: Diaa Abayazeed
 */

#ifndef UTILS_H
#define UTILS_H

#define SETBIT(reg,bit)     (reg=reg |(1<<bit))

#define TOGGLEBIT(reg,bit)  (reg=reg ^(1<<bit))

#define CLEARBIT(reg,bit)   (reg=reg &~(1<<bit))

#define READBIT(reg,bit)    ((reg>>bit)&1)


#endif /* UTILS_H */