import sys
import ROOT
inputfile = sys.argv[1]
#inputfile = args[0]   
print inputfile
sample = ROOT.TFile(inputfile)
h = sample.Get('hevtflw')
event = []
for i in range(1,10):
    event.append(h.GetBinContent(i))
    print event[i-1]   