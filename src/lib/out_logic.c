/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include "clog/clog.h"
#include <flood/out_stream.h>
#include <ordered-datagram/out_logic.h>
#include <ordered-datagram/serialize.h>

/// Initialize the out logic
/// @param self
void orderedDatagramOutLogicInit(OrderedDatagramOutLogic* self)
{
    self->sequenceToSend = 0;
    self->debugPrepareCount = 0;
}

/// Write the current datagramId to the stream
/// @param self
/// @param outStream
/// @return negative value on error
int orderedDatagramOutLogicPrepare(OrderedDatagramOutLogic* self, FldOutStream* outStream)
{
    int result = orderedDatagramIdWrite(outStream, self->sequenceToSend);
    if (result < 0)
    {
        return result;
    }

    self->debugPrepareCount++;
#if 0
    CLOG_VERBOSE("ordered: wrote sequence %04X count:%d", self->sequenceToSend, self->debugPrepareCount);
#endif
    return 0;
}

/// Call when it is sure that the packet will be sent. Increases sequenceId.
/// @param self
void orderedDatagramOutLogicCommit(OrderedDatagramOutLogic* self)
{
    if (self->debugPrepareCount == 0) {
        CLOG_ERROR("commit is not allowed")
    }
    self->sequenceToSend++;
    self->debugPrepareCount = 0;
}

