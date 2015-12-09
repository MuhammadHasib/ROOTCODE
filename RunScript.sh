#!/bin/bash

root -l -q -b re4.C
root -l -q -b readHist.C

pdflatex DrawPlots.tex

evince DrawPlots.pdf 
