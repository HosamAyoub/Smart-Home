/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: DIO					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 2 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef MCAL_DIO_PRIVATE_H_
#define MCAL_DIO_PRIVATE_H_

#define PORTA        	(*((volatile u8 *) 0x3B))
#define DDRA         	(*((volatile u8 *) 0x3A))
#define PINA         	(*((volatile u8 *) 0x39))

#define PORTB        	(*((volatile u8 *) 0x38))
#define DDRB         	(*((volatile u8 *) 0x37))
#define PINB         	(*((volatile u8 *) 0x36))

#define PORTC        	(*((volatile u8 *) 0x35))
#define DDRC         	(*((volatile u8 *) 0x34))
#define PINC         	(*((volatile u8 *) 0x33))

#define PORTD        	(*((volatile u8 *) 0x32))
#define DDRD         	(*((volatile u8 *) 0x31))
#define PIND         	(*((volatile u8 *) 0x30))


#define REG_SIZE		8


#define CONC(P0, P1, P2, P3, P4, P5, P6, P7) CONC_HELPER(P0, P1, P2, P3, P4, P5, P6, P7)
#define CONC_HELPER(P0, P1, P2, P3, P4, P5, P6, P7) 0b##P7##P6##P5##P4##P3##P2##P1##P0
#define PORTA_DIR CONC(DIO_PA0_DIR, DIO_PA1_DIR, DIO_PA2_DIR, DIO_PA3_DIR, DIO_PA4_DIR, DIO_PA5_DIR, DIO_PA6_DIR, DIO_PA7_DIR)
#define PORTB_DIR CONC(DIO_PB0_DIR, DIO_PB1_DIR, DIO_PB2_DIR, DIO_PB3_DIR, DIO_PB4_DIR, DIO_PB5_DIR, DIO_PB6_DIR, DIO_PB7_DIR)
#define PORTC_DIR CONC(DIO_PC0_DIR, DIO_PC1_DIR, DIO_PC2_DIR, DIO_PC3_DIR, DIO_PC4_DIR, DIO_PC5_DIR, DIO_PC6_DIR, DIO_PC7_DIR)
#define PORTD_DIR CONC(DIO_PD0_DIR, DIO_PD1_DIR, DIO_PD2_DIR, DIO_PD3_DIR, DIO_PD4_DIR, DIO_PD5_DIR, DIO_PD6_DIR, DIO_PD7_DIR)

#endif /* MCAL_DIO_PRIVATE_H_ */
