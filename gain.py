import sys
import os
import ROOT
from string import Template
#Get all channels detail value echo step
def main(): 
    args = sys.argv[1]
    table = open(args , 'r' )
    d1=[]
    d2=[] 
    d3=[]
    d4=[]
    for s_row in table :
        l = [x.strip() for x in s_row.split(',')]
        d1.append(l[0])
        d2.append(l[1])
        d3.append(l[2])
#        d4.append(l[3])
    if "BV60" in args:
        h2 = ROOT.TH2F('BV60','BV60',200,0,150,30,1,30)
        name="BV60"
    if "BV170" in args:
        h2 = ROOT.TH2F('BV170','BV170',200,0,200,30,1,30)
        name="BV170"
    #TH2F * h2 = new TH2F("h2","h2 title",8,0,4,8,0,4)
    c = ROOT.TCanvas('c', 'c', 200, 10, 700, 500)
    for i in range(len(d1)-1):
        x=-float(d1[i+1])
        a=float(d3[1])
        b=float(d3[i+1])
        y=b/a
        h2.Fill(x,y,1)
    h2.Draw("ALP")
    h2.GetXaxis().SetTitle("Voltage")
    h2.GetYaxis().SetTitle("Gain")
    h2.SetLineWidth(2)
    h2.SetMarkerStyle(21)
    h2.GetXaxis().CenterTitle()
    h2.GetYaxis().CenterTitle()
    h2.Draw("")
    c.SaveAs(name+".pdf")
if __name__ == '__main__':
    main()
