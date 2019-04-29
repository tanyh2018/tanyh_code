gSystem->Load("libRooFit");
//gStyle->SetPaperSize(32,16);
using namespace RooFit;
void fit_his(){
	TCanvas *c1 = new TCanvas("c1","",0,0,900,600);
    c1->cd();
   RooRealVar x("pKsm_4c","pKsm_4c",1,3);
   TChain *chain2 = new TChain("fit4c");
   chain2->Add("/cefs/higgs/tanyuhang/hig2inv/pkchic0.root");
   TTree* sigtree = chain2;
   TH1F *h2=new TH1F("pKsm_4c","pKsm_4c",100,1,3);
   sigtree->Draw("pKsm_4c>>h2");
   TH1D *sigdata =(TH1D*)gDirectory->Get("h2"); 
   RooDataHist data1 ("data1"  , "data1" , x, sigdata);
   RooHistPdf sigh("sig","sigshape", x, data1, 0);
//    RooArgusBG fun("argus","Argus PDF",x,RooConst(137),c,a) ;
   RooDataSet  *data = sigh.generate(x,10000);
//	fun.fitTo(*data) ;
   RooPlot* xframe = x.frame() ;
   data->plotOn(xframe) ;
//    fun.plotOn(xframe) ;
    //.plotOn(mesframe,Components(argus),LineStyle(kDashed)) ; 
//	xframe->Draw();
}