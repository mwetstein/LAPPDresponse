{
  // Load libraries
  // ==============
  gSystem->Load("libGeom");
  gSystem->Load("libEve");
  gSystem->Load("libMinuit");
  gSystem->Load("lib/LAPPDresponse.so");

  #include "TRandom3.h"
  #include <iomanip>
  #include "include/LAPPDresponse.hh"

  TRandom3 numberp(42484);


  // Path to WCSim ROOT file
  // =======================
  TString filename("../../FullEvent.root");
  TString genfilename("../../generatorcardfile_test.root");

  // Load Data
  // =========

 LAPPDresponse* mlappd = new LAPPDresponse();


}

