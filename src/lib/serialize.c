/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <flood/out_stream.h>
#include <ordered-datagram/serialize.h>

int orderedDatagramIdRead(FldInStream* inStream, OrderedDatagramId* out)
{
    return fldInStreamReadUInt16(inStream, out);
}

int orderedDatagramIdWrite(FldOutStream* outStream, OrderedDatagramId id)
{
    return fldOutStreamWriteUInt16(outStream, id);
}
