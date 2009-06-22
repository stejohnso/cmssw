import FWCore.ParameterSet.Config as cms

pfAllMuons = cms.EDProducer("PdgIdPFCandidateSelector",
    src = cms.InputTag("noPileUp"),
    pdgId = cms.vint32( -13, 13)
)



