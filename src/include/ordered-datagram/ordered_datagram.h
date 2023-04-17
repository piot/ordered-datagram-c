/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef ORDERED_DATAGRAM_H
#define ORDERED_DATAGRAM_H

#include <stdbool.h>
#include <stdint.h>

typedef uint16_t OrderedDatagramId;

bool orderedDatagramIdIsValidSuccessor(OrderedDatagramId encountered, OrderedDatagramId lastReceived);
int orderedDatagramIdDiff(OrderedDatagramId encountered, OrderedDatagramId lastReceived);

#endif
