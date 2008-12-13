#ifndef ElectronPixelSeedProducer_h
#define ElectronPixelSeedProducer_h

//
// Package:         RecoEgamma/ElectronTrackSeedProducers
// Class:           ElectronPixelSeedProducer
//
// Description:     Calls ElectronPixelSeedGenerator
//                  to find TrackingSeeds.


#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaTowerIsolation.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/EDProduct.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

class  ElectronPixelSeedGenerator;
class SeedFilter;
///class TrajectorySeedCollection;

class ElectronPixelSeedProducer : public edm::EDProducer
{
 public:

  explicit ElectronPixelSeedProducer(const edm::ParameterSet& conf);

  virtual ~ElectronPixelSeedProducer();

  virtual void beginJob(edm::EventSetup const&iSetup);
  virtual void produce(edm::Event& e, const edm::EventSetup& c);

 private:

  void filterClusters(const edm::Handle<reco::SuperClusterCollection> &superClusters,
   const CaloTowerCollection *towers, reco::SuperClusterRefVector &sclRefs);
  void filterSeeds(edm::Event& e, const edm::EventSetup& setup, reco::SuperClusterRefVector &sclRefs);

  edm::InputTag superClusters_[2];
  edm::InputTag hcalTowers_;
  edm::InputTag initialSeeds_;

  const edm::ParameterSet conf_;
  ElectronPixelSeedGenerator *matcher_;
  SeedFilter * seedFilter_;

  TrajectorySeedCollection *theInitialSeedColl;

  EgammaTowerIsolation *towerIso1_;
  EgammaTowerIsolation *towerIso2_;

  // parameters for H/E
  double maxHOverEDepth1_;
  double maxHOverEDepth2_;
  double hOverEConeSize_;
  double hOverEPtMin_;

  // super cluster Et cut
  double SCEtCut_;

  unsigned long long cacheID_;

  bool fromTrackerSeeds_;
  bool prefilteredSeeds_;

};

#endif



