#include "PMultiProton.h"

PMultiProton::PMultiProton()
{ 
    time 	= new GH1("time", 	"time", 	1400, -700, 700);
    time_cut 	= new GH1("time_cut", 	"time_cut", 	1400, -700, 700);
    time_cut_pknock 	= new GH1("time_cut_pknock", 	"time_cut_pknock", 	8400, -700, 7700);

    time_2g 	= new GH1("time_2g",	"time_2g", 	1400, -700, 700);
    time_2g_cut = new GH1("time_2g_cut","time_2g_cut", 	1400, -700, 700);

    char Title_h1[60];
    char Name_h1[60];
  
    for (int i=0; i<3; i++) {

      

      sprintf(Title_h1,"Missing Mass %d protons knockout",i+1);
      sprintf(Name_h1,"Missing_Mass_%d",i+1);
      //lead
      MM[i] = new GH1(Name_h1,Title_h1, 1750,187000,194000);  //Fine Bins!
      // MM[i] = new GH1(Name_h1, Title_h1, 300, 189000, 194000);

      //carbon?
      // MM[i] = new GH1(Name_h1,Title_h1, 7000,4000,11000); //Fine Bins!
      //MM[i] = new GH1(Name_h1, Title_h1, 1200, 4000, 11000);

      //calcium?
      //MM[i] = new GH1(Name_h1,Title_h1, 3500,30500,37500);   
      //MM[i] = new GH1(Name_h1, Title_h1, 600, 30500, 37500);



      sprintf(Title_h1,"Photon time %d protons knockout",i+1);
      sprintf(Name_h1,"ph_time_%d",i+1); 
      Ph_time[i] = new GH1(Name_h1,Title_h1,200,-200,200);

      sprintf(Title_h1, "Photon time %d protons knockout background", i+1);
      sprintf(Name_h1, "ph_time_%d_background",i+1);
      Ph_time_bkgd[i] = new GH1(Name_h1, Title_h1, 200, -200, 200);


      // Create histograms to hold missing mass vs tagger energy

      sprintf(Title_h1, "Missing Mass %d protons knockout vs Incident E_{#gamma} PROMPT", i+1);
      sprintf(Name_h1, "Missing_Mass_%d_vs_Incident_Egamma_pr",i+1);

      
      //MM_incidentEgamma_pr[i] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 2000, 0.0, 1000.0); //Carbon
      MM_incidentEgamma_pr[i] = new TH2F(Name_h1, Title_h1, 1750,187000,194000, 2000, 0.0, 1000.0); // Lead


      sprintf(Title_h1, "Missing Mass %d protons knockout vs Incident E_{#gamma} RANDOM", i+1);
      sprintf(Name_h1, "Missing_Mass_%d_vs_Incident_Egamma_r",i+1);

       
      // MM_incidentEgamma_r[i] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 2000, 0.0, 1000.0);//carbon
      MM_incidentEgamma_r[i] = new TH2F(Name_h1, Title_h1, 1750,187000,194000, 2000, 0.0, 1000.0); // Lead


                   //Kieran's additions, background prompts and random

       sprintf(Title_h1, "Missing Mass %d protons knockout vs E_{#gamma} Background PROMPT", i+1);
       sprintf(Name_h1, "Missing_Mass_%d_vs_Egamma_Background_pr", i+1);

       MM_Egamma_Bkgd_pr[i] = new TH2F(Name_h1, Title_h1, 1750, 187000, 194000, 200, 0.0, 20.0); // Lead
       
       //MM_Egamma_Bkgd_pr[i] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 200.0, 0.0, 20.0); //Carbon


       sprintf(Title_h1, "Missing Mass %d protons knockout vs E_{#gamma} Background RANDOM", i+1);
       sprintf(Name_h1, "Missing_Mass_%d_vs_Egamma_Background_r", i+1);

        MM_Egamma_Bkgd_r[i] = new TH2F(Name_h1, Title_h1, 1750, 187000, 194000, 200, 0.0, 20.0); //Lead

       //MM_Egamma_Bkgd_r[i] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 200.0, 0.0, 20.0); //Carbon





       for (int j =0; j<6; j++) {

       //Decay gamma from Dan's code
       
      sprintf(Title_h1,"Missing Mass %d protons knockout vs %d E_{#gamma} PROMPT",i+1, j+i);
      sprintf(Name_h1,"Missing_Mass_%d_vs_%d_Egamma_pr",i+1, j+1);
       //  MM_Egamma[i] = new GH2(Name_h1,Title_h1, 1000,4000,11000,80,0.,20.); 
       //MM_Egamma[i] = new GH2(Name_h1,Title_h1, 110,-100,1000,80,0.,20.);  
      // MM[i] = new GH1(Name_h1,Title_h1, 1750,187000,194000);     //Lead
       // MM_Egamma[i] = new GH2(Name_h1,Title_h1, 500,187000,194000,40,0.,20.); //Lead
       
      MM_Egamma_pr[i][j] = new TH2F(Name_h1,Title_h1, 1750,187000,194000,200,0.,20.); //Lead
      
      // MM_Egamma_pr[i][j] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 200.0, 0.0, 20.0); //Carbon

       
       sprintf(Title_h1,"Missing Mass %d protons knockout vs %d E_{#gamma} RANDOM",i+1, j+1);
       sprintf(Name_h1,"Missing_Mass_%d_vs_%d_Egamma_r",i+1,j+1);
       
       MM_Egamma_r[i][j] = new TH2F(Name_h1,Title_h1, 1750,187000,194000,200,0.,20.); // Lead

       //MM_Egamma_r[i][j] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 200.0, 0.0, 20.0); //Carbon


       


       }


    }

for (int i=3; i<6; i++) {



      sprintf(Title_h1,"Missing Mass %d protons knockout",i+1);
      sprintf(Name_h1,"Missing_Mass_%d",i+1);
      //lead
      MM[i] = new GH1(Name_h1,Title_h1, 1750,187000,194000);  
      //MM[i] = new GH1(Name_h1, Title_h1, 300, 187000, 194000);

      //carbon?
      // MM[i] = new GH1(Name_h1,Title_h1, 7000,4000,11000);
      //MM[i] = new GH1(Name_h1, Title_h1, 1200, 4000, 11000);

      //calcium?
      //MM[i] = new GH1(Name_h1,Title_h1, 3500,30500,37500);   
      //MM[i] = new GH1(Name_h1, Title_h1, 600, 30500, 37500);


      sprintf(Title_h1,"Photon time %d protons knockout",i+1);
      sprintf(Name_h1,"ph_time_%d",i+1); 
      Ph_time[i] = new GH1(Name_h1,Title_h1,200,-200,200);


      sprintf(Title_h1, "Photon time %d protons knockout background", i+1);
      sprintf(Name_h1, "ph_time_%d_background",i+1);
      Ph_time_bkgd[i] = new GH1(Name_h1, Title_h1, 200, -200, 200);


      // Create histograms to hold missing mass vs incident photon energy from tagger

      sprintf(Title_h1, "Missing Mass %d protons knockout vs Incident E_{#gamma} PROMPT", i+1);
      sprintf(Name_h1, "Missing_Mass_%d_vs_Incident_Egamma_pr",i+1);

       
      // MM_incidentEgamma_pr[i] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 2000, 0.0, 1000.0); // Carbon
      MM_incidentEgamma_pr[i] = new TH2F(Name_h1, Title_h1, 1750, 187000, 194000, 2000, 0.0, 1000.0); // Lead

      sprintf(Title_h1, "Missing Mass %d protons knockout vs Incident E_{#gamma} RANDOM", i+1);
      sprintf(Name_h1, "Missing_Mass_%d_vs_Incident_Egamma_r",i+1);

       
      //MM_incidentEgamma_r[i] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 2000, 0.0, 1000.0); // Carbon
      MM_incidentEgamma_r[i] = new TH2F(Name_h1, Title_h1, 1750, 187000, 194000, 2000, 0.0, 1000.0); // Lead

            //Kieran's additions, background promt and random

       sprintf(Title_h1, "Missing Mass %d protons knockout vs E_{#gamma} Background PROMPT", i+1);
       sprintf(Name_h1, "Missing_Mass_%d_vs_Egamma_Background_pr", i+1);


       MM_Egamma_Bkgd_pr[i] = new TH2F(Name_h1, Title_h1, 1000, 187000, 194000, 80, 0.0, 20.0); // Lead

       //MM_Egamma_Bkgd_pr[i] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 80.0, 0.0, 20.0);

       sprintf(Title_h1, "Missing Mass %d protons knockout vs E_{#gamma} Background RANDOM", i+1);
       sprintf(Name_h1, "Missing_Mass_%d_vs_Egamma_Background_r", i+1);


       MM_Egamma_Bkgd_r[i] = new TH2F(Name_h1, Title_h1, 1000, 187000, 194000, 80, 0.0, 20.0); // Lead

       //MM_Egamma_Bkgd_r[i] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 80.0, 0.0, 20.0); //Carbon




      for (int j=0; j<6; j++){


       //Decay gamma from Dan's code
       
       sprintf(Title_h1,"Missing Mass %d protons knockout vs %d E_{#gamma} PROMPT",i+1, j+1);
       sprintf(Name_h1,"Missing_Mass_%d_vs_%d_Egamma_pr",i+1, j+1);
       //  MM_Egamma[i] = new GH2(Name_h1,Title_h1, 1000,4000,11000,80,0.,20.); 
       //MM_Egamma[i] = new GH2(Name_h1,Title_h1, 110,-100,1000,80,0.,20.); 
      // MM[i] = new GH1(Name_h1,Title_h1, 1750,187000,194000);     
       // MM_Egamma[i] = new GH2(Name_h1,Title_h1, 500,187000,194000,40,0.,20.); 

       MM_Egamma_pr[i][j] = new TH2F(Name_h1,Title_h1, 1000,187000,194000,80,0.,20.); //Lead

       // MM_Egamma_pr[i][j] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 80.0, 0.0, 20.0); //Carbon


       sprintf(Title_h1,"Missing Mass %d protons knockout vs %d E_{#gamma} RANDOM",i+1, j+1);
       sprintf(Name_h1,"Missing_Mass_%d_vs_%d_Egamma_r",i+1, j+1);


       MM_Egamma_r[i][j] = new TH2F(Name_h1,Title_h1, 1000,187000,194000,80,0.,20.); // Lead
       
       // MM_Egamma_r[i][j] = new TH2F(Name_h1, Title_h1, 1000, 4000, 11000, 80.0, 0.0, 20.0); // Carbon





       
  }



    }


    TaggerAccScal = new TH1D("TaggerAccScal","TaggerAccScal",352,0,352);

    // Open estimated light correction factor
    lightCorrEst = new TGraph();
    lightCorrEst = GetTGraph("LCorr2.root", "LightCorr");

    energyLoss = new TGraph2D();
    // lead, no steel
    // energyLoss = GetTGraph2D("Corrections2D.root", "ELOSS");
    
    //lead, steel
    energyLoss = GetTGraph2D("Pb208_Corrections_SteelIn.root", "ELOSS");

    // carbon, steel
    //energyLoss = GetTGraph2D("C12_Correction_AllAngles.root", "ELOSS");

    //calcium, steel
    //energyLoss = GetTGraph2D("Ca40_Correction_AllAngles.root", "ELOSS");
    cout << "TGraph2D loaded!" << endl;


}

