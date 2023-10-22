/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TIMERS					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 16 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef MCAL_TIMERS_TIMERS_PRIVATE_H_
#define MCAL_TIMERS_TIMERS_PRIVATE_H_

/********************************************************************************************/
/********************			SWC: TIMER0					*********************************/
/********************************************************************************************/

#define TCCR0                    					(*(volatile u8 *) 0x53)
#define TCCR0_WGM00									6
#define TCCR0_COM01									5
#define TCCR0_COM00									4
#define TCCR0_WGM01									3
#define TCNT0                    					(*(volatile u8 *) 0x52)
#define OCR0                     					(*(volatile u8 *) 0x5C)
#define TIMSK                    					(*(volatile u8 *) 0x59)
#define TIMSK_TOIE0									0
#define TIMSK_OCIE0									1

#define TIFR                     					(*(volatile u8 *) 0x58)
#define TIFR_OCF0									1
#define TIFR_TOV0									0


#define PRESCALER_MASK								0b11111000

#define TIMER0_OVF_MODE								0
#define TIMER0_CTC_MODE								1
#define TIMER0_FAST_PWM_MODE						2
#define TIMER0_PHASE_CORRECT_PWM_MODE				3

#define TIMER0_OC0_DISCONNECTED						4
#define TIMER0_TOGGLE_OC0							5
#define TIMER0_CLEAR_OC0							6
#define TIMER0_SET_OC0								7

/********************************************************************************************/
/********************			SWC: TIMER2					*********************************/
/********************************************************************************************/

#define TCCR2                                       (*(volatile u8 *) 0x45)
#define TCCR2_WGM20                                 6
#define TCCR2_COM21                                 5
#define TCCR2_COM20                                 4
#define TCCR2_WGM21                                 3

#define TCNT2                                       (*(volatile u8 *) 0x44)
#define OCR2                                        (*(volatile u8 *) 0x43)
#define ASSR                                        (*(volatile u8 *) 0x42)
#define ASSR_AS2                                    3
#define ASSR_TCN2UB                                 2
#define ASSR_OCR2UB                                 1
#define ASSR_TCR2UB                                 0

#define TIMSK_TOIE2									6
#define TIMSK_OCIE2									7

#define TIFR_TOV2									6
#define TIFR_OCF2									7

#define TIMER2_OVF_MODE								0
#define TIMER2_CTC_MODE								1
#define TIMER2_FAST_PWM_MODE						2
#define TIMER2_PHASE_CORRECT_PWM_MODE				3

#define TIMER2_OC2_DISCONNECTED						4
#define TIMER2_TOGGLE_OC2							5
#define TIMER2_CLEAR_OC2							6
#define TIMER2_SET_OC2								7

#endif /* MCAL_TIMERS_TIMERS_PRIVATE_H_ */
