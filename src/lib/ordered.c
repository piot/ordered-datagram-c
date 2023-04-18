/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <ordered-datagram/ordered_datagram.h>

int orderedDatagramIdDiff(OrderedDatagramId encountered, OrderedDatagramId lastReceived)
{
    int diff;

    if (encountered < lastReceived) {
        const int orderedDatagramIdMax = 0x10000;
        diff = encountered + orderedDatagramIdMax - lastReceived;
    } else {
        diff = encountered - lastReceived;
    }

    return diff;
}

bool orderedDatagramIdIsValidSuccessor(OrderedDatagramId encountered, OrderedDatagramId lastReceived)
{
    int diff = orderedDatagramIdDiff(encountered, lastReceived);

    const int orderedDatagramIdAcceptableDiff = 625; // 10 datagrams / tick * tickFrequency (62.5) * 1 second latency
    return diff > 0 && diff <= orderedDatagramIdAcceptableDiff;
}
