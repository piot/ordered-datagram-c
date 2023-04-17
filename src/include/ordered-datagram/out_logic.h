/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef ORDERED_DATAGRAM_OUT_LOGIC_H
#define ORDERED_DATAGRAM_OUT_LOGIC_H

#include <stdbool.h>
#include <ordered-datagram/ordered_datagram.h>

struct FldOutStream;

typedef struct OrderedDatagramOutLogic
{
    OrderedDatagramId sequenceToSend;
    int debugPrepareCount;
} OrderedDatagramOutLogic;


void orderedDatagramOutLogicInit(OrderedDatagramOutLogic* self);
int orderedDatagramOutLogicPrepare(OrderedDatagramOutLogic* self, struct FldOutStream* outStream);
void orderedDatagramOutLogicCommit(OrderedDatagramOutLogic* self);

#endif
