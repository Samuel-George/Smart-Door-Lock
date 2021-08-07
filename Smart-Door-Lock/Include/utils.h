/*
 * utils.h
 *
 *  Created on: Sep 4, 2019
 *      Author: Manal
 */

#ifndef UTILS_H_
#define UTILS_H_

#define set_bit(reg,bitn) reg|=(1<<bitn)
#define clr_bit(reg,bitn) reg&=(~(1<<bitn))
#define get_bit(reg,bitn) ((reg&(1<<bitn))>>bitn)
#define toggle_bit(reg,bitn) reg^=(1<<bitn)

#endif /* UTILS_H_ */
