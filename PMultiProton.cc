#include "PMultiProton.h"


PMultiProton::PMultiProton()
{ 
    time 	= new GH1("time", 	"time", 	1400, -700, 700);
    time_cut 	= new GH1("time_cut", 	"time_cut", 	1400, -700, 700);

    time_2g 	= new GH1("time_2g",	"time_2g", 	1400, -700, 700);
    time_2g_cut = new GH1("time_2g_cut","time_2g_cut", 	1400, -700, 700);

    char Title_h1[60];
    char Name_h1[60];
  
    for (int i=0; i<6; i++) {
      sprintf(Title_h1,"Missing Mass %d protons knockout",i+1);
      sprintf(Name_h1,"Missing_Mass_%d",i+1);
      MM[i] = new GH1(Name_h1,Title_h1, 2000,187000,197000);     
    }
    TaggerAccScal = new TH1D("TaggerAccScal","TaggerAccScal",352,0,352);

    //const Double_t protonMass = 938.2720813;

    //Open root file with light correction TGraph
    lightCorrection = new TGraph();
    lightCorrection = GetTGraph("corr_cb_g.root", "Graph");
    cout << "TEST: " << lightCorrection->Eval(50) << endl;

    //Open all the theta dependent energy loss TGraphs...

    deg22Correction = new TGraph();
    deg22Correction = GetTGraph("TGLoss.root", "deg22");
    cout << "TEST22: " << deg22Correction->Eval(62.7) << endl;
    deg24Correction = new TGraph();
    deg24Correction = GetTGraph("TGLoss.root", "deg24");
    cout << "TEST24: " << deg24Correction->Eval(62.7) << endl;
    deg26Correction = new TGraph();
    deg26Correction = GetTGraph("TGLoss.root", "deg26");
    cout << "TEST26: " << deg26Correction->Eval(62.7) <<endl;
    deg28Correction = new TGraph();
    deg28Correction = GetTGraph("TGLoss.root", "deg28");
    cout << "TEST28: " << deg28Correction->Eval(62.7) <<endl;

    deg30Correction = new TGraph();
    deg30Correction = GetTGraph("TGLoss.root", "deg30");
    cout << "TEST30: " << deg30Correction->Eval(62.7) <<endl;
    deg32Correction = new TGraph();
    deg32Correction = GetTGraph("TGLoss.root", "deg32");
    cout << "TEST32: " << deg32Correction->Eval(62.7) <<endl;
    deg34Correction = new TGraph();
    deg34Correction = GetTGraph("TGLoss.root", "deg34");
    cout << "TEST34: " << deg34Correction->Eval(62.7) <<endl;
    deg36Correction = new TGraph();
    deg36Correction = GetTGraph("TGLoss.root", "deg36");
    cout << "TEST36: " << deg36Correction->Eval(62.7) <<endl;
    deg38Correction = new TGraph();
    deg38Correction = GetTGraph("TGLoss.root", "deg38");
    cout << "TEST38: " << deg38Correction->Eval(62.7) <<endl;
   
    deg40Correction = new TGraph();
    deg40Correction = GetTGraph("TGLoss.root", "deg40");
    cout << "TEST40: " << deg40Correction->Eval(62.7) <<endl;
    deg42Correction = new TGraph();
    deg42Correction = GetTGraph("TGLoss.root", "deg42");
    cout << "TEST42: " << deg42Correction->Eval(62.7) <<endl;
    deg44Correction = new TGraph();
    deg44Correction = GetTGraph("TGLoss.root", "deg44");
    cout << "TEST44: " << deg44Correction->Eval(62.7) <<endl;
    deg46Correction = new TGraph();
    deg46Correction = GetTGraph("TGLoss.root", "deg46");
    cout << "TEST46: " << deg46Correction->Eval(62.7) <<endl;
    deg48Correction = new TGraph();
    deg48Correction = GetTGraph("TGLoss.root", "deg48");
    cout << "TEST48: " << deg48Correction->Eval(62.7) <<endl;
    
    deg50Correction = new TGraph();
    deg50Correction = GetTGraph("TGLoss.root", "deg50");
    cout << "TEST50: " << deg50Correction->Eval(62.7) <<endl;
    deg52Correction = new TGraph();
    deg52Correction = GetTGraph("TGLoss.root", "deg52");
    cout << "TEST52: " << deg52Correction->Eval(62.7) <<endl;
    deg54Correction = new TGraph();
    deg54Correction = GetTGraph("TGLoss.root", "deg54");
    cout << "TEST54: " << deg54Correction->Eval(62.7) <<endl;
    deg56Correction = new TGraph();
    deg56Correction = GetTGraph("TGLoss.root", "deg56");
    cout << "TEST56: " << deg56Correction->Eval(62.7) <<endl;
    deg58Correction = new TGraph();
    deg58Correction = GetTGraph("TGLoss.root", "deg58");
    cout << "TEST58: " << deg58Correction->Eval(62.7) <<endl;

    deg60Correction = new TGraph();
    deg60Correction = GetTGraph("TGLoss.root", "deg60");
    cout << "TEST60: " << deg60Correction->Eval(62.7) <<endl;
    deg62Correction = new TGraph();
    deg62Correction = GetTGraph("TGLoss.root", "deg62");
    cout << "TEST62: " << deg62Correction->Eval(62.7) <<endl;
    deg64Correction = new TGraph();
    deg64Correction = GetTGraph("TGLoss.root", "deg64");
    cout << "TEST64: " << deg64Correction->Eval(62.7) <<endl;
    deg66Correction = new TGraph();
    deg66Correction = GetTGraph("TGLoss.root", "deg66");
    cout << "TEST66: " << deg66Correction->Eval(62.7) <<endl;
    deg68Correction = new TGraph();
    deg68Correction = GetTGraph("TGLoss.root", "deg68");
    cout << "TEST68: " << deg68Correction->Eval(62.7) <<endl;
    
    deg70Correction = new TGraph();
    deg70Correction = GetTGraph("TGLoss.root", "deg70");
    cout << "TEST70: " << deg70Correction->Eval(62.7) <<endl;
    deg72Correction = new TGraph();
    deg72Correction = GetTGraph("TGLoss.root", "deg72");
    cout << "TEST72: " << deg72Correction->Eval(62.7) <<endl;
    deg74Correction = new TGraph();
    deg74Correction = GetTGraph("TGLoss.root", "deg74");
    cout << "TEST74: " << deg74Correction->Eval(62.7) <<endl;
    deg76Correction = new TGraph();
    deg76Correction = GetTGraph("TGLoss.root", "deg76");
    cout << "TEST76: " << deg76Correction->Eval(62.7) <<endl;

    //End of distgusting mess of code loading TGraphs...
  
    

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
	
	// fill missing mass, protons
    FillMissingMassPknock(*GetProtons(),MM[GetProtons()->GetNParticles()-1]);
	

		

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


  //************* Apply light correction from graph provided by Dominik Werthmoller ********

  //Create an array to hold copy of vectors
  TLorentzVector *lightCorrectedParticle = new TLorentzVector[tree.GetNParticles()];

  //Apply light correction to measured energy.
  /*
  for (int i=0; i<tree.GetNParticles(); i++) {
    
    //Get measured energy from TLVector by subtracting proton mass.
    Double_t measuredEnergy = tree.Particle(i).E() - protonMass();

    //Create copy of particle tree for corrections.
     lightCorrectedParticle[i] = tree.Particle(i);
     
     cout << "Measured KE " << i << " : " << measuredEnergy <<endl;
     

     //Apply correction to kinetic energy.
      Double_t correctedEnergy = ((measuredEnergy * lightCorrection->Eval(measuredEnergy)) 
     			 + measuredEnergy);

     //Test
     // Double_t correctedEnergy = measuredEnergy;

      cout << "Light Corrected " << i << " : " << correctedEnergy << endl;
     

     //Set total corrected energy by adding back proton mass.
     //lightCorrectedParticle[i].SetE(correctedEnergy + protonMass());
     
     //Set total energy to just the kinetic energy.
     lightCorrectedParticle[i].SetE(correctedEnergy);
  }
  */
  
  //************ Apply energy corrections from KP sims ***************************************

  //Create TLVector array to hold corrected particle data.
  TLorentzVector *energyCorrectedParticle = new TLorentzVector[tree.GetNParticles()];

  for (int i=0; i<tree.GetNParticles(); i++) {

    //TEST
    lightCorrectedParticle[i] = tree.Particle(i);
   
    

    //Apply theta cuts.
    energyCorrectedParticle[i] = CutTheta(lightCorrectedParticle[i]);

    //Get kinetic energy from total and define variables to hold total 
    //corrected kinetic energy and theta.
    // Double_t lightCorrectedEnergy = lightCorrectedParticle[i].E() - protonMass();
    
    Double_t lightCorrectedEnergy = energyCorrectedParticle[i].E() -protonMass();
    
    Double_t totalCorrectedEnergy;
    Double_t theta = energyCorrectedParticle[i].Theta();

    cout << "LC PreENERGY " << i << " : " << lightCorrectedEnergy << endl;
    

    //Start a disgusting loop to get correction from TGraph...

    if (lightCorrectedEnergy > 0.0 || lightCorrectedEnergy < 400.0) {

    if (theta > 0.3665 && theta <=0.4014) {
      
      totalCorrectedEnergy = (lightCorrectedEnergy + 
				       deg22Correction->Eval(lightCorrectedEnergy));
     // cout << "Eval: " << deg22Correction->Eval(lightCorrectedEnergy) << endl;	
    //  cout << "Light Corr: " << lightCorrectedEnergy << endl;
     // cout << "Corrected: " << totalCorrectedEnergy << endl;
       

    } else if (theta > 0.4014 && theta <= 0.4363) {
	
	 totalCorrectedEnergy = (lightCorrectedEnergy +
					 deg24Correction->Eval(lightCorrectedEnergy));
//	cout << "Eval: " << deg24Correction->Eval(lightCorrectedEnergy) << endl;
	//cout << "Light Corr: " << lightCorrectedEnergy << endl;
//	cout << "Corrected: " << totalCorrectedEnergy << endl;

    } else if (theta > 0.4363 && theta <= 0.4712) {
	  
	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg26Correction->Eval(lightCorrectedEnergy));
	  //cout << deg26Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.4712 && theta <= 0.5061) {

	  totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg28Correction->Eval(lightCorrectedEnergy));
	 // cout << deg28Correction->Eval(lightCorrectedEnergy) << endl;
	//  cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta >0.5061 && theta <= 0.5411) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg30Correction->Eval(lightCorrectedEnergy));
	 // cout << deg30Correction->Eval(lightCorrectedEnergy) << endl;
	 // cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;


    } else if (theta > 0.5411 && theta <= 0.57596) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg32Correction->Eval(lightCorrectedEnergy));
	 // cout << deg32Correction->Eval(lightCorrectedEnergy) << endl;
	//  cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.57596 && theta <= 0.6109) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg34Correction->Eval(lightCorrectedEnergy));
	 // cout << deg34Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.6109 && theta <= 0.6458) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg36Correction->Eval(lightCorrectedEnergy));
	 // cout << deg36Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.6458 && theta <= 0.6807) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg38Correction->Eval(lightCorrectedEnergy));
	 // cout << deg38Correction->Eval(lightCorrectedEnergy) << endl;
	 // cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.6807 && theta <= 0.7156) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg40Correction->Eval(lightCorrectedEnergy));
	 // cout << deg40Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.7156 && theta <= 0.7505) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg42Correction->Eval(lightCorrectedEnergy));
	 // cout << deg42Correction->Eval(lightCorrectedEnergy) << endl;
	 // cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.7505 && theta <= 0.7854) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg44Correction->Eval(lightCorrectedEnergy));
	 // cout << deg44Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.7854 && theta <= 0.8203) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg46Correction->Eval(lightCorrectedEnergy));
	  //cout << deg46Correction->Eval(lightCorrectedEnergy) << endl;
	 // cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.8203 && theta <= 0.8552) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg48Correction->Eval(lightCorrectedEnergy));
	 // cout << deg48Correction->Eval(lightCorrectedEnergy) << endl;
	 // cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.8552 && theta <= 0.8901) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg50Correction->Eval(lightCorrectedEnergy));
	 // cout << deg50Correction->Eval(lightCorrectedEnergy) << endl;
	 // cout << "Light Corr: " << lightCorrectedEnergy << endl;
	//  cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.8901 && theta <= 0.9250) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg52Correction->Eval(lightCorrectedEnergy));
	  //cout << deg52Correction->Eval(lightCorrectedEnergy) << endl;
	 // cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.9250 && theta <= 0.9599) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg54Correction->Eval(lightCorrectedEnergy));
	  //cout << deg54Correction->Eval(lightCorrectedEnergy) << endl;
	 // cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.9599 && theta <= 0.9948) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg56Correction->Eval(lightCorrectedEnergy));
	  //cout << deg56Correction->Eval(lightCorrectedEnergy) << endl;
	 // cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 0.9948 && theta <= 1.0297) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg58Correction->Eval(lightCorrectedEnergy));
	 // cout << deg58Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 1.0297 && theta <= 1.06465) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg60Correction->Eval(lightCorrectedEnergy));
	  //cout << deg60Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	 // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 1.06465 && theta <= 1.09956) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg62Correction->Eval(lightCorrectedEnergy));
	  //cout << deg62Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 1.09956 && theta <= 1.1345) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg64Correction->Eval(lightCorrectedEnergy));
	  //cout << deg64Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 1.1345 && theta <= 1.1694) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg66Correction->Eval(lightCorrectedEnergy));
	 // cout << deg66Correction->Eval(lightCorrectedEnergy) << endl;
	 // cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 1.1694 && theta <= 1.2043) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg68Correction->Eval(lightCorrectedEnergy));
	  //cout << deg68Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;
    
    } else if (theta > 1.2043 && theta <= 1.2392) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg70Correction->Eval(lightCorrectedEnergy));
	  //cout << deg70Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 1.2392 && theta <= 1.2741) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg72Correction->Eval(lightCorrectedEnergy));
	  //cout << deg72Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta > 1.2741 && theta <= 1.309) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg74Correction->Eval(lightCorrectedEnergy));
	  //cout << deg74Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  // cout << "Corrected: " << totalCorrectedEnergy <<endl;

    } else if (theta >1.309 && theta <= 1.3439) {

	   totalCorrectedEnergy = (lightCorrectedEnergy +
					   deg76Correction->Eval(lightCorrectedEnergy));
	  //cout << deg76Correction->Eval(lightCorrectedEnergy) << endl;
	  //cout << "Light Corr: " << lightCorrectedEnergy << endl;
	  //cout << "Corrected: " << totalCorrectedEnergy <<endl;
    
	  //Apply energy correction
	  //energyCorrectedParticle[i].SetE(totalCorrectedEnergy + protonMass());


    }

    }
    //Shitty abominable if else block ends!!!!!!!!!!!!!!!!

    //Apply energy correction
    if (lightCorrectedEnergy > 0.0 && totalCorrectedEnergy != 0.0 && energyCorrectedParticle[i].E() != 0.0) {
     
      energyCorrectedParticle[i].SetE(totalCorrectedEnergy + protonMass());

     //Calculate the momentum correction from the energy. Get theta/phi but don't change.
     Double_t E = energyCorrectedParticle[i].E();
     Double_t P = TMath::Sqrt((E * E) - (protonMass() * protonMass()));
     //Double_t eta = energyCorrectedParticle[i].Eta();
     //Double_t phi = energyCorrectedParticle[i].Phi();
     
     //energyCorrectedParticle[i].SetPtEtaPhiE(P, eta, phi, E);
     energyCorrectedParticle[i].SetRho(P);

    } 

    cout << "Total Corrected PostENERGY " << i << " : " << totalCorrectedEnergy << endl;
    
    }
  

  for (int i=0; i<tree.GetNParticles();i++) {
    // missingpknock4 = missingpknock4 - tree.Particle(i) ; //Original Code
    //Code with light correction included.
    // missingpknock4 = missingpknock4 - lightCorrectedParticle[i];
    //Code with light and KP corrections included?
    missingpknock4 = missingpknock4 - energyCorrectedParticle[i];

  }
 						 
  return missingpknock4;

}


