COMMON_OBJECTS	= toyMain.o
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: button.elf button-s.elf

button.elf: ${COMMON_OBJECTS} states.o buzzer.o led.o switches.o toyMain.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
button-s.elf: ${COMMON_OBJECTS} states-s.o buzzer.o led.o switches.o toyMain.o ../lib/libTimer.a
	${AS} ${CFLAGS} ${LDFLAGS} -o $@ $^

load-c: button.elf
	msp430loader.sh $^
load-s: button-s.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

toyMain.o: led.h switches.h buzzer.h
states.o: states.h
wdInterruptHandler.o: led.h switches.h buzzer.h
