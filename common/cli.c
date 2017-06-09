#include <stdio.h>
#include "config.h"
#include "pcbuffer.h"

char buffer[BUFSIZ];

int _write(int fd, const void *buf, size_t count) {
	for (fd = 0; fd < count; fd++) {
		while (pc_buffer_full(&usart3_tx)) {;}
		pc_buffer_add(&usart3_tx, *((char *) buf++));
	}
	USB_UART->CR1 |= USART_CR1_TXEIE;
	return count;
}

int _read(int fd, const void *buf, size_t count) {
	for (fd = 0; fd < count; fd++) {
		while (pc_buffer_empty(&usart3_rx)) {;}
		pc_buffer_remove(&usart3_rx, (char *) buf++);
	}
	return count;
}

void _ttywrch(int ch) {
	while (pc_buffer_full(&usart3_tx)) {;}
	pc_buffer_add(&usart3_tx, (char) ch);
	USB_UART->CR1 |= USART_CR1_TXEIE;
}

inline void printPrompt(void) {
	printf("=> ");
}

void processCommand(void) {
	if (pc_buffer_getMessage(&USB_RX, buffer, BUFSIZ)) {
		if (buffer[0] != '\0') {
			/* need to pull the characters out of the buffer */
			printf("Got: %s\r\n", buffer);
		}
		printPrompt();
	}
}
