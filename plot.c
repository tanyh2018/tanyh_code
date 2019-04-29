void plot(){
        c1=new TCanvas("c1", "A Zoomed Graph", 200, 10, 700, 500);
//        h2 = ROOT.TH2F('h2', 'h2', 100, 0, 4E+15, 100, 0, 2E+12);
//        h2->SetStats(kFALSE); // no statistics
//        h2->Draw();
        Int_t n = 5;
        Double_t x[5]={0, 4E14, 8E14, 1.5E15, 3E15};
        Double_t y[5]={1.67E+12, 1.52E+12, 1.40E12, 1.22E12, 8.97E11};
        gr5 = new TGraph(n, x, y);
        gr5->SetLineWidth(2);
        gr5->SetMarkerStyle(21);
        gr5->Draw("ALP");
        gr5->GetXaxis()->SetTitle("Fluence (Neq/cm^2)");
        gr5->GetYaxis()->SetTitle("Integral of doping profile");
        gr5->GetXaxis()->CenterTitle();
        gr5->GetYaxis()->CenterTitle();
        gr5->GetYaxis()->SetLabelSize(0.03);
        gr5->Draw("LP");
        c1->SaveAs("plot.pdf");
}