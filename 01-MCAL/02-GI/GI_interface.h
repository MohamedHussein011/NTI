/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: GI_interface.h	            ************************/
/***************************************************************************************/

#ifndef GI_INTERFACE_H
#define GI_INTERFACE_H

//enable or disable global interrupt
#define GI_ENABLE				0
#define GI_DISABLE				1


/*Enable Global interrupt - Set I*/
#define sei()     __asm__ __volatile__("sei" ::: "memory")


/*Disable Global interrupt - Clear I*/
#define cli()     __asm__ __volatile__("cli" ::: "memory")

/********************************				Function Prototypes				********************************/

/* @brief		shall initialize Global interrupt
*				with the configuration set in GI_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void GI_voidInit(void);

/* @brief		shall enable Global interrupt during runtime
* @paramin		none
* @paramout		none
* @retval		none
*/
void GI_voidEnable (void);

/* @brief		shall disable Global interrupt during runtime
* @paramin		none
* @paramout		none
* @retval		none
*/
void GI_voidDisable (void);

#endif 
