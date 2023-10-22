/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: EXTI					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 12 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

void EXTI_voidINT0Init (void);
void EXTI_voidINT0Enable (void);
void EXTI_voidINT0Disable (void);
void EXTI_voidINT0SetTrigger (u8 Local_u8CopyTrigger);
void EXTI_voidSetCallBack (pf pfCallback);

#define EXTI_INT0_LOW_LEVEL					0
#define EXTI_INT0_RISING_EDGE               1
#define EXTI_INT0_FALLING_EDGE              2
#define EXTI_INT0_ON_CHANGE                 3

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
