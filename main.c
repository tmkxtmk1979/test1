#include <interrupt.h>

/* interrupt flag */
extern int interrupt;

unsigned int flag = 0;

void interrupt_handler(void) {
	if (interrupt & TIMERINT_MASK) {
		flag |= TIMERINT_MASK;
		interrupt &= ~TIMERINT_MASK;
	} else if (interrupt & PIOINT_MASK) {
		flag |= PIOINT_MASK;
		interrupt &= ~PIOINT_MASK;
	}
}

void sub_timerint() {
	/* */
}

void sub_pioint() {
	/* */
}

void main() {
	while (1) {
		/* */
		if (flag & TIMERINT_MASK) {
			sub_timerint();
		} else if (flag & PIOINT_MASK) {
			sub_pioint();
		} else {
			/* other int handler to be added... */
		}
	}
}
