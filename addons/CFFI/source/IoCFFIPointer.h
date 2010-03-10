/* CFFI - An Io interface to C
Copyright (c) 2006 Trevor Fancher. All rights reserved.
All code licensed under the New BSD license.
*/

#ifndef IoCFFIPointer_DEFINED
#define IoCFFIPointer_DEFINED 1

#include "IoObject.h"

#define ISCFFIPointer(self) IoObject_hasCloneFunc_(self, (IoTagCloneFunc *)IoCFFIPointer_rawClone)

typedef IoObject IoCFFIPointer;

typedef struct IoCFFIPointer
{
	void	*ptr;
	void	**valuePointer;
} IoCFFIPointerData;

IoTag			*IoCFFIPointer_newTag(void *state);
IoCFFIPointer	*IoCFFIPointer_proto(void *state);
IoCFFIPointer	*IoCFFIPointer_rawClone(IoCFFIPointer *self);
void			IoCFFIPointer_free(IoCFFIPointer *self);
void			IoCFFIPointer_mark(IoCFFIPointer *self);

IoCFFIPointer	*IoCFFIPointer_ToType_(IoObject *type);

IoCFFIPointer	*IoCFFIPointer_new(void *state);

IoObject		*IoCFFIPointer_address(IoCFFIPointer *self, IoObject *locals, IoMessage *m);
IoObject		*IoCFFIPointer_value(IoCFFIPointer *self, IoObject *locals, IoMessage *m);
IoObject		*IoCFFIPointer_setValue(IoCFFIPointer *self, IoObject *locals, IoMessage *m);
IoObject		*IoCFFIPointer_toType(IoCFFIPointer *self, IoObject *locals, IoMessage *m);
IoObject		*IoCFFIPointer_at(IoCFFIPointer *self, IoObject *locals, IoMessage *m);
IoObject		*IoCFFIPointer_atPut(IoCFFIPointer *self, IoObject *locals, IoMessage *m);
IoObject		*IoCFFIPointer_asBuffer(IoCFFIPointer *self, IoObject *locals, IoMessage *m);
IoObject		*IoCFFIPointer_castTo(IoCFFIPointer *self, IoObject *locals, IoMessage *m);


IoCFFIPointer	*IoCFFIPointer_cloneWithData(IoCFFIPointer *self, void **data);
void			*IoCFFIPointer_valuePointer(IoCFFIPointer *self);
void			IoCFFIPointer_setValuePointer_offset_(IoCFFIPointer* self, void *ptr, int offset);

#endif
