/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: EXTI					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 12 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

pf Global_pfINT0Call = NULL;

void EXTI_voidINT0Init (void)
{
#if EXTI_INT0_SENSE_MODE == EXTI_INT0_LOW_LEVEL
	CLR_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);
#elif EXTI_INT0_SENSE_MODE == EXTI_INT0_ON_CHANGE
	SET_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);
#elif EXTI_INT0_SENSE_MODE == EXTI_INT0_FALLING_EDGE
	CLR_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);
#elif EXTI_INT0_SENSE_MODE == EXTI_INT0_RISING_EDGE
	SET_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);
#else
#error "EXTI_INT0_SENSE_MODE is out of range"
#endif
}

void EXTI_voidINT0Enable (void)
{
	SET_BIT(GICR, GICR_INT0);
}

void EXTI_voidINT0Disable (void)
{
	CLR_BIT(GICR, GICR_INT0);
}

void EXTI_voidINT0SetTrigger (u8 Local_u8CopyTrigger)
{
	switch (Local_u8CopyTrigger)
	{
		case EXTI_INT0_LOW_LEVEL:
			CLR_BIT(MCUCR, 0);
			CLR_BIT(MCUCR, 1);
			break;
		case EXTI_INT0_ON_CHANGE:
			SET_BIT(MCUCR, 0);
			CLR_BIT(MCUCR, 1);
			break;
		case EXTI_INT0_FALLING_EDGE:
			CLR_BIT(MCUCR, 0);
			SET_BIT(MCUCR, 1);
			break;
		case EXTI_INT0_RISING_EDGE:
			SET_BIT(MCUCR, 0);
			SET_BIT(MCUCR, 1);
			break;
		default:
			break;
	}
}

void EXTI_voidSetCallBack (pf pfCallback)
{
	if (pfCallback != NULL)
	{
		Global_pfINT0Call = pfCallback;
	}
	else
	{
		// do nothing
	}
}

void __vector_1 (void) __attribute__ ((signal, used));
void __vector_1 (void)
{
	Global_pfINT0Call();
}
