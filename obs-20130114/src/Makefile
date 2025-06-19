#
# OMNeT++/OMNEST Makefile for obs
#
# This file was generated with the command:


# Name of target to be created (-o option)
TARGET = obs$(EXE_SUFFIX)
INET_PROJ = /home/sm/unusedsimulator/om6_1/omn6_1/inet-4.5.4
LIBS = -L$(INET_PROJ)/out/gcc-debug/src -linet
LIBS += -Wl,-rpath,`abspath $(INET_PROJ)/out/gcc-debug/src`
OMNETPP_HOME = /home/sm/unusedsimulator/om6_1/omn6_1
INET_HOME = /home/sm/unusedsimulator/om6_1/omn6_1/inet-4.5.4


# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)
MSGC_FLAGS = --msg4


# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -I$(INET_PROJ)/src \
    -ICoreNode \
    -IEdgeNode \
    -Imessages \
    -Imisc \
    -Itests \
    -Itests/sinks \
    -Itests/sources

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
INET_PROJ = /home/sm/unusedsimulator/om6_1/omn6_1/inet-4.5.4
INCLUDE_DIRS = -I. -I$(OMNETPP_HOME)/include -I$(INET_HOME)/src


# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/CoreNode/OBS_CoreControlLogic.o \
    $O/CoreNode/OBS_CoreInput.o \
    $O/CoreNode/OBS_CoreOutput.o \
    $O/CoreNode/OBS_CoreOutputHorizon.o \
    $O/CoreNode/OBS_CoreRoutingTable.o \
    $O/CoreNode/OBS_EOConverter.o \
    $O/CoreNode/OBS_OEConverter.o \
    $O/CoreNode/OBS_OpticalCrossConnect.o \
    $O/EdgeNode/BurstList.o \
    $O/EdgeNode/OBS_BurstDisassembler.o \
    $O/EdgeNode/OBS_BurstSender.o \
    $O/EdgeNode/OBS_DispatcherRule.o \
    $O/EdgeNode/OBS_FileBurstifier.o \
    $O/EdgeNode/OBS_PacketBurstifier.o \
    $O/EdgeNode/OBS_PacketDispatcher.o \
    $O/messages/OBS_Burst.o \
    $O/misc/OBS_DropBurst.o \
    $O/misc/OBS_OpticalMonitor.o \
    $O/tests/PacketConverter.o \
    $O/tests/sinks/testSink1.o \
    $O/tests/sinks/testSink2.o \
    $O/tests/sinks/testSink3.o \
    $O/tests/sinks/testSink4.o \
    $O/tests/sinks/testSink5.o \
    $O/tests/sources/testSource1.o \
    $O/tests/sources/testSource2.o \
    $O/tests/sources/testSource3.o \
    $O/tests/sources/testSource4.o \
    $O/tests/sources/testSource5.o \
    $O/CoreNode/OBS_BCPControlInfo_m.o \
    $O/CoreNode/OBS_ControlUnitInfo_m.o \
    $O/CoreNode/OBS_CoreRoutingTableEntry_m.o \
    $O/EdgeNode/OBS_BurstifierInfo_m.o \
    $O/EdgeNode/OBS_BurstSenderInfo_m.o \
    $O/EdgeNode/OBS_ScheduledBurstItem_m.o \
    $O/messages/OBS_Burst_m.o \
    $O/messages/OBS_BurstControlPacket_m.o \
    $O/tests/sources/SourceControlInfo_m.o

# Message files
MSGFILES = \
    CoreNode/OBS_BCPControlInfo.msg \
    CoreNode/OBS_ControlUnitInfo.msg \
    CoreNode/OBS_CoreRoutingTableEntry.msg \
    EdgeNode/OBS_BurstifierInfo.msg \
    EdgeNode/OBS_BurstSenderInfo.msg \
    EdgeNode/OBS_ScheduledBurstItem.msg \
    messages/OBS_Burst.msg \
    messages/OBS_BurstControlPacket.msg \
    tests/sources/SourceControlInfo.msg

# Other makefile variables (-K)
INET_PROJ=/home/sm/unusedsimulator/om6_1/omn6_1/inet-4.5.4

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
MSGC_FLAGS = --msg4

# Modern C++ support (C++11 or higher)
COPTS += -std=c++11

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif
#include $(OMNETPP_HOME)/Makefile.inc
#include $(INET_HOME)/Makefile.inc

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f obs obs.exe libobs.so libobs.a libobs.dll libobs.dylib
	-rm -f ./*_m.cc ./*_m.h
	-rm -f CoreNode/*_m.cc CoreNode/*_m.h
	-rm -f EdgeNode/*_m.cc EdgeNode/*_m.h
	-rm -f messages/*_m.cc messages/*_m.h
	-rm -f misc/*_m.cc misc/*_m.h
	-rm -f tests/*_m.cc tests/*_m.h
	-rm -f tests/sinks/*_m.cc tests/sinks/*_m.h
	-rm -f tests/sources/*_m.cc tests/sources/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc CoreNode/*.cc EdgeNode/*.cc messages/*.cc misc/*.cc tests/*.cc tests/sinks/*.cc tests/sources/*.cc


