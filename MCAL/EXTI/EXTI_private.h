/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: EXTI					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 12 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


#define MCUCR				        (*(volatile u8*) 0x55)
#define GICR						(*(volatile u8*) 0x5B)
#define GICR_INT0					6

#define GIFR                        (*(volatile u8*) 0x5A)


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
