/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TIMERS					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 16 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMERs_interface.h"
#include "TIMERs_private.h"
#include "TIMERs_config.h"

/********************************************************************************************/
/********************			SWC: TIMER0					*********************************/
/********************************************************************************************/
pf TIMER0_pfOVFCallback = NULL;
pf TIMER0_pfCTCCallback = NULL;

void TIMER0_voidInit (void)
{
	/* select mode */
	#if TIMER0_MODE == TIMER0_OVF_MODE
		CLR_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
	#elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM_MODE
		SET_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
	#elif TIMER0_MODE == TIMER0_CTC_MODE
		CLR_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
	#elif TIMER0_MODE == TIMER0_FAST_PWM_MODE
		SET_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
	#endif
	/* select oc0 pin mode */
	#if TIMER0_OC0_PIN == TIMER0_OC0_DISCONNECTED
		CLR_BIT(TCCR0, TCCR0_COM00);
		CLR_BIT(TCCR0, TCCR0_COM01);
	#elif TIMER0_OC0_PIN == TIMER0_TOGGLE_OC0
		SET_BIT(TCCR0, TCCR0_COM00);
		CLR_BIT(TCCR0, TCCR0_COM01);
	#elif TIMER0_OC0_PIN == TIMER0_CLEAR_OC0
		CLR_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	#elif TIMER0_OC0_PIN == TIMER0_SET_OC0
		SET_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	#endif

}

void TIMER0_voidEnable (u8 Copy_u8Prescaler)
{

	TCCR0 &= PRESCALER_MASK;
	// to avoid any number higher than 7
	TCCR0 |= Copy_u8Prescaler & ~(PRESCALER_MASK);
}

void TIMER0_voidDisable (void)
{
	TCCR0 &= PRESCALER_MASK;
}

void TIMER0_voidEnableOVFInterrutpt (void)
{
	SET_BIT(TIMSK, TIMSK_TOIE0);
}

void TIMER0_voidDisableOVFInterrutpt (void)
{
	CLR_BIT(TIMSK, TIMSK_TOIE0);
}

void TIMER0_voidEnableCTCInterrutpt (void)
{
	SET_BIT(TIMSK, TIMSK_OCIE0);
}

void TIMER0_voidDisableCTCInterrutpt (void)
{
	CLR_BIT(TIMSK, TIMSK_OCIE0);
}

void TIMER0_voidSetCallbackOVF (pf pfOVFcall)
{
	if (pfOVFcall != NULL)
		TIMER0_pfOVFCallback = pfOVFcall;
}

void TIMER0_voidSetCallbackCTC (pf pfCTCcall)
{
	if (pfCTCcall != NULL)
		TIMER0_pfCTCCallback = pfCTCcall;
}

void TIMER0_voidSetPreloadValue (u8 Copy_u8Preload)
{
	TCNT0 = Copy_u8Preload;
}

void TIMER0_voidSetCTCValue (u8 Copy_u8CTCValue)
{
	OCR0 = Copy_u8CTCValue;
}

u8   TIMER0_u8ReadTCNT0Value (void)
{
	return TCNT0;
}

u8   TIMER0_u8ReadOCR0Value (void)
{
	return OCR0;
}

void TIMER0_u8ChangeMode (u8 Copy_u8Mode)
{

}

void TIMER0_voidDelayMS(u32 Copy_u32MilliSeconds)
{
	#if TIMER0_MODE == TIMER0_CTC_MODE
		static u8 Local_u8Flag = 1;
		u64 Local_u64Iterator = Copy_u32MilliSeconds * 4;
		if (Local_u8Flag)
		{
			TIMER0_voidSetCTCValue(250);
			TIMER0_voidInit();
			Local_u8Flag = 0;
		}
		TIMER0_voidEnable (TIMER0_PRESCALER_8);
		for (; Local_u64Iterator != 0; Local_u64Iterator--)
		{
			while (GET_BIT(TIFR, TIFR_OCF0) == 0);
			SET_BIT(TIFR, TIFR_OCF0);
		}
		TIMER0_voidDisable();
	#else
		#warning "TIMER0 Delay function won't work"
	#endif
}

void __vector_11 (void) __attribute__ ((signal, used));
void __vector_11 (void)
{
	if (TIMER0_pfOVFCallback != NULL)
		TIMER0_pfOVFCallback();
}

void __vector_10 (void) __attribute__ ((signal, used));
void __vector_10 (void)
{
	if (TIMER0_pfCTCCallback != NULL)
		TIMER0_pfCTCCallback();
}

