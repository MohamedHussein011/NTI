/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: Platform_Types.h               ************************/
/***************************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

//Vendor ID (vendorId) according to the AUTOSAR vendor list.
#define PLATFORM_VENDOR_ID							100U

//Module ID of this module
#define PLATFORM_MODULE_ID							199U

/*AUTOSAR Module version 4.4.0*/
#define PLATFORM_AR_RELEASE_MAJOR_VERSION				4U
#define PLATFORM_AR_RELEASE_MINOR_VERSION				4U
#define PLATFORM_AR_RELEASE_REVISION_VERSION			0U

/*Module version 1.0.0*/
#define PLATFORM_SW_MAJOR_VERSION						1U
#define PLATFORM_SW_MINOR_VERSION						0U
#define PLATFORM_SW_PATCH_VERSION						0U


/*CPU Register width*/
#define CPU_TYPE_8				8U				//Indicating a 8 bit processor
#define CPU_TYPE_16				16U				//Indicating a 16 bit processor
#define CPU_TYPE_32				32U				//Indicating a 32 bit processor
#define CPU_TYPE_64				64U				//Indicating a 64 bit processor

/*
 * Bit order definition
 */
#define MSB_FIRST					0U				//The most significant bit is the first bit of the bit sequence
#define LSB_FIRST					1U				//The least significant bit is the first bit of the bit sequence

/*
 * Byte order definition
 */
#define HIGH_BYTE_FIRST				0U				//Within uint16, the high byte is located before the low byte
#define LOW_BYTE_FIRST				1U				//Within uint16, the low byte is located before the high byte

/*
 * Boolean Values
 */
typedef unsigned char boolean;
#ifndef TRUE
#define TRUE				0x01U
#endif

#ifndef FALSE
#define FALSE				0x00U
#endif

typedef unsigned char 			uint8;				/*range: 0		-->		255 */
#define UINT8_MIN				0x00
#define UINT8_MAX				0xFF

typedef unsigned short 			uint16;				/*range: 0		-->		65535 */
#define UINT16_MIN				0x00
#define UINT16_MAX				0xFFFF

typedef unsigned long		    uint32;				/*range: 0		-->		4294967295 */
#define UINT32_MIN				0x00
#define UINT32_MAX				0xFFFFFFFF

typedef unsigned long long 		uint64;				/*range: 0		-->		18446744073709551615 */
#define UINT64_MIN				0x00
#define UINT64_MAX				0xFFFFFFFFFFFFFFFF

typedef signed char 			sint8;				/*range: -128						-->		127 */
#define SINT8_MIN				0x80
#define SINT8_MAX				0x7F

typedef signed short 			sint16;				/*range: -32768						-->		32767 */
#define SINT16_MIN				0x8000
#define SINT16_MAX				0x7FFF

typedef signed long 			sint32;				/*range: -2147483648				-->		2147483647 */
#define SINT32_MIN				0x80000000
#define SINT32_MAX				0x7FFFFFFF

typedef signed long long 		sint64;				/*range: -9223372036854775808		-->		9223372036854775807 */
#define SINT64_MIN				0x8000000000000000
#define SINT64_MAX				0x7FFFFFFFFFFFFFFF

typedef float 					float32;				/*range: -1.17549435e-38		-->		3.40282347e+38 */
typedef double 					float64;

typedef void* VoidPtr;
typedef const void* ConstVoidPtr;





#endif
