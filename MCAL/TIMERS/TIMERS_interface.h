/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TIMERS					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 16 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef MCAL_TIMERS_TIMERS_INTERFACE_H_
#define MCAL_TIMERS_TIMERS_INTERFACE_H_

/********************************************************************************************/
/********************			SWC: TIMER0					*********************************/
/********************************************************************************************/

void TIMER0_voidInit (void);
void TIMER0_voidEnable (u8 Copy_u8Prescaler);
void TIMER0_voidDisable (void);
void TIMER0_voidEnableOVFInterrutpt (void);
void TIMER0_voidDisableOVFInterrutpt (void);
void TIMER0_voidEnableCTCInterrutpt (void);
void TIMER0_voidDisableCTCInterrutpt (void);
void TIMER0_voidSetCallbackOVF (pf pfOVFcall);
void TIMER0_voidSetCallbackCTC (pf pfCTCcall);
void TIMER0_voidSetPreloadValue (u8 Copy_u8Preload);
void TIMER0_voidSetCTCValue (u8 Copy_u8CTCValue);
u8   TIMER0_u8ReadTCNT0Value (void);
void TIMER0_u8ChangeMode (u8 Copy_u8Mode);
void TIMER0_voidDelayMS(u32 Copy_u32MilliSeconds);

#define TIMER0_PRESCALER_1															1
#define TIMER0_PRESCALER_8						    								2
#define TIMER0_PRESCALER_64					        								3
#define TIMER0_PRESCALER_256                            							4
#define TIMER0_PRESCALER_1024                           							5
#define TIMER0_PRESCALER_EXTERNAL_SOURCE_CLOCK_ON_FALLING_EDGE                      6
#define TIMER0_PRESCALER_EXTERNAL_SOURCE_CLOCK_ON_RISIGN_EDGE                       7


/********************************************************************************************/
/********************			SWC: TIMER2					*********************************/
/********************************************************************************************/
void TIMER2_voidInit (void);
void TIMER2_voidEnable (u8 Copy_u8Prescaler);
void TIMER2_voidDisable (void);
void TIMER2_voidEnableOVFInterrutpt (void);
void TIMER2_voidDisableOVFInterrutpt (void);
void TIMER2_voidEnableCTCInterrutpt (void);
void TIMER2_voidDisableCTCInterrutpt (void);
void TIMER2_voidSetCallbackOVF (pf pfOVFcall);
void TIMER2_voidSetCallbackCTC (pf pfCTCcall);
void TIMER2_voidSetPreloadValue (u8 Copy_u8Preload);
void TIMER2_voidSetCTCValue (u8 Copy_u8CTCValue);
u8   TIMER2_u8ReadTCNT2Value (void);
void TIMER2_voidAsynchronousMode (u8 Copy_u8Prescaler);
void TIMER2_voidUpdateAsynchronousMode (void);

#define TIMER2_PRESCALER_1															1
#define TIMER2_PRESCALER_8						    								2
#define TIMER2_PRESCALER_32					        								3
#define TIMER2_PRESCALER_64	                            							4
#define TIMER2_PRESCALER_128	                           							5
#define TIMER2_PRESCALER_256								                      	6
#define TIMER2_PRESCALER_1024                       								7


#endif /* MCAL_TIMERS_TIMERS_INTERFACE_H_ */
