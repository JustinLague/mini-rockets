const osThreadAttr_t mainHeader_attr = {
  .priority = (osPriority_t) osPriorityHigh, //Set initial thread priority to high
  .stack_size = 4096
};


void initMainTask() {
	osThreadId_t main_id = osThreadNew(startMainTask, NULL, &mainHeader_attr);
	SEGGER_RTT_WriteString(0, "Init main task\r\n");
}