void PMultiProton::FillMissingMassPknock(const GTreeParticle& tree, GH1* gHist, Bool_t TaggerBinning)
{

        for (Int_t j = 0; j < GetTagger()->GetNTagged(); j++)
		{
			FillMissingMassPknock(tree, j, gHist, TaggerBinning);
		}
}



void PMultiProton::FillMissingMassPknock(const GTreeParticle& tree, Int_t tagger_index, GH1* gHist, Bool_t TaggerBinning)
{
    // Is tagger channel rejected by user?
    if(GetTagger()->GetTaggedChannel(tagger_index) < GetTC_cut_min()) return;
    if(GetTagger()->GetTaggedChannel(tagger_index) > GetTC_cut_max()) return;

    // calc particle time diff
    time2 = GetTagger()->GetTaggedTime(tagger_index) - tree.GetTime(0); //NB time is just taken from the FIRST PROTON !!!!!!!
    
    // calc missing p4
    missingpknock4 = CalcMissingP4knock(tree,tagger_index);

   // Fill GH1
   if(TaggerBinning)   gHist->Fill(missingpknock4.M(),time2, GetTagger()->GetTaggedChannel(tagger_index));
   else gHist->Fill(missingpknock4.M(),time2);

}


//Function inserted by KP to read TFile and open TGraph.

TGraph* PMultiProton::GetTGraph(const char *filename, const char *graphname)
{

  TFile *theFile = new TFile(filename);
  TGraph *theGraph = (TGraph*)theFile->Get(graphname); //Get and cast type as TGraph.

  return theGraph;

}

//Function to apply theta cuts.

TLorentzVector PMultiProton::CutTheta(TLorentzVector Particle)
{
  
  Double_t theta = Particle.Theta();
  TLorentzVector zeroVector;
  
  if (theta > 0.3665 && theta < 1.3439) {
    
    return Particle;

    } else if (theta > 1.8151 && theta < 2.7576) {

    Double_t mapTheta = (0.0 - theta) + (2 * 1.570796327);
    Particle.SetTheta(mapTheta);

    return Particle;

    } else {

    return zeroVector;

  }
}
  

  
  






