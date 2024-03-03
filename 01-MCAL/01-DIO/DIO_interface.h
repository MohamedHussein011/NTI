/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: DIO_interface.h	            ************************/
/***************************************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

                             /*************** ERRORS ***************/
#define DIO_E_PARAM_INVALID_PIN_ID			0x0A
#define DIO_E_PARAM_INVALID_PORT_ID			0x0B
#define DIO_E_PARAM_POINTER					0x0C
#define DIO_E_PARAM_INVALID_PIN_DIR			0x0D
#define DIO_E_PARAM_INVALID_PIN_VAL			0x0E
#define DIO_E_PARAM_INVALID_PORT_DIR		0x0F
#define DIO_E_PARAM_INVALID_PORT_VAL	    0x10

                             /*************** MACROS FOR PORT ***************/
/* macros for port id */
#define DIO_PORTA			    0
#define DIO_PORTB			    1
#define DIO_PORTC			    2
#define DIO_PORTD			    3

/* macros for port direction */
#define DIO_PORT_INPUT          0x00
#define DIO_PORT_OUTPUT			0xff

/* macros for port value */
#define DIO_PORT_LOW            0x00
#define DIO_PORT_HIGH			0xff

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
#define DIO_PIN_INPUT           0
#define DIO_PIN_OUTPUT			1

/* macros for pin value */
#define DIO_PIN_LOW             0
#define DIO_PIN_HIGH			1


                             /*************** APIS PROTO TYPES ***************/
/*		Init 	 */
void DIO_voidInit(void);

/* Pin Apis */							
u8 DIO_u8SetPinDirection            (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection);
u8 DIO_u8SetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue);
u8 DIO_u8GetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue);
u8 DIO_u8TogglePinValue             (u8 copy_u8PortId, u8 copy_u8PinId);
u8 DIO_u8ActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId);

/* Port Apis */	
u8 DIO_u8SetPortDirection            (u8 copy_u8PortId, u8 copy_u8PortDirection);
u8 DIO_u8SetPortValue                (u8 copy_u8PortId, u8 copy_u8PortValue);
u8 DIO_u8GetPortValue                (u8 copy_u8PortId, u8* copy_pu8PortValue);
u8 DIO_u8TogglePortValue             (u8 copy_u8PortId);
u8 DIO_u8ActivePortInPullUpResistance(u8 copy_u8PortId);


#endif /* DIO_INTERFACE_H_ */
