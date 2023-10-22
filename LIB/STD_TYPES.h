/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: LIB					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 2 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef	STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char			u8;
typedef signed char 			s8;

typedef unsigned int 			u16;
typedef signed int 				s16;


typedef unsigned long int 		u32;
typedef signed long int 		s32;

typedef unsigned long long int 	u64;
typedef signed long long int 	s64;

typedef float 					f32;
typedef double 					f64;
typedef long double				f96;


#define NULL 					(void *)0
#define REG_SIZE				8

typedef enum {
	OK,
	ERROR,
	PARAMETER_OUT_RANGE,
	POINTER_OUT_OF_RANGE,
	TWI_StartConditionError,
	TWI_RepeatedStartConditionError,
	TWI_SlaveAddressWithWriteAcknowledgmentError,
	TWI_SlaveAddressWithReadAcknowledgmentError,
	TWI_MasterWriteByteWithAcknowledgmentError,
	TWI_MasterReadByteWithAcknowledgmentError
}tenumErrorStatus;

typedef void (* pf) (void);

#endif
