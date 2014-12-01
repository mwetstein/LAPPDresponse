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

 mlappd->AddSinglePhotonTrace(coor-20.0, 50, 1000);
 mlappd->AddSinglePhotonTrace(coor-22.0, 50, 2800);


 LAPPDpulseCluster* mclust = mlappd->GetPulseCluster();
 for(int i=0; i<30; i++){
  
  cout<<"channel "<<i+1<<" number of hits: "<<mclust->GetNPulsesStrip(i+1)<<endl;	

 }


 // TH1D* mtrace_right = mlappd->GetTrace(11, 1, 800, 100., 300);


  TH1D* mtrace_right = mlappd->GetTrace(26, 1, 800, 100., 300);
  mtrace_right->Draw("L*");
  TH1D* mtrace_left = mlappd->GetTrace(26, -1, 800, 100., 300);
  mtrace_left->SetLineColor(2);
  mtrace_left->Draw("L* SAME");


  double highedge = mtrace_right->GetXaxis()->GetXmax();
  double lowedge = mtrace_right->GetXaxis()->GetXmin();

  TH2D* trace2d = new TH2D("trace2d","trace2d",4,25,29,300,lowedge,highedge);
  
  for(int i=25; i<29; i++){
      TH1D* ttrace =  mlappd->GetTrace(i, 1, 800, 100., 300);
      for(int j=0; j<300; j++){
	double bcont = ttrace->GetBinContent(j+1);
	trace2d->SetBinContent(i-24,j-1,-bcont);
	//cout<<i-24<<" "<<j-1<<" "<<bcont<<endl;
      }
  }

  TCanvas* tc = new TCanvas();
  trace2d->Draw("surf3");
 // trace2d->Draw("SPEC dm(1,10) pa(2,1,1) ci(1,4,8) a(15,45,0)");
}

