/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <flood/out_stream.h>
#include <ordered-datagram/out_logic.h>
#include <ordered-datagram/serialize.h>

/// Initialize the out logic
/// @param self out logic
void orderedDatagramOutLogicInit(OrderedDatagramOutLogic* self)
{
    self->sequenceToSend = 0;
    self->isAllowedToCommit = false;
}

/// Write the current datagramId to the stream
/// @param self out logic
/// @param outStream stream to write header to
/// @return negative value on error
int orderedDatagramOutLogicPrepare(OrderedDatagramOutLogic* self, FldOutStream* outStream)
{
    int result = orderedDatagramIdWrite(outStream, self->sequenceToSend);
    if (result < 0) {
        return result;
    }

    self->isAllowedToCommit = true;
#if 0
    CLOG_VERBOSE("ordered: wrote sequence %04X", self->sequenceToSend);
#endif
    return 0;
}

/// Call when it is sure that the packet will be sent. Increases sequenceId.
/// @param self out logic
void orderedDatagramOutLogicCommit(OrderedDatagramOutLogic* self)
{
    if (!self->isAllowedToCommit) {
        CLOG_ERROR("orderedDatagramOutLogicCommit: commit is not allowed")
    }
    self->sequenceToSend++;
    self->isAllowedToCommit = false;
}