PMultiProton::~PMultiProton()
{
}

Bool_t	PMultiProton::Init()
{
	cout << "Initialising physics analysis..." << endl;
	cout << "--------------------------------------------------" << endl << endl;

	if(!InitBackgroundCuts()) return kFALSE;
	if(!InitTargetMass()) return kFALSE;
	if(!InitTaggerChannelCuts()) return kFALSE;
	if(!InitTaggerScalers()) return kFALSE;
	cout << "--------------------------------------------------" << endl;
	return kTRUE;
}

Bool_t	PMultiProton::Start()
{
    if(!IsGoATFile())
    {
        cout << "ERROR: Input File is not a GoAT file." << endl;
        return kFALSE;
    }
    SetAsPhysicsFile();

    TraverseValidEvents();

    return kTRUE;
}

void	PMultiProton::ProcessEvent()
{
	// fill time diff (tagger - proton), all protons
    FillTime(*GetProtons(),time);
    FillTimeCut(*GetProtons(),time_cut);
    at_min_time = 0;
    if (GetProtons()->GetNParticles()>0) {
      FillTimeCutPknock(*GetProtons(),time_cut_pknock);
    }
	// fill missing mass, protons
    // FillMissingMassPknock(*GetProtons(),MM[GetProtons()->GetNParticles()-1]);
    // From Dan's Egamma code
    if(GetChargedPions()->GetNParticles()==0 && GetRootinos()->GetNParticles()==
       0 && GetElectrons()->GetNParticles()==0 && GetNeutralPions()->GetNParticles()==0
       ){
      FillMissingMassPknock(*GetProtons(),MM[GetProtons()->GetNParticles()-1], MM_incidentEgamma_pr[GetProtons()->GetNParticles()-1], MM_incidentEgamma_r[GetProtons()->GetNParticles()-1]);

      //Added extra dimentsion with GetPhotons() 27/2/17
      // Are backgrounds all the same? Backgrounds are non-coincident.
      // Removed e_gamma histograms to fill directly within loop 8/3/17
      

      FillMissingMassPknockEgamma(*GetProtons(),*GetPhotons(),Ph_time[GetProtons()->GetNParticles()-1], MM_Egamma_Bkgd_pr[GetProtons()->GetNParticles()-1],MM_Egamma_Bkgd_r[GetProtons()->GetNParticles()-1],Ph_time_bkgd[GetProtons()->GetNParticles()-1]);
          

    }


		

}

