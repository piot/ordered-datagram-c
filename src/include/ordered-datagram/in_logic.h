/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef ORDERED_DATAGRAM_IN_LOGIC_H
#define ORDERED_DATAGRAM_IN_LOGIC_H

#include <stdbool.h>
#include <ordered-datagram/ordered_datagram.h>

struct FldInStream;

typedef struct OrderedDatagramInLogic
{
    bool hasReceivedInitialDatagram;
    OrderedDatagramId lastReceivedSequence;
} OrderedDatagramInLogic;

void orderedDatagramInLogicInit(OrderedDatagramInLogic* self);
int orderedDatagramInLogicReceive(OrderedDatagramInLogic* self, struct FldInStream* inStream);

#endif
