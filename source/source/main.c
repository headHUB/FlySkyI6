/*
 * Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * This is template for main module created by New Kinetis SDK 2.x Project Wizard. Enjoy!
 **/

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "delay.h"
#include "fsl_gpio.c"
#include "lcd.h"
#include "console.h"
#include "screen.h"
#include "debug.h"
#include "adc.h"
#include "backlight.h"
#include "MKL16Z4.h"
#include "fsl_common.h"
#include "fsl_dma.h"
#include "fsl_dmamux.h"
#include "fsl_uart.h"
#include "flysky.h"
#include "mod.h"
#include "alt.h"
#include "ibustelemetry.h"


/*
 *
typedef uint32_t (*divFun)(uint32_t, uint32_t);
typedef int (*sprintfFun)(char* buffer, const char* format, ...);

const sprintfFun sprintfCall = (sprintfFun) 0x19F8;
*/
char buffer[32];


int main(void) {
  BOARD_InitPins();
  BOARD_BootClockRUN();
  BOARD_SysTick();
  lcd_init();
  for(int i =0; i < 1024; i++) screen_buffer[i]= 0;
  console_init();
  adc_init();
  BOARD_InitDebugConsole();
  backlightInit();
  debug_init();
  (*(uint32_t *)(MODEL_SETTINGS)) = 0x200002AE;
  unsigned char* buf = 0;
  getSensorName(2);
  loadModSettings();
  saveModSettings();
  printTimer();
  if( strLenCall((const char*)RADIO_MODES)){
	  init(10000);
	   getALT(10000);
	   acData(buf);
  }
  acData(buf);

  //if( strLenCall((const char*)&modConfig)){

	  getALT(10000);
 //}
 // if( strLenCall((const char*)longSensors)){

	  getALT(10000);

//   }
//  if( strLenCall((const char*)timerBuffer)){
	  getALT(10000);
	  //timerVal +=1;
//  }
  displayMenu();
  TimerConfig();
  BatteryType();
  strLenCall((const char*)txBat);
  strLenCall((const char*)altSensor);

  ChackCustomAlarms();

//strLenCall((const char*)extraMenu);
//strLenCall((const char*)alarm);
//strLenCall((const char*)timerValueStr);
//strLenCall((const char*)timerChannel);
//strLenCall((const char*)timerStartWhen);
//strLenCall((const char*)timerOff);
//strLenCall((const char*)timer);
//strLenCall((const char*)timerNull);
//strLenCall((const char*)timerFormat);
  //keep this one because of without usage signature block will be removed
  if(SIGNATURE[0] == 1){

  }
  formatSensorValue((char *)SIGNATURE, 0,0);
  //divFun dev = (divFun)0x1E5E;
  //char* format = "%d";
  //sprintfCall(buffer, format, 0);

  //uint32_t resutl = dev(100U, 10U);
  displaySensors();
  auxChannelsPage();
  AlarmConfig();
  printTimer(0);
  //rxTest2();
  //initALT(100000);
  uint32_t reminder=0;
  __asm("mov r1, #4" : [output] "=r" (reminder));
  __asm("mov %[output], r1" : [output] "=r" (reminder));

  while(1) {
	 //int32_t alt = getALT(50000);
	 //if(alt > 0){ alt+=alt;alt-=alt;}
	//debug_flush();
	//adc_test();
	//adc_test2();
	//displaySmalString(testdata, 0U,0U);
	//displaySmalString(testdata, 0U,9U);
	//displaySmalString(testdata, 0U,21U);

	lcd_send_data(screen_buffer);
	//debug("###  OpenGround  ###\n");
    //GPIO_TogglePinsOutput(BACKLIGHT_LED_GPIO, (1U << BACKLIGHT_LED_PIN));
  }
}