void	PMultiProton::ProcessScalerRead()
{
	// Fill Tagger Scalers
	FillScalers(GetTC_scaler_min(),GetTC_scaler_max(),TaggerAccScal);
}

Bool_t	PMultiProton::Write()
{
    // Write all GH1's and TObjects defined in this class
	GTreeManager::Write();
}
TLorentzVector PMultiProton::CalcMissingP4knock(const GTreeParticle &tree, Int_t tagger_index)
{
  beam2 		= TLorentzVector(0.,0.,GetTagger()->GetTaggedEnergy(tagger_index),GetTagger()->GetTaggedEnergy(tagger_index));
  missingpknock4 	= beam2 + GetTarget();
 TLorentzVector *simCorrectedParticle = new TLorentzVector[tree.GetNParticles()];
 Double_t KineticEnergy;
 Double_t correctedKineticEnergy;
 Double_t lcorrectedKineticEnergy;
 Double_t correctedMomentum;
 Double_t factor;

 //Dan's decay gamma stuff.
 
 Double_t MassRecoil;
 Double_t MissingEnergy;
 Double_t RecoilEnergy;
 

  for (int i=0; i<tree.GetNParticles();i++) {
    


         simCorrectedParticle[i] = tree.Particle(i);
         //KineticEnergy
         // do light correction 
         KineticEnergy =  tree.Particle(i).E() - protonMass();
         
	 factor =  lightCorrEst->Eval(KineticEnergy);
		   
	 lcorrectedKineticEnergy = KineticEnergy + factor*KineticEnergy;
	 //lcorrectedKineticEnergy = KineticEnergy;

	 // cout << " KE " << KineticEnergy << endl ;
	 // cout << " factor " << factor << endl ;
	 // cout << " l corr KE " << lcorrectedKineticEnergy << endl;


	 // Add 5000MeV offset to particles outside cut range.

	 Double_t theta = tree.Particle(i).Theta();

	 // cout << "Theta: " <<theta <<endl;

	 //Cut below 22 or over 167
	 if (theta < 0.3665 || theta > 2.7576) {
	   correctedKineticEnergy = 5000;
	 }


	 // Lead cut

	 /*	  if (theta < 1.8151 && theta > 1.32645) {
	   correctedKineticEnergy = 5000;
	 }
	 */


	 // If theta is greater than 90 degrees, map it to less than so can use symmetry.

	 if (theta > 1.5708 && theta < 2.7576) {
	  
	   theta = (0 - theta) + ( 2 * TMath::PiOver2());
	 }

	 if (theta > 0.383972 && theta < 1.5708) {
	 // Lead condition
	 // if (theta > 0.383972 && theta < 1.32645) {
	   
	   correctedKineticEnergy = (lcorrectedKineticEnergy + 
	 				     energyLoss->Interpolate(theta, lcorrectedKineticEnergy));

	 }


	 //cout << "Total corrected ke: " << correctedKineticEnergy << endl;

	 simCorrectedParticle[i].SetE(correctedKineticEnergy + protonMass());
	 correctedMomentum = sqrt((correctedKineticEnergy + protonMass())*(correctedKineticEnergy + protonMass()) - protonMass()*protonMass());

	 //cout << "Corrected mom: " << correctedMomentum << endl;
	 simCorrectedParticle[i].SetRho(correctedMomentum);

	 missingpknock4 = missingpknock4 - simCorrectedParticle[i] ;
    
	 // missingpknock4 = missingpknock4 - tree.Particle(i);


	 //Decay gamma from Dan's code
	 
	 MissingEnergy = beam2.E() - (simCorrectedParticle[i].E()-protonMass());
          if(i==tree.GetNParticles()-1){ //for last detected proton
            // //12C
            //  MassRecoil=9327.004;
	    //  if(tree.GetNParticles()==2)MassRecoil=9327.004;
	    //  if(tree.GetNParticles()==3)MassRecoil=8408.00;
	    //  if(tree.GetNParticles()==4)MassRecoil=7483.552;
	   
	    // //208Pb
	     MassRecoil=191866.8177;
	     if(tree.GetNParticles()==2)MassRecoil=191866.8177;
	     if(tree.GetNParticles()==3)MassRecoil=190937.361;
	     if(tree.GetNParticles()==4)MassRecoil=190006.714;
	     if(tree.GetNParticles()==5)MassRecoil=189068.282;
	     if(tree.GetNParticles()==6)MassRecoil=188131.788;
 


	    RecoilEnergy =  missingpknock4.Rho()*missingpknock4.Rho();
	    RecoilEnergy = RecoilEnergy/(2*MassRecoil);
          if(RecoilEnergy<0.)RecoilEnergy=-1.0*RecoilEnergy;

	 //    /
	    MissingEnergy= MissingEnergy - RecoilEnergy; 
	    // cout << "Missing EnErgy   " << MissingEnergy << "mass  " << missingpknock4.E() << "£Recoil Energy " << RecoilEnergy << "i   " << i << "tree   " << tree.GetNParticles() << endl;
	    //   cout << "p4P" << missingpknock4.E() << "  beam=" << beam2.E() << "  TargetE=" << GetTarget().E() << endl; 
	    //missingpknock4  = TLorentzVector(0.,0.,0.00001,MissingEnergy); //overwrite previous fudge!
	   //  cout << "Missing energy 4 vector" << MissE.M();
           
	  
	    // missingpknock4  = TLorentzVector(0.,0.,0.,MissingEnergy);
          //else(missingpknock4  = TLorentzVector(0.,0.,0.,999.));
	  // cout << "Missing energy 4 vector" << missingpknock4.M();
	 }	 

	 

  }
 		
  
				 
  return missingpknock4;

}

