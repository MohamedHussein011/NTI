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

void GI_voidEnable (void);
void GI_voidDisable (void);

#endif 
