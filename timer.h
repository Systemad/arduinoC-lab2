#ifndef _TIMER_H_
#define _TIMER_H_

#define tl_compare 156

void timer_init(void);

#endif // _TIMER_H_

/*
* 16 000 000 / 1024 = 15625 prescale factor
* 15625 * 0.01(sec) = 156.25 ~= 156 =  output compare
*
*/
