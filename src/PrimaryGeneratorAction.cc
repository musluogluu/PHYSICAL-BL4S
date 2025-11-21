#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleDefinition.hh"
#include "G4Event.hh"
//commit
PrimaryGeneratorAction::PrimaryGeneratorAction() {
    fParticleGun = new G4ParticleGun(1);

    // Başlangıçta örnek bir parçacık tanımlayalım (ilk olarak pozitron kullanılacak)
    auto particle = G4ParticleTable::GetParticleTable()->FindParticle("e+");
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleEnergy(1.0 * GeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., -50.*cm));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
    G4int evtID = event->GetEventID();
    G4ParticleDefinition* particle = nullptr;

    if (evtID < 3666) {
        particle = G4ParticleTable::GetParticleTable()->FindParticle("e+");       // pozitron
    } else if (evtID < 3666 + 1668) {
        particle = G4ParticleTable::GetParticleTable()->FindParticle("pi+");      // pozitif pion
    } else if (evtID < 3666 + 1668 + 333) {
        particle = G4ParticleTable::GetParticleTable()->FindParticle("kaon+");    // pozitif kaon
    } else {
        particle = G4ParticleTable::GetParticleTable()->FindParticle("proton");   // proton
    }

    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->GeneratePrimaryVertex(event);
}