// ---------------------- --------------------------- --------------------- ------------------------

void PMultiProton::FillTimeCutPknock(const GTreeParticle& tree, GH1* gHist)
{
  Double_t time_proton[10];
 
 
  for (Int_t i = 0; i < tree.GetNParticles(); i++) {
    //    time_proton[i] = tree.GetTime(i) ; // use this if time is used
    time_proton[i] = tree.Particle(i).E(); // is the energy, just called the time, because before I was using the time
    //    printf("Time i=%d = %.3f ; ",i,time_proton[i]);
  }
  if(tree.GetNParticles() > 0) {
    at_min_time = (int)TMath::LocMax(tree.GetNParticles(),time_proton); // use this one if energy is used
    //    at_min_time = (int)TMath::LocMin(tree.GetNParticles(),time_proton); // use this one if time is used
    //    printf(" minimum for i=%d \n",at_min_time);
    for (Int_t j = 0; j < GetTagger()->GetNTagged(); j++)
      {
            // Is tagger channel rejected by user?
	if(GetTagger()->GetTaggedChannel(j) < GetTC_cut_min()) continue;
	if(GetTagger()->GetTaggedChannel(j) > GetTC_cut_max()) continue;

	//	time_calc = GetTagger()->GetTaggedTime(j) - tree.GetTime(at_min_time) + (tree.GetNParticles()*500);
	//	printf("Beta = %.3f \n",tree.Particle(at_min_time).Beta()); 
	if(tree.Particle(at_min_time).Beta() > 0.0 && tree.Particle(at_min_time).Beta() <=1.0) {
	  //	  time_calc = GetTagger()->GetTaggedTime(j) +  (tree.GetNParticles()*500); // no correction
	  //  time_calc = GetTagger()->GetTaggedTime(j) - 0.25 / (tree.Particle(at_min_time).Beta()*TMath::C()) +  (tree.GetNParticles()*500);
	  time_calc = GetTagger()->GetTaggedTime(j) - 0.25 / (tree.Particle(at_min_time).Beta()*TMath::C());
	}
	//	else time_calc = GetTagger()->GetTaggedTime(j) +  (tree.GetNParticles()*500);
	else time_calc = GetTagger()->GetTaggedTime(j);
	if((GHistBGSub::IsPrompt(time_calc)) || (GHistBGSub::IsRandom(time_calc))) gHist->Fill(time_calc);
      }
  }
}