/********************************************************************************************/
/********************			SWC: TIMER2					*********************************/
/********************************************************************************************/
pf TIMER2_pfOVFCallback = NULL;
pf TIMER2_pfCTCCallback = NULL;

void TIMER2_voidInit (void)
{
	/* select mode */
	#if TIMER2_MODE == TIMER2_OVF_MODE
		CLR_BIT(TCCR2, TCCR2_WGM20);
		CLR_BIT(TCCR2, TCCR2_WGM21);
	#elif TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM_MODE
		SET_BIT(TCCR2, TCCR2_WGM20);
		CLR_BIT(TCCR2, TCCR2_WGM21);
	#elif TIMER2_MODE == TIMER2_CTC_MODE
		CLR_BIT(TCCR2, TCCR2_WGM20);
		SET_BIT(TCCR2, TCCR2_WGM21);
	#elif TIMER2_MODE == TIMER2_FAST_PWM_MODE
		SET_BIT(TCCR2, TCCR2_WGM20);
		SET_BIT(TCCR2, TCCR2_WGM21);
	#endif
	/* select oc2 pin mode */
	#if TIMER2_OC2_PIN == TIMER2_OC2_DISCONNECTED
		CLR_BIT(TCCR2, TCCR2_COM20);
		CLR_BIT(TCCR2, TCCR2_COM21);
	#elif TIMER2_OC2_PIN == TIMER2_TOGGLE_OC2
		SET_BIT(TCCR2, TCCR2_COM20);
		CLR_BIT(TCCR2, TCCR2_COM21);
	#elif TIMER2_OC2_PIN == TIMER2_CLEAR_OC2
		CLR_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	#elif TIMER2_OC2_PIN == TIMER2_SET_OC2
		SET_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	#endif
}

void TIMER2_voidEnable (u8 Copy_u8Prescaler)
{
	TCCR2 &= PRESCALER_MASK;
	// to avoid any number higher than 7
	TCCR2 |= Copy_u8Prescaler & ~(PRESCALER_MASK);
}

void TIMER2_voidDisable (void)
{
	TCCR2 &= PRESCALER_MASK;
}

void TIMER2_voidEnableOVFInterrutpt (void)
{
	SET_BIT(TIMSK, TIMSK_TOIE2);
}

void TIMER2_voidDisableOVFInterrutpt (void)
{
	CLR_BIT(TIMSK, TIMSK_TOIE2);
}

void TIMER2_voidEnableCTCInterrutpt (void)
{
	SET_BIT(TIMSK, TIMSK_OCIE2);
}

void TIMER2_voidDisableCTCInterrutpt (void)
{
	CLR_BIT(TIMSK, TIMSK_OCIE2);
}

void TIMER2_voidSetCallbackOVF (pf pfOVFcall)
{
	if (pfOVFcall != NULL)
		TIMER2_pfOVFCallback = pfOVFcall;
}

void TIMER2_voidSetCallbackCTC (pf pfCTCcall)
{
	if (pfCTCcall != NULL)
		TIMER2_pfCTCCallback = pfCTCcall;
}

void TIMER2_voidSetPreloadValue (u8 Copy_u8Preload)
{
	TCNT2 = Copy_u8Preload;
}

void TIMER2_voidSetCTCValue (u8 Copy_u8CTCValue)
{
	OCR2 = Copy_u8CTCValue;
}

u8   TIMER2_u8ReadTCNT2Value (void)
{
	return TCNT2;
}

void TIMER2_voidAsynchronousMode (u8 Copy_u8Prescaler)
{
	TIMER2_voidDisableOVFInterrutpt();
	TIMER2_voidDisableCTCInterrutpt();
	SET_BIT(ASSR, ASSR_AS2);

	TIMER2_voidSetPreloadValue(0);
	TIMER2_voidSetCTCValue(0);
	TIMER2_voidEnable(Copy_u8Prescaler);
	TIMER2_voidUpdateAsynchronousMode();
	SET_BIT(TIFR, TIFR_TOV2);
	SET_BIT(TIFR, TIFR_OCF2);
}

void TIMER2_voidUpdateAsynchronousMode (void)
{
	while (GET_BIT(ASSR, ASSR_OCR2UB) | GET_BIT(ASSR, ASSR_TCN2UB) | GET_BIT(ASSR, ASSR_TCR2UB));
}

void __vector_4 (void) __attribute__ ((signal, used));
void __vector_4 (void)
{
	if (TIMER2_pfCTCCallback != NULL)
		TIMER2_pfCTCCallback();
}

void __vector_5 (void) __attribute__ ((signal, used));
void __vector_5 (void)
{
	if (TIMER2_pfOVFCallback != NULL)
		TIMER2_pfOVFCallback();
}
