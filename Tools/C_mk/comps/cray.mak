#
# Generic setup for using Cray
#
CXX = CC
CC  = cc
FC  = ftn
F90 = ftn

CXXFLAGS =
CFLAGS   =
FFLAGS   =
F90FLAGS =

cray_version := $(shell $(CXX) -V 2>&1 | grep 'Version')

ifeq ($(DEBUG),TRUE)

  CXXFLAGS += -g -O0
  CFLAGS   += -g -O0
  FFLAGS   += -g -O0
  F90FLAGS += -g -O0

else

  CXXFLAGS += -O2
  CFLAGS   += -O2
  FFLAGS   += -O2
  F90FLAGS += -O2

endif


# C++ and C
CXXFLAGS += -h std=c++11
CFLAGS   += -h c99

# Fortran
F90FLAGS += -N 255 -I $(fmoddir) -J $(fmoddir) -em
FFLAGS   += -N 255 -I $(fmoddir) -J $(fmoddir) -em


GENERIC_COMP_FLAGS = 

ifneq ($(USE_OMP),TRUE)
  GENERIC_COMP_FLAGS += -h noomp
endif

ifneq ($(USE_ACC),TRUE)
  GENERIC_COMP_FLAGS += -h noacc
endif


CXXFLAGS += $(GENERIC_COMP_FLAGS)
CFLAGS   += $(GENERIC_COMP_FLAGS)
FFLAGS   += $(GENERIC_COMP_FLAGS)
F90FLAGS += $(GENERIC_COMP_FLAGS)