//------------------ ---------------------------- -------------------------- ----------------------

void PMultiProton::FillMissingMassPknock(const GTreeParticle& tree, GH1* gHist, TH2F* tHist_MM_incidentEgamma_pr, TH2F* tHist_MM_incidentEgamma_r, Bool_t TaggerBinning)
{

        for (Int_t j = 0; j < GetTagger()->GetNTagged(); j++)
		{
		  FillMissingMassPknock(tree, j, gHist, tHist_MM_incidentEgamma_pr, tHist_MM_incidentEgamma_r, TaggerBinning);
		}
}

//------------------- ------------------------- ----------------------------------------------------

//Decay gamma function from Dan's Code
// Removed gHist_r and gHist_pr from arguments and fill. Were before GH1* phHist


void PMultiProton::FillMissingMassPknockEgamma(const GTreeParticle& treeP,const GTreeParticle& treeG, GH1* phHist, TH2F* gHistK_pr, TH2F* gHistK_r , GH1* phHistK, Bool_t TaggerBinning)
{

        for (Int_t j = 0; j < GetTagger()->GetNTagged(); j++)
		{
		  FillMissingMassPknockEgamma(treeP,treeG, j, phHist, gHistK_pr, gHistK_r, phHistK, TaggerBinning);
		}
}


//--------------------- ----------------------- ------------------------ ---------------------

