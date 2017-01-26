#ifndef __PMultiProton_h__
#define __PMultiProton_h__

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "GTreeManager.h"
#include "PPhysics.h"

#include <TGraph.h>

class	PMultiProton  : public PPhysics
{
private:
    GH1*	time;
    GH1*	time_cut;
    GH1*	time_2g;      
    GH1*	time_2g_cut;   
     

    GH1*	MM[6];

    TH1*	TaggerAccScal;
    TLorentzVector missingpknock4;
    TLorentzVector beam2;
    Double_t time2;


    //Correction TGraphs
    TGraph* lightCorrection;
   
    TGraph* deg22Correction;
    TGraph* deg24Correction;
    TGraph* deg26Correction;
    TGraph* deg28Correction;
    TGraph* deg30Correction;
    TGraph* deg32Correction;
    TGraph* deg34Correction;
    TGraph* deg36Correction;
    TGraph* deg38Correction;
    TGraph* deg40Correction;
    TGraph* deg42Correction;
    TGraph* deg44Correction;
    TGraph* deg46Correction;
    TGraph* deg48Correction;
    TGraph* deg50Correction;
    TGraph* deg52Correction;
    TGraph* deg54Correction;
    TGraph* deg56Correction;
    TGraph* deg58Correction;
    TGraph* deg60Correction;
    TGraph* deg62Correction;
    TGraph* deg64Correction;
    TGraph* deg66Correction;
    TGraph* deg68Correction;
    TGraph* deg70Correction;
    TGraph* deg72Correction;
    TGraph* deg74Correction;
    TGraph* deg76Correction;

    //Define proton's mass as constant. Used for adjusting kinetic/total energy.
    inline Double_t protonMass() {return 938.2720813;}


protected:
    virtual Bool_t  Start();
    virtual void    ProcessEvent();
    virtual void	ProcessScalerRead();
    virtual Bool_t    Write();
			
public:
    PMultiProton();
    virtual ~PMultiProton();
    virtual Bool_t  Init();
    TLorentzVector CalcMissingP4knock(const GTreeParticle &tree, Int_t tagger_index);
    void	FillMissingMassPknock(const GTreeParticle& tree, GH1* gHist, Bool_t TaggerBinning = kFALSE);

    void 	FillMissingMassPknock(const GTreeParticle& tree, Int_t tagger_index, GH1* gHist, Bool_t TaggerBinning = kFALSE);


    //Functions added by KP.
     TGraph* GetTGraph(const char *filename, const char *graphname);
     //TLorentzVector correctELoss(const GTreeParticle& tree);

     TLorentzVector CutTheta(TLorentzVector Particle);

     TLorentzVector ApplyCorrection(TLorentzVector Particle);

};
#endif
