#include "app_usb.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"

const osThreadAttr_t usbHeader_attr = {
  .priority = (osPriority_t) osPriorityNormal, //Set initial thread priority to high
  .stack_size = 1024
};


void initUSBTask() {
	osThreadId_t usb_id = osThreadNew(USBTask, NULL, &usbHeader_attr);
	SEGGER_RTT_WriteString(0, "Init usb task\r\n");
}

__NO_RETURN void USBTask() {

	while(1) {
		osDelay(10);
	}
}
