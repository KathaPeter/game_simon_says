/*
 * seven_segment_display.h
 *
 *  Created on: Dec 17, 2023
 *      Author: Katharina Peter
 */

#ifndef SRC_SEVEN_SEGMENT_DISPLAY_H_
#define SRC_SEVEN_SEGMENT_DISPLAY_H_

#include <stdint.h>

/**
 *  @brief: Shows a given number on a seven segment display.
 *
 *  @param: u8Number: Number that will lights up on the seven segment display.
 *
 *  @returns: 0: Success
 *  		 -1: Error
 *
 */
int8_t s8Segment_SetDisplay(uint8_t u8Number);

#endif /* SRC_SEVEN_SEGMENT_DISPLAY_H_ */
