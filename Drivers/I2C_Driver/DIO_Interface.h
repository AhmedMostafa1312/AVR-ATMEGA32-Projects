/*
 * DIO_Interface.h
 *
 *  Created on: Apr 13, 2018
 *      Author: ahmed
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_vidPortIdentification(u8 Copy_u8PinNibblePortNumber);

void DIO_vidSetPinDirection(u8 Copy_u8PinNumber,u8 copy_u8PinDirection);
void DIO_vidSetLowNibbleDirection(u8 Copy_u8LowNibbleNumber,u8 copy_u8LowNibbleDirection);
void DIO_vidSetHighNibbleDirection(u8 Copy_u8HighNibbleNumber,u8 copy_u8HighNibbleDirection);
void DIO_vidSetPortDirection(u8 Copy_u8PortId,u8 copy_u8PortDirection);

void DIO_vidSetPinValue(u8 Copy_u8PinNumber,u8 copy_u8PinValue);
void DIO_vidTogglePinValue(u8 Copy_u8PinNumber);
void DIO_vidSetLowNibbleValue(u8 Copy_u8LowNibbleNumber,u8 copy_u8LowNibblevalue);
void DIO_vidToggleLowNibbleValue(u8 Copy_u8LowNibbleNumber);
void DIO_vidAssignLowNibbleValue(u8 Copy_u8LowNibbleNumber,u8 Copy_u8LowNibbleValue);
void DIO_vidSetHighNibbleValue(u8 Copy_u8HighNibbleNumber,u8 copy_u8HighNibblevalue);
void DIO_vidToggleHighNibbleValue(u8 Copy_u8HighNibbleNumber);
void DIO_vidAssignHighNibbleValue(u8 Copy_u8HighNibbleNumber,u8 Copy_u8HighNibbleValue);
void DIO_vidSetPortValue(u8 Copy_u8PortId,u8 copy_u8Portvalue);
void DIO_vidTogglePortValue(u8 Copy_u8PortId);
void DIO_vidAssignPortValue(u8 Copy_u8PortId,u8 Copy_u8PortValue);

u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber);
u8 DIO_u8GetLowNibbleValue(u8 Copy_u8LowNibbleNumber);
u8 DIO_u8GetHighNibbleValue(u8 Copy_u8HighNibbleNumber);
u8 DIO_u8GetPortValue(u8 Copy_u8PortId);

/***************************** SPI Master/Slave DIO Configurations ******************************/
void DIO_vidSPIMasterPinConfigurations(void);
void DIO_vidSPISlavePinConfigurations(void);


/*-----for all 32 pins-----*/
/*port A*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
/*port B*/
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15
/*port C*/
#define PIN16 16
#define PIN17 17
#define PIN18 18
#define PIN19 19
#define PIN20 20
#define PIN21 21
#define PIN22 22
#define PIN23 23
/*port D*/
#define PIN24 24
#define PIN25 25
#define PIN26 26
#define PIN27 27
#define PIN28 28
#define PIN29 29
#define PIN30 30
#define PIN31 31

/*-----for low nibbles-----*/
/*port A*/
#define LOW_NIBBLE_0 0
/*port B*/
#define LOW_NIBBLE_1 8
/*port C*/
#define LOW_NIBBLE_2 16
/*port D*/
#define LOW_NIBBLE_3 24

/*-----for high nibbles-----*/
/*port A*/
#define HIGH_NIBBLE_0 4
/*port B*/
#define HIGH_NIBBLE_1 12
/*port C*/
#define HIGH_NIBBLE_2 20
/*port D*/
#define HIGH_NIBBLE_3 28

/*-----for ports-----*/
/*port A*/
#define PORT_A 0
/*port B*/
#define PORT_B 8
/*port C*/
#define PORT_C 16
/*port D*/
#define PORT_D 24

/*-----for setting pin direction-----*/
#define OUTPUT 0
#define INPUT_PULL_UP 1
#define INPUT_HIGH_Z 2

/*-----for setting pin value in output case-----*/
#define LOW 0
#define HIGH 1

#endif /* DIO_INTERFACE_H_ */
