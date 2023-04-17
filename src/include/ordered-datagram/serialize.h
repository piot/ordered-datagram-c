/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef ORDERED_DATAGRAM_SERIALIZE_H
#define ORDERED_DATAGRAM_SERIALIZE_H

#include <ordered-datagram/ordered_datagram.h>

struct FldInStream;
struct FldOutStream;

int orderedDatagramIdRead(struct FldInStream* inStream, OrderedDatagramId* out);
int orderedDatagramIdWrite(struct FldOutStream* outStream, OrderedDatagramId id);

#endif
