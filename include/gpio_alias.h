#include "gpio.h"
#define FILL_GPIO(_name, _pin, _port, _mode, _speed, _pullup) \
	 {\
		.name = _name,\
		.pin = _pin,\
		.port = _port,\
		.mode = _mode,\
		.speed = _speed,\
		.pullup = _pullup,\
	},
#define NUM_GPIO_ALIAS sizeof(GPIO_TABLE)/sizeof(GPIO)


const GPIO GPIO_TABLE[]={
	FILL_GPIO("PRESSURE1", 0, GPIOA, OUTPUT, MEDIUM_SPEED, NONE)
	FILL_GPIO("PRESSURE2", 0, GPIOA, OUTPUT, MEDIUM_SPEED, NONE)
	FILL_GPIO("PRESSURE3", 0, GPIOA, OUTPUT, MEDIUM_SPEED, NONE)
	FILL_GPIO("TEMP1", 0, GPIOA, OUTPUT, MEDIUM_SPEED, NONE)
	FILL_GPIO("TEMP2", 0, GPIOA, OUTPUT, MEDIUM_SPEED, NONE)
	FILL_GPIO("TEMP3", 0, GPIOA, OUTPUT, MEDIUM_SPEED, NONE)
	FILL_GPIO("REDLED", 14, GPIOB, OUTPUT, MEDIUM_SPEED, NONE)
	FILL_GPIO("BLUELED", 7, GPIOB, OUTPUT, MEDIUM_SPEED, NONE)
	FILL_GPIO("GREENLED", 0, GPIOB, OUTPUT, MEDIUM_SPEED, NONE)
};
