import FWCore.ParameterSet.Config as cms

pfMuIsoDepAll = cms.EDProducer("CandIsoDepositProducer",
    src = cms.InputTag("pfMuonsPtGt5"),
    MultipleDepositsFlag = cms.bool(False),
    trackType = cms.string('candidate'),
    ExtractorPSet = cms.PSet(
        Diff_z = cms.double(0.2),#(0.2)
        ComponentName = cms.string('CandViewExtractor'),
        DR_Max = cms.double(1.0),
        Diff_r = cms.double(0.1),#(0.1)
        inputCandView = cms.InputTag(""),
        DR_Veto = cms.double(1e-05),
        DepositLabel = cms.untracked.string('')
    )                                            
)



