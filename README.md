# powerParametersDetection-Arduino

abstract: read bateery parateters, inculding voltage, electric current, the rest of energy and power, form LT-211 module by arduino mega2560. 

hardware:arduino mega2560; lith-baterry; baterry measuerment module LT-211: https://item.taobao.com/item.htm?spm=a1z09.2.0.0.f02f2e8dyfBUSX&id=17807208004&_u=61sqvu1j8b97

brief theory: LT-211 support MODBUS communication protocol, and just send pre-defined cmd char array to LT-211 by arduino mega2560 usart(default: usart1), and read returned cmd char array by arduino mega2560 usart buffer, and then extract message from char array by bit movement operation. 

comment: I just use MODBUS communication protocol simplely, and did not use CRC check code。
