{
  // Load libraries
  // ==============
  gSystem->Load("libGeom");
  gSystem->Load("libEve");
  gSystem->Load("libMinuit");
  gSystem->Load("lib/libLAPPD.so");

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
 double coor = 101.6-5.766;
 int sno = mlappd->FindStripNumber(coor);
 cout<<"strip number for: " <<coor<<" "<<sno<<endl;

 int stripuse=30;
 double couse = mlappd->StripCoordinate(stripuse);
 cout<<"strip number: "<<stripuse<<" stripcoordinate: "<<couse<<endl;

 mlappd->AddSinglePhotonTrace(coor, 50, 1000);
 mlappd->AddSinglePhotonTrace(coor, 50, 2800);


 LAPPDpulseCluster* mclust = mlappd->GetPulseCluster();
 for(int i=0; i<30; i++){
  
  cout<<"channel "<<i+1<<" number of hits: "<<mclust->GetNPulsesStrip(i+1)<<endl;	

 }

  TH1D* mtrace_right = mlappd->GetTrace(28, 1, 800, 100., 300);
  mtrace_right->Draw("L*");
  TH1D* mtrace_left = mlappd->GetTrace(28, -1, 800, 100., 300);
  mtrace_left->SetLineColor(2);
  mtrace_left->Draw("L* SAME");

}

