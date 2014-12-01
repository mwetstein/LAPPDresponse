## Makefile ##

#
# notes:
#  LAPPD_INCDIR  points to LAPPD .hh files
#  LAPPD_LIBDIR  points to LAPPD .o files
#

CXX           = g++
CXXDEPEND     = -MM
CXXFLAGS      = -g -Wall -fPIC -O0
LD            = g++
LDFLAGS       = -g 

UNAME := $(shell uname)

ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLDFLAGS  := $(shell root-config --ldflags)
ROOTLIBS     := $(shell root-config --evelibs) 
# $(shell root-config --libs)
ROOTGLIBS    := $(shell root-config --glibs)

CXXFLAGS     += $(ROOTCFLAGS)
LDFLAGS      += $(ROOTLDFLAGS)
LIBS          = $(ROOTLIBS) $(SYSLIBS)
GLIBS         = $(ROOTGLIBS) $(SYSLIBS)

INCDIR = ./include
SRCDIR = ./src
TMPDIR = ./tmp
LIBDIR = ./lib
BINDIR = ./bin

INCLUDES = -I$(INCDIR)

LAPPD_INCDIR = ./include
LAPPD_LIBDIR = ./tmp

LAPPD_INCLUDES = -I$(LAPPD_INCDIR)
LAPPD_LDFLAGS += -L$(LAPPD_LIBDIR)
LAPPD_LIBS += -lLAPPD

.PHONY: 
	all

all: clean rootcint shared

ROOTSO := $(LIBDIR)/libLAPPD.so

ROOTDICT := $(SRCDIR)/LAPPDRootDict.cc

ROOTSRC := $(SRCDIR)/LAPPDpulse.cc $(INCDIR)/LAPPDpulse.hh $(SRCDIR)/LAPPDpulseCluster.cc $(INCDIR)/LAPPDpulseCluster.hh $(SRCDIR)/LAPPDresponse.cc $(INCDIR)/LAPPDresponse.hh  $(INCDIR)/LAPPDLinkDef.hh

ROOTOBJS := $(TMPDIR)/LAPPDpulse.o $(TMPDIR)/LAPPDpulseCluster.o $(TMPDIR)/LAPPDresponse.o $(TMPDIR)/LAPPDRootDict.o

$(TMPDIR)/%.o : $(SRCDIR)/%.cc
	@echo "<**Compiling $@**>"
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LAPPD_INCLUDES) -c $< -o $@

$(TMPDIR)/%.d: $(SRCDIR)/%.cc
	@echo "<**Depend $@**>"
	set -e; $(CXX) $(CXXDEPEND) $(CXXFLAGS) $(INCLUDES) $(LAPPD_INCLUDES) $< \
	| sed 's!$*\.o!& $@!' >$@;\
	[ -s $@ ] || rm -f $@

$(ROOTDICT) : $(ROOTSRC)

rootcint : $(ROOTSRC)
	@echo "<**Rootcint**>"
	rootcint -f $(ROOTDICT) -c -I$(INCDIR) -I$(LAPPD_INCDIR) -I$(shell root-config --incdir) LAPPDpulse.hh LAPPDpulseCluster.hh LAPPDresponse.hh
shared: $(ROOTDICT) $(ROOTSRC) $(ROOTOBJS)
	@echo "<**Shared**>"
ifeq ($(UNAME), Darwin) 
	g++ -dynamiclib $(ROOTLIBS) $(ROOTGLIBS) -O $(ROOTOBJS) -lMinuit -o $(ROOTSO)
endif
ifeq ($(UNAME), Linux) 
	g++ -shared $(ROOTLIBS) $(ROOTGLIBS) -O $(ROOTOBJS) -o $(ROOTSO)
endif

clean :
	@echo "<**Clean**>"
	rm -f $(SRCDIR)/*~ $(INCDIR)/*~ $(TMPDIR)/*.o $(TMPDIR)/*.d $(TMPDIR)/*.a $(LIBDIR)/*.so $(SRCDIR)/LAPPDRootDict.*

reco.o : reco.cc 
	@echo "making $@ from $<"
	@echo $(CXX) $(CXXFLAGS) $(INCLUDES) $(LAPPD_INCLUDES) -c $< -o $@
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LAPPD_INCLUDES) -c $< -o $@

reco : reco.o $(ROOTSO)
	@echo "Making reco executable for WCSimAnalysis..."
	g++ -o reco $(CXXFLAGS) reco.o $(LAPPD)/libWCSimRoot.so $(ROOTSO) $(ROOTLIBS) $(ROOTGLIBS) -lMinuit 

DEPS = $(ROOTOBJS:$(TMPDIR)/%.o=$(TMPDIR)/%.d)

ifeq ($(MAKECMDGOALS),all)
 include $(DEPS)
endif

ifeq ($(MAKECMDGOALS),shared)
 include $(DEPS)
endif
