#ifndef __PMultiProton_h__
#define __PMultiProton_h__

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "GTreeManager.h"
#include "PPhysics.h"

#include <TGraph.h>
#include <TGraph2D.h>

class	PMultiProton  : public PPhysics
{
private:
    GH1*	time;
    GH1*	time_cut;
    GH1*	time_cut_pknock;
    GH1*	time_2g;      
    GH1*	time_2g_cut;   
     
    // Added extra dimension to some arrays of histograms 27/2/17

    GH1*	MM[6];
    //From Dan's EGamma code
    GH1*	Ph_time[6];
    /* GH2*	MM_Egamma[6]; */
    TH2F*	MM_Egamma_pr[6][6];
    TH2F*	MM_Egamma_r[6][6];
    //Kieran's additions
    GH1*        Ph_time_bkgd[6];
    /* GH2*        MM_Egamma_Bkgd[6]; */
    TH2F*        MM_Egamma_Bkgd_pr[6];
    TH2F*        MM_Egamma_Bkgd_r[6];

    //Histogram to hold missing mass vs tagger energy
    TH2F*        MM_incidentEgamma_pr[6];
    TH2F*        MM_incidentEgamma_r[6];

    TH1*	TaggerAccScal;
    TLorentzVector missingpknock4;
    TLorentzVector beam2;
    Double_t time2;
    int at_min_time;
    Double_t time_calc;

    Double_t totalPhotonEnergy;
    int numberOfCoincidentGammas;
    Double_t totalBackgroundEnergy;
    int numberOfBackgroundGammas;

    int numBackgroundGammas_MinusOne;
    int numCoincidentGammas_MinusOne;

    

    TGraph* lightCorrEst;
    TGraph2D* energyLoss;

inline Double_t protonMass() {return 938.2720813;}

protected:
    virtual Bool_t  Start();
    virtual void    ProcessEvent();
    virtual void    ProcessScalerRead();
    virtual Bool_t  Write();
			
public:
    PMultiProton();
    virtual ~PMultiProton();
    virtual Bool_t  Init();
    TLorentzVector CalcMissingP4knock(const GTreeParticle &tree, Int_t tagger_index);
    void	FillMissingMassPknock(const GTreeParticle& tree, GH1* gHist, TH2F* tHist_MM_incidentEgamma_pr, TH2F* tHist_MM_incidentEgamma_r, Bool_t TaggerBinning = kFALSE);

    void 	FillMissingMassPknock(const GTreeParticle& tree, Int_t tagger_index, GH1* gHist, TH2F* tHist_MM_incidentEgamma_pr, TH2F* tHist_MM_incidentEgamma_r, Bool_t TaggerBinning = kFALSE);

    //From Dan's decay gamma code
    // Have added second GH2 and GH1 for non-coincident photons
    // Removed gHist_r and gHist_pr and fill inside loop instead
    void	FillMissingMassPknockEgamma(const GTreeParticle& treeP,const GTreeParticle& treeG, GH1* phHist, TH2F* gHistK_pr, TH2F* gHistK_r, GH1* phHistK, Bool_t TaggerBinning = kFALSE);

    void 	FillMissingMassPknockEgamma(const GTreeParticle& treeP,const GTreeParticle& treeG, Int_t tagger_index, GH1* phHist, TH2F* gHistK_pr, TH2F* gHistK_r, GH1* phHistK,  Bool_t TaggerBinning = kFALSE);
    


    void        FillTimeCutPknock(const GTreeParticle& tree, GH1* Hist);
    TGraph* GetTGraph(const char *filename, const char *graphname);
    TGraph2D* GetTGraph2D(const char *filename, const char *graphname);
    
};


#endif
