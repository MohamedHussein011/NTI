/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: Std_Types.h		            ************************/
/***************************************************************************************/

#ifndef _STD_TYPES_H
#define _STD_TYPES_H

#define NULL ( (void *)0 )

typedef unsigned char        u8;            /*           0 .. 255             */
typedef unsigned short int   u16;           /*           0 .. 65535           */
typedef unsigned long  int   u32;           /*           0 .. 4294967295      */

typedef signed char          s8;            /*        -128 .. +127            */
typedef signed short int     s16;           /*      -32768 .. +32767          */
typedef signed long  int     s32;           /* -2147483648 .. +2147483647     */

typedef float f32;
typedef double f64;

typedef void (*pvFunction_t) (void);           /*Pointer to function*/

#define OK               0
#define NOK              1
#define IDLE             2
#define BUSY             3
#define NULLPOINTER      4
#define TIMEOUT_STATE    5
#define WORKING          6
#define NOT_WORKING      7
#define OUT_RANGE        8
#define TRUE			 9
#define FALSE 			 10

#endif
