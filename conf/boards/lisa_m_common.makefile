# Hey Emacs, this is a -*- makefile -*-
#
 # Common makefile defines for Lia 1.1, Lisa M 2.0, and Lisa M 2.1
#

BOARD_CFG=\"boards/$(BOARD)_$(BOARD_VERSION).h\"

ARCH=stm32
$(TARGET).ARCHDIR = $(ARCH)
# not needed?
$(TARGET).OOCD_INTERFACE=ftdi/flossjtag
#$(TARGET).OOCD_INTERFACE=ftdi/jtagkey
$(TARGET).LDSCRIPT=$(SRC_ARCH)/lisa-m.ld

# -----------------------------------------------------------------------

# default flash mode is via usb dfu bootloader (luftboot)
# other possibilities: DFU-UTIL, JTAG, SWD, STLINK, SERIAL
FLASH_MODE ?= DFU

HAS_LUFTBOOT ?= 1
ifeq (,$(findstring $(HAS_LUFTBOOT),0 FALSE))
$(TARGET).CFLAGS+=-DLUFTBOOT
$(TARGET).LDFLAGS+=-Wl,-Ttext=0x8002000
endif

#
#
# some default values shared between different firmwares
#
#


#
# default LED configuration
#
RADIO_CONTROL_LED  ?= 4
BARO_LED           ?= none
AHRS_ALIGNER_LED   ?= 2
GPS_LED            ?= 3
SYS_TIME_LED       ?= 1


#
# default uart configuration
#
RADIO_CONTROL_SPEKTRUM_PRIMARY_PORT   ?= UART1
RADIO_CONTROL_SPEKTRUM_SECONDARY_PORT ?= UART5

MODEM_PORT ?= UART2
MODEM_BAUD ?= B57600

GPS_PORT ?= UART3
GPS_BAUD ?= B38400

#
# default PPM input is on PA01 (SERVO6)
#
RADIO_CONTROL_PPM_PIN ?= PA01
ifeq ($(RADIO_CONTROL_PPM_PIN),$(filter $(RADIO_CONTROL_PPM_PIN),PA_10 PA10 UART1_RX))
  PPM_CONFIG=1
else ifeq ($(RADIO_CONTROL_PPM_PIN),$(filter $(RADIO_CONTROL_PPM_PIN),PA_01 PA01 PA1 SERVO6))
  PPM_CONFIG=2
else
$(error Unknown RADIO_CONTROL_PPM_PIN, configure it to either PA01 or PA10)
endif

#
# default actuator configuration
#
# you can use different actuators by adding a configure option to your firmware section
# e.g. <configure name="ACTUATORS" value="actuators_ppm/>
# and by setting the correct "driver" attribute in servo section
# e.g. <servo driver="Ppm">
#
ACTUATORS ?= actuators_pwm
