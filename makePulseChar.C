{

// peak signal distribution

TString fname;
fname+="PHD.txt";	
ifstream InFile(fname, ios::in);

TGraph* gPHD = new TGraph();

int ii=0;
double peakval,N;
while((!InFile.eof())) {
    InFile >> peakval >> N ;
    cout<<peakval<<" "<<N<<" "<<ii<<endl;	
    gPHD->SetPoint(ii,peakval,N);	
    ii++;
}

TH1D* hPHD = new TH1D("peakdist","peakdist",100,0,1000);

for(int mm=0; mm<100; mm++){

  double bcnt = hPHD->GetBinCenter(mm+1);
  double cntnt = gPHD->Eval(bcnt);
  if(cntnt<0)cntnt=0;	
  hPHD->SetBinContent(mm+1,cntnt);	
}


// histogram recording the sigma values for the charge spread, as a function of distance from 
// strip center

TH1D* pulsewidth = new TH1D("pulsewidth","pulsewidth",10,0.0,3.45);

for(int k=0; k<10; k++){

  double bcent = pulsewidth->GetBinCenter(k);
  double sigma = (0.51 + 0.017*k)*6.91;

  pulsewidth->SetBinContent(k+1,sigma);
}


// template pulse shape

TFile* tf = new TFile("template.Apr05v1.root","READ");

TH1D* templatepulse = new TH1D("mytemplate","mytemplate",3000,0.,3000.);
TH1D* oldtemplate = (TH1D*) tf->Get("thetemplate");

for(int i=0; i<templatepulse->GetNbinsX(); i++){

	double bcx = templatepulse->GetBinCenter(i);
	double bincontent = oldtemplate->Interpolate(bcx+49300);
	cout<<bcx<<" "<<bincontent<<endl;
	templatepulse->SetBinContent(i+1,bincontent);
}

//templatepulse->Draw();
hPHD->Draw();
// save the relevant histograms

TFile* tf2 = new TFile("pulsecharacteristics.root","RECREATE");
pulsewidth->Write("pulsewidth");
templatepulse->Write("templatepulse");
hPHD->Write("PHD");





}
