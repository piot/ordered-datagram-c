/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <ordered-datagram/ordered_datagram.h>

#define ORDERED_DATAGRAM_ID_MAX (65536)
#define ORDERED_DATAGRAM_ID_ACCEPTABLE_DIFF (625) // 10 datagrams * tickFrequency (62.5) * 1 second latency

int orderedDatagramIdDiff(OrderedDatagramId encountered, OrderedDatagramId expected)
{
    int diff;

    if (encountered < expected) {
        diff = encountered + ORDERED_DATAGRAM_ID_MAX - expected;
    } else {
        diff = encountered - expected;
    }

    return diff;
}

bool orderedDatagramIdIsValidSuccessor(OrderedDatagramId encountered, OrderedDatagramId expected)
{
    int diff;

    if (encountered < expected) {
        diff = encountered + ORDERED_DATAGRAM_ID_MAX - expected;
    } else {
        diff = encountered - expected;
    }

    return diff > 0 && diff <= ORDERED_DATAGRAM_ID_ACCEPTABLE_DIFF;
}
