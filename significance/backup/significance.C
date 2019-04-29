#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <algorithm>   
#include <TMath.h>
#include <RooStats/RooStatsUtils.h>

using namespace std;
int main(int argc, char* argv[])
{
   Int_t       nparam        =   1; 
   Double_t    deltaL        = 0.5; //delta of FCN
   Double_t    factor        = 2.0; //for likelyhood fit
 //  Double_t    factor        = 1.0; //for chisq fit
   if (argc<3)
   {
      cout << "    Usuage: "<< endl;
      cout << "    significance deltaL nParam "<< endl;
      //exit(0);
   }
   string chi2="likely";
   if (argc>3){
      chi2=argv[3];
   }
   //
   //
   if (argc>2){
	   deltaL =    atof(argv[1]);
	   nparam =    atoi(argv[2]);
   }
   if( chi2.find("chi2") != string::npos ) factor = 1.0;
   //
   cout<<"deltaL = "<<deltaL<<", nParam= "<<nparam<<endl;
   Double_t    prob          = TMath::Prob(factor*fabs(deltaL),nparam);
   Double_t    significance  = RooStats::PValueToSignificance(prob*0.5);
   cout<<"prob= "<<prob<<", significance= "<<significance<<endl;
   exit(0);

}
