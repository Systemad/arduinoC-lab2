#ifndef _TIMER_H_
#define _TIMER_H_

#define compare_value 156

void timer_init(void);

#endif // _TIMER_H_


/*
* Use formula f_cpu / (prescale_value * rate) to calculate compare value    f_cpu = 16Mhz (16 000 000) 
* 16Mhz / (1024 * 100) = 156.25 rounded 156                                 prescale_value = 1024
* (16Mhz = 16 000 000)                                                      rate = 100 = 10ms
*/