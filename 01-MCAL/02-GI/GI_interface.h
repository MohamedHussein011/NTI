/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: GI_interface.h	            ************************/
/***************************************************************************************/

#ifndef GI_INTERFACE_H
#define GI_INTERFACE_H


/*Enable Global interrupt - Set I*/
#define sei()     __asm__ __volatile__("sei" ::: "memory")

/*Disable Global interrupt - Clear I*/
#define cli()     __asm__ __volatile__("cli" ::: "memory")

/********************************				Function Prototypes				********************************/

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

/* @brief		shall get Global interrupt flag
* @paramin		none
* @paramout		none
* @retval		Global interrupt flag
*/
u8 GI_u8GetFlag (void);


#endif 