void PMultiProton::FillMissingMassPknock(const GTreeParticle& tree, Int_t tagger_index, GH1* gHist, TH2F* tHist_MM_incidentEgamma_pr, TH2F* tHist_MM_incidentEgamma_r, Bool_t TaggerBinning)
{
    // Is tagger channel rejected by user?
    if(GetTagger()->GetTaggedChannel(tagger_index) < GetTC_cut_min()) return;
    if(GetTagger()->GetTaggedChannel(tagger_index) > GetTC_cut_max()) return;

    // calc particle time diff
    //    time2 = GetTagger()->GetTaggedTime(tagger_index) - tree.GetTime(at_min_time) ; //NB time is just taken from the FIRST PROTON !!!!!!!
    if(tree.GetNParticles()>0)  time2 =  GetTagger()->GetTaggedTime(tagger_index) - 0.25 / (tree.Particle(at_min_time).Beta()*TMath::C()) ; // New with correction for time traveling and removed time of Cluster

    //if(tree.GetNParticles()>3){
      //cout << "number of particles" << tree.GetNParticles() << "time for protons" <<  tree.GetTime(0) << "  " <<  tree.GetTime(1) <<  "  " <<  tree.GetTime(2) <<  "  " <<  tree.GetTime(3) <<  "  " <<  tree.GetTime(4) <<  "  " <<  tree.GetTime(5) << endl;
      // }
    //for (int i=0; i<tree.GetNParticles();i++) {    
    // calc missing p4
    
    if(tree.GetNParticles()>0) {
      missingpknock4 = CalcMissingP4knock(tree,tagger_index);


  // int_t number_prot = tree.GetNParticles();
  // Float_t mass_daughter = (208 - number_prot)*931.494;
  // missingpknock4 = missingpknock4-mass_daughter; //Pb208 convert to mass excess

  // //if(GetTarget()<150.){missingpknock4 = missingpknock4-((208-tree.GetNParticles())*931.494);} //12C convert to mass excess

   // Fill GH1
      if(TaggerBinning)   gHist->Fill(missingpknock4.M(),time2, GetTagger()->GetTaggedChannel(tagger_index));
      else gHist->Fill(missingpknock4.M(),time2);

    }



    	// Fill missing mass vs incident E_gamma histograms

    /*   if(TaggerBinning) {
      printf("Missing Mass = %.3e  Incident Photon Energy = %.3e \n",missingpknock4.M(),GetTagger()->GetTaggedEnergy(tagger_index));
      if(GHistBGSub::IsPrompt(time2))  tHist_MM_incidentEgamma_pr->Fill(missingpknock4.M(),GetTagger()->GetTaggedEnergy(tagger_index));
      if(GHistBGSub::IsRandom(time2))  tHist_MM_incidentEgamma_r->Fill(missingpknock4.M(),GetTagger()->GetTaggedEnergy(tagger_index));

    }

    else {*/
    // printf("Missing Mass = %.3e  Incident Photon Energy = %.3e \n",missingpknock4.M(),GetTagger()->GetTaggedEnergy(tagger_index));
    if(GHistBGSub::IsPrompt(time2))  tHist_MM_incidentEgamma_pr->Fill(missingpknock4.M(),GetTagger()->GetTaggedEnergy(tagger_index));
    if(GHistBGSub::IsRandom(time2))  tHist_MM_incidentEgamma_r->Fill(missingpknock4.M(),GetTagger()->GetTaggedEnergy(tagger_index));
      //  }



}

//--------------------------- --------------------- --------------------------------------------

// Another decay gamma function from Dan's code
// --------------------- ---------------------- ----------------------- ------------------------
// Added extra GH2 and GH1 arguments for non-coincident gammas
// Removed TH2F* gHist_r and gHist_pr 8/3/17

