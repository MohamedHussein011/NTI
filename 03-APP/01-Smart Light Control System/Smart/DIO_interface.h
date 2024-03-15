/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: DIO_interface.h	            ************************/
/***************************************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*********************************		Error classification	******************************/
//Invalid Port Pin ID requested
#define DIO_E_PARAM_INVALID_PIN_ID			0x0A
//Invalid Port ID requested
#define DIO_E_PARAM_INVALID_PORT_ID			0x0B
//APIs called with a Null Pointer
#define DIO_E_PARAM_POINTER					0x0C
//Invalid Port Pin Direction requested
#define DIO_E_PARAM_INVALID_PIN_DIR			0x0D
//Invalid Port Pin Value requested
#define DIO_E_PARAM_INVALID_PIN_VAL			0x0E
//Invalid Port Direction requested
#define DIO_E_PARAM_INVALID_PORT_DIR		0x0F
//Invalid Port Value requested
#define DIO_E_PARAM_INVALID_PORT_VAL	    0x10

                             /*************** MACROS FOR PORT ***************/
/* macros for port id */
#define DIO_PORTA			    0
#define DIO_PORTB			    1
#define DIO_PORTC			    2
#define DIO_PORTD			    3

/* macros for port direction */
#define DIO_PORT_INPUT          0x00              //Sets port as input (default state)
#define DIO_PORT_OUTPUT			0xff              //Sets port as output

/* macros for port value */
#define DIO_PORT_LOW            0x00             //Sets port Low (default state)
#define DIO_PORT_HIGH			0xff             //Sets port as High

                             /*************** MACROS FOR PIN ***************/
/* macros for pin id */
#define DIO_PIN0			    0
#define DIO_PIN1			    1
#define DIO_PIN2			    2
#define DIO_PIN3			    3
#define DIO_PIN4			    4
#define DIO_PIN5			    5
#define DIO_PIN6			    6
#define DIO_PIN7			    7

/* macros for pin direction */
#define DIO_PIN_INPUT           0         //Sets port pin as input (default state)
#define DIO_PIN_OUTPUT			1         //Sets port pin as output

/* macros for pin value */
#define DIO_PIN_LOW             0         //Sets port pin Low (default state)
#define DIO_PIN_HIGH			1         //Sets port pin as High


/********************************				Function Prototypes				********************************/
/* @brief		shall initialize ALL ports and port pins
*				with the configuration set in DIO_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void DIO_voidInit(void);

/* Pin Apis */
/* @brief		shall set the port pin direction during runtime
* @paramin		copy_u8PortId / Port ID number - copy_u8PinId / Port Pin ID number - copy_u8PinDirection / Port Pin Direction
* @paramout		none
* @retval		Error state of wrong paramin
*/
u8 DIO_u8SetPinDirection            (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection);

/* @brief		shall set the port pin value during runtime
* @paramin		copy_u8PortId / Port ID number - copy_u8PinId / Port Pin ID number - copy_u8PinValue / Port Pin Value
* @paramout		none
* @retval		Error state of wrong paramin
*/
u8 DIO_u8SetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue);

/* @brief		shall get the port pin value during runtime
* @paramin		copy_u8PortId / Port ID number - copy_u8PinId / Port Pin ID number - copy_pu8PinValue / Port Pin Value
* @paramout		copy_pu8PinValue / value of port pin
* @retval		Error state of wrong paramin
*/
u8 DIO_u8GetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue);

/* @brief		shall toggle the port pin value during runtime
* @paramin		copy_u8PortId / Port ID number - copy_u8PinId / Port Pin ID number
* @paramout		none
* @retval		Error state of wrong paramin
*/
u8 DIO_u8TogglePinValue             (u8 copy_u8PortId, u8 copy_u8PinId);

/* @brief		shall set the port pin as input pullup during runtime
* @paramin		copy_u8PortId / Port ID number - copy_u8PinId / Port Pin ID number
* @paramout		none
* @retval		Error state of wrong paramin
*/
u8 DIO_u8ActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId);

/* Port Apis */	
/* @brief		shall set the port direction during runtime
* @paramin		copy_u8PortId / Port ID number - copy_u8PortDirection / Port Direction
* @paramout		none
* @retval		Error state of wrong paramin
*/
u8 DIO_u8SetPortDirection            (u8 copy_u8PortId, u8 copy_u8PortDirection);

/* @brief		shall set the port value during runtime
* @paramin		copy_u8PortId / Port ID number - copy_u8PortValue / Port Value
* @paramout		none
* @retval		Error state of wrong paramin
*/
u8 DIO_u8SetPortValue                (u8 copy_u8PortId, u8 copy_u8PortValue);

/* @brief		shall get the port value during runtime
* @paramin		copy_u8PortId / Port ID number - copy_pu8PortValue / Port Value
* @paramout		copy_pu8PortValue / value of port
* @retval		Error state of wrong paramin
*/
u8 DIO_u8GetPortValue                (u8 copy_u8PortId, u8* copy_pu8PortValue);

/* @brief		shall toggle the port value during runtime
* @paramin		copy_u8PortId / Port ID number
* @paramout		none
* @retval		Error state of wrong paramin
*/
u8 DIO_u8TogglePortValue             (u8 copy_u8PortId);

/* @brief		shall set the port as input pullup during runtime
* @paramin		copy_u8PortId / Port ID number
* @paramout		none
* @retval		Error state of wrong paramin
*/
u8 DIO_u8ActivePortInPullUpResistance(u8 copy_u8PortId);


#endif /* DIO_INTERFACE_H_ */
