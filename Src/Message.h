/*
 * Message.h
 *
 *  Created on: Sep 13, 2017
 *      Author: johan
 */

#pragma once

/**
 * Address list:
 * 16 bit int.
 * 0b0 =
 */
struct Message {
	uint16_t address;
	int value;
};
