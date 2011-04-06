# $Id$
#
# QNX/RTP hosted, using GCC

inline ?= 1
debug ?= 1
optimize ?= 0
threads ?= 1
pipes ?= 1

CCFLAGS += -fexceptions
LDFLAGS += -fexceptions

ifeq ($(inline),1)
CCFLAGS += -finline-functions
else
CCFLAGS += -fno-inline
endif # inline

DCFLAGS  += -ggdb
DCCFLAGS += -ggdb

ifeq ($(optimize),1)
OCFLAGS += -O3
endif #optimize

CFLAGS  += -W -Wall -Wpointer-arith

LIBS    += -lsocket -lstdc++ -lm

PIC     = -fPIC
ARFLAGS = ruv
SOFLAGS += $(CPPFLAGS) -shared
SOBUILD = $(COMPILE.cc) $(PIC) -o $(VSHDIR)$*.so $<
PRELIB  = @true

# Test for template  instantiation, add to SOFLAGS if SONAME set,
# add -E to LDFLAGS if using GNU ld
#
include $(ACE_ROOT)/include/makeinclude/platform_g++_common.GNU

CCFLAGS += $(CFLAGS) $(FLAGS_C_CC)

CFLAGS  += $(FLAGS_C_CC)