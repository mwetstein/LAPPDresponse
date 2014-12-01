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
 
 // test function to get the strip number for a given transverse coordinate (mm)	
 int sno = mlappd->FindStripNumber(coor);
 cout<<"strip number for: " <<coor<<" "<<sno<<endl;

 // test function to get the transverse coordinate (mm) for a given strip number
 int stripuse=30;
 double couse = mlappd->StripCoordinate(stripuse);
 cout<<"strip number: "<<stripuse<<" stripcoordinate: "<<couse<<endl;

 // add a photon hit to the LAPPDresponse class
 // AddSinglePhotonTrace(position_transverse_tostrips(mm), position_parallel_tostrips(mm), global_time(psec))
 mlappd->AddSinglePhotonTrace(coor-20.0, 50, 1000);
 // add an additional photon, slightly more towards the center
 mlappd->AddSinglePhotonTrace(coor-22.0, -10, 2800);

 // Get the cluster storing all of the pulses on the LAPPD
 LAPPDpulseCluster* mclust = mlappd->GetPulseCluster();

 for(int i=0; i<30; i++){
   
   // loop over 30 strips, query the cluster of pulses - how many hits (if any) are on the strip
   cout<<"channel "<<i+1<<" number of hits: "<<mclust->GetNPulsesStrip(i+1)<<endl;	

 }


  // Get the trace from the right side of strip #26
  // GetTrace(stripnumber, parity(+1=right, -1=left), start_time (psec), interval_between_samples (psec), number_of_samples, noise (mV))
  TH1D* mtrace_right = mlappd->GetTrace(26, 1, 800, 100., 300, 1.0);
  mtrace_right->Draw("L*");
  // Get the trace from the left side of strip #26 
  TH1D* mtrace_left = mlappd->GetTrace(26, -1, 800, 100., 300, 1.0);
  mtrace_left->SetLineColor(2);
  mtrace_left->Draw("L* SAME");
 

  // Make a 2D hist of the response on the right side of 4 strips
  double highedge = mtrace_right->GetXaxis()->GetXmax();
  double lowedge = mtrace_right->GetXaxis()->GetXmin();
  TH2D* trace2d = new TH2D("trace2d","trace2d",4,25,29,300,lowedge,highedge);
  
  for(int i=25; i<29; i++){
      TH1D* ttrace =  mlappd->GetTrace(i, 1, 800, 100., 300, 1.0);
      for(int j=0; j<300; j++){
	double bcont = ttrace->GetBinContent(j+1);
	trace2d->SetBinContent(i-24,j-1,-bcont);
	//cout<<i-24<<" "<<j-1<<" "<<bcont<<endl;
      }
  }

  TCanvas* tc = new TCanvas();
  trace2d->Draw("surf3");

}