void PMultiProton::FillMissingMassPknockEgamma(const GTreeParticle& treeP,const GTreeParticle& treeG, Int_t tagger_index, GH1* phHist, TH2F* gHistK_pr, TH2F* gHistK_r, GH1* phHistK, Bool_t TaggerBinning)
{
  double E_gamma_at[1000];
  double E_gamma_bkgd_at[1000];
  double oangle;
  int j,k;


  totalPhotonEnergy = 0.0;
  numberOfCoincidentGammas = 0;
  totalBackgroundEnergy = 0.0;
  numberOfBackgroundGammas = 0;

    // Is tagger channel rejected by user?
    if(GetTagger()->GetTaggedChannel(tagger_index) < GetTC_cut_min()) return;
    if(GetTagger()->GetTaggedChannel(tagger_index) > GetTC_cut_max()) return;

    // calc particle time diff
    //    time2 = GetTagger()->GetTaggedTime(tagger_index) - treeP.GetTime(at_min_time) ; //NB time is just taken from the FIRST PROTON !!!!!!!
    if(treeP.GetNParticles()>0)  time2 =  GetTagger()->GetTaggedTime(tagger_index) - 0.25 / (treeP.Particle(at_min_time).Beta()*TMath::C()) ; // New with correction for time traveling and removed time of Cluster

    //if(treeP.GetNParticles()>3){
      //cout << "number of particles" << treeP.GetNParticles() << "time for protons" <<  treeP.GetTime(0) << "  " <<  treeP.GetTime(1) <<  "  " <<  treeP.GetTime(2) <<  "  " <<  treeP.GetTime(3) <<  "  " <<  treeP.GetTime(4) <<  "  " <<  treeP.GetTime(5) << endl;
      // }
    //for (int i=0; i<treeP.GetNParticles();i++) {    
    // calc missing p4

    // cout << "START PKNOCKEGAMMA!!! --------------------- \n" << endl;
    // printf("Total gamma energy = %.3e \n", totalPhotonEnergy);
    // printf("Number of coincident = %d \n", numberOfCoincidentGammas); 


    if(treeP.GetNParticles()>0) {
      missingpknock4 = CalcMissingP4knock(treeP,tagger_index);
      for (j=0; j<treeG.GetNParticles(); j++) {
  
	int DecGammaOK=1;
	int DecGammaBkgd = 1;
	int ProtonsOK=1;
        int DecGammaCount=0.;
        double DecGamma_time=0.;
	// Added to keep track of non-coincident background
	int DecGammaBkgdCount=0;

	

        DecGamma_time = treeP.GetTime(at_min_time) - treeG.GetTime(j);
	if(DecGamma_time <-10. || DecGamma_time>10.)DecGammaOK=0; // gam timing coincidence fast proton
	if(DecGamma_time >-40. || DecGamma_time <-180.)DecGammaBkgd=0; // don't select out of time protons for coincidence GH2
	 // if(DecGamma_time <-10. || DecGamma_time>10.)DecGammaBkgd=0; // don't select coincident 
	 if(treeG.Particle(j).E()>10.) {
	   DecGammaOK=0; 
	   DecGammaBkgd=0; //dont keep high energy stuff
	 }
	 //if(DecGamma_time <-10. || DecGamma_time>10.)DecGammaBkgd=0;
	 //if(DecGamma_time <-10. || DecGamma_time>10.)DecGammaOK=0;

	for(k=0; k<treeP.GetNParticles();k++) {
	  oangle = treeG.Particle(j).Angle((treeP.Particle(k).Vect()))*TMath::RadToDeg();         
	  if(oangle <= 35.){DecGammaOK=0;DecGammaBkgd=0;} // gamma too close to a proton cluster
	  //cout << "Dec Gamma time   " <<  DecGamma_time << endl;
	}


	if(DecGammaOK==1){

	  E_gamma_at[j] = treeG.Particle(j).E();

	  DecGammaCount++;

	  totalPhotonEnergy = totalPhotonEnergy + E_gamma_at[j];
	  //printf("E_gamma_at[%d] = %.3e \n", j, E_gamma_at[j]);

	  numberOfCoincidentGammas++;

	} //fill if none of prptons close to gamma


        else{E_gamma_at[j] = 0.;} // reject gamma and set energy to zero

	if(DecGammaBkgd==1){



	  E_gamma_bkgd_at[j] = treeG.Particle(j).E();

	  DecGammaBkgdCount++;

	  //totalBackgroundEnergy = totalBackgroundEnergy + E_gamma_bkgd_at[j];

	  // numberOfBackgroundGammas++;


	}



	else{E_gamma_bkgd_at[j] = 0.0;}
	  
	// printf("Number of photons? %d \n", treeG.GetNParticles());
	// printf("Gamma time = %.3e \n", DecGamma_time);
	// printf("E_gamma_at[%d] = %.3e \n", j, E_gamma_at[j]);
	// printf("DecGammaCount = %d \n", DecGammaCount);
	// printf("DecGammaBkgdCount = %d \n", DecGammaBkgdCount);

	//printf("Tagger energy = %.3e \n", GetTagger()->GetTaggedEnergy(tagger_index));

        // cout << "j   " << j << "k   " << k << "open angle   " << oangle << endl ;
  // int_t number_prot = treeP.GetNParticles();
  // Float_t mass_daughter = (208 - number_prot)*931.494;
  // missingpknock4 = missingpknock4-mass_daughter; //Pb208 convert to mass excess
       
  // //if(GetTarget()<150.){missingpknock4 = missingpknock4-((208-treeP.GetNParticles())*931.494);} //12C convert to mass exces


   // Fill GH1
	if(DecGammaCount==1 && GetTagger()->GetTaggedEnergy(tagger_index)> 350 ){ //only fill if 1 good decay gamma below 10 MeV
       
	  //printf("Number of protons %d time2=%.3e \n",treeP.GetNParticles(),time2);
	  //printf("Tagger energy = %.3e \n", GetTagger()->GetTaggedEnergy(tagger_index));
	  //	  cout << "Number of protons " << treeP.GetNParticles() << "  time2=" << time2 << endl;
	  if(TaggerBinning)   {
	      //	    gHist->Fill(missingpknock4.M(),E_gamma_at[j],time2, GetTagger()->GetTaggedChannel(tagger_index));

	    //This code has been replaced outside the loop to deal with more than 1 coincident gamma.
	    //It WORKED FOR ONE!!!
	    /*

	    if(GHistBGSub::IsPrompt(time2))  {
	      gHist_pr->Fill(missingpknock4.M(),E_gamma_at[j]);
	      //  printf("Pass prompt \n");
	    }
	    else if(GHistBGSub::IsRandom(time2))  {
	      gHist_r->Fill(missingpknock4.M(),E_gamma_at[j]);
	      // printf("Pass random \n");
	    }
	    //  else printf("\n");

	    */

	    phHist->Fill(DecGamma_time,time2, GetTagger()->GetTaggedChannel(tagger_index));


	  }
	  else {

	    /*

	    if(GHistBGSub::IsPrompt(time2))  {
	      gHist_pr->Fill(missingpknock4.M(),E_gamma_at[j]);
	      //  printf("Pass prompt \n");
	    }

	    else if(GHistBGSub::IsRandom(time2))  {
	      gHist_r->Fill(missingpknock4.M(),E_gamma_at[j]);
	      //  printf("Pass random \n");
	    }
	    //	    else printf("\n");
	    //    gHist->Fill(missingpknock4.M(),E_gamma_at[j],time2);

	    */
	    phHist->Fill(DecGamma_time,time2);


	  }
	}

	//	printf("Background PLOT DecGammaBkgdCount=%d count=%d time=%.3e  Energy tagger=%.3e \n", DecGammaBkgdCount,DecGammaBkgd,DecGamma_time,GetTagger()->GetTaggedEnergy(tagger_index));
	//Added by K to fill background GH2/1

	
	if(DecGammaBkgdCount==1 && GetTagger()->GetTaggedEnergy(tagger_index)>350) {
	  //	  printf("PASSED BACKGROUND \n");
	  if(TaggerBinning) {

	    

	    //gHistK->Fill(missingpknock4.M(), E_gamma_bkgd_at[j], time2, GetTagger()->GetTaggedChannel(tagger_index));
	    if(GHistBGSub::IsPrompt(time2))  gHistK_pr->Fill(missingpknock4.M(),E_gamma_bkgd_at[j]);
	    if(GHistBGSub::IsRandom(time2))  gHistK_r->Fill(missingpknock4.M(),E_gamma_bkgd_at[j]);


	    

	    phHistK->Fill(DecGamma_time, time2, GetTagger()->GetTaggedChannel(tagger_index));


	  }
	  else {

	    

	    //	    gHistK->Fill(missingpknock4.M(), E_gamma_bkgd_at[j], time2);
	    if(GHistBGSub::IsPrompt(time2))  gHistK_pr->Fill(missingpknock4.M(),E_gamma_bkgd_at[j]);
	    if(GHistBGSub::IsRandom(time2))  gHistK_r->Fill(missingpknock4.M(),E_gamma_bkgd_at[j]);

	    

	    phHistK->Fill(DecGamma_time, time2);
	  }

	}
      
  

      }
    }


    // Fill the appropriate histogram with the decay gamma information

    if (numberOfCoincidentGammas > 0 && GetTagger()->GetTaggedEnergy(tagger_index)>350) {

      // printf("Number of coincident gammas = %d \n", numberOfCoincidentGammas);

      numCoincidentGammas_MinusOne = numberOfCoincidentGammas - 1;

      //printf("Number of coincident gammas_MINUS ONE = %d \n", numCoincidentGammas_MinusOne);
     

	if(GHistBGSub::IsPrompt(time2)) {


	  // gHist_pr->Fill(missingpknock4.M(), totalPhotonEnergy); // Now filling directly below

	  MM_Egamma_pr[treeP.GetNParticles()-1][numCoincidentGammas_MinusOne]->Fill(missingpknock4.M(), totalPhotonEnergy);


	  //cout << "Passed Prompt!" << endl;
	  //printf("Total photon Energy = %.3e \n", totalPhotonEnergy);
	}

	else if(GHistBGSub::IsRandom(time2)) {


	  // gHist_r->Fill(missingpknock4.M(), totalPhotonEnergy);

	  MM_Egamma_r[treeP.GetNParticles()-1][numCoincidentGammas_MinusOne]->Fill(missingpknock4.M(), totalPhotonEnergy);

	  //cout << "Passed Random!" << endl;
	}

	//phHist->Fill(DecGamma_time, time2, GetTagger()->GetTaggedChannel(tagger_index));

    }

    
    /*
    if (numberOfBackgroundGammas > 0 && GetTagger()->GetTaggedEnergy(tagger_index)>350) {

      //printf("Number of background gammas = %d \n", numberOfBackgroundGammas);
      
      numBackgroundGammas_MinusOne = numberOfBackgroundGammas - 1;

      //printf("Number of background gammas_MINUS ONE = %d \n", numBackgroundGammas_MinusOne);


      if(GHistBGSub::IsPrompt(time2)) {

	gHistK_pr->Fill(missingpknock4.M(),totalBackgroundEnergy);

      }
      
      if(GHistBGSub::IsRandom(time2)) {


	gHistK_r->Fill(missingpknock4.M(),totalBackgroundEnergy);


      }


    }
    */


    //printf("Number of coincident = %d \n", numberOfCoincidentGammas);
    //cout << "END PKNOCKEGAMMA!!! ------------------- \n" << endl;
    //printf("Total gamma energy = %.3e \n", totalPhotonEnergy);


}

// ---------------------- ------------------------------- -----------------------------------------

//Function inserted by KP to read TFile and open TGraph.

TGraph* PMultiProton::GetTGraph(const char *filename, const char *graphname)
{

  TFile *theFile = new TFile(filename);
  TGraph *theGraph = (TGraph*)theFile->Get(graphname); //Get and cast type as TGraph.

  return theGraph;

}

TGraph2D* PMultiProton::GetTGraph2D(const char *filename, const char *graphname)
{
  TFile *theFile = new TFile(filename);
  TGraph2D *theGraph = (TGraph2D*)theFile->Get(graphname);

  return theGraph;
}


