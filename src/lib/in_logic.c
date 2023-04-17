/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <ordered-datagram/in_logic.h>
#include <ordered-datagram/serialize.h>

/// Initialize in logic
/// @param self
void orderedDatagramInLogicInit(OrderedDatagramInLogic* self)
{
    self->hasReceivedInitialDatagram = 0;
    self->lastReceivedSequence = 0;
}

/// Reads a OrderedDatagramId from inStream and checks if the sequence is valid
/// @param self
/// @param inStream
/// @return negative on error. zero if it wasn't a valid package, otherwise the diff against the last one.
int orderedDatagramInLogicReceive(OrderedDatagramInLogic* self, FldInStream* inStream)
{
    OrderedDatagramId encounteredId;
    int result = orderedDatagramIdRead(inStream, &encounteredId);
    if (result < 0) {
        return result;
    }

#if 0
    CLOG_VERBOSE("ordered: read sequence %04X", encounteredId);
#endif

    if (self->hasReceivedInitialDatagram) {
        int diff = orderedDatagramIdDiff(encounteredId, self->lastReceivedSequence);
        if (diff > 0 && diff < 32767) {
            self->lastReceivedSequence = encounteredId;
            return diff;
        }
    } else {
        self->hasReceivedInitialDatagram = true;
        self->lastReceivedSequence = encounteredId;
        return 1;
    }

    // Sequence is invalid, return zero
    return 0;
}