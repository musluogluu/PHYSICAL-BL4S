# SpallationSim: Geant4 Nuclear Spallation Simulation

This project simulates nuclear spallation of a target using a proton beam. The simulation is implemented in Geant4 and was developed as part of the BL4S CERN project for pre-experimental validation.

---

## Simulation Overview

- **Target:** Tungsten (W), cylindrical shape, 15 cm diameter, 60 cm height
- **Beam:**
  - Positron=3666
  - Proton=1000
  - Positive Pion=1668
  - Positive Kaon=333
- **Output:** Neutron data saved in (`analyz_neutron_data.c`)

---

## File Directory

```bash
SpallationSim/
├── CMakeLists.txt
├── README.md
├── run.mac
├── vis.mac
├── include/
│   ├── DetectorConstruction.hh
│   ├── ActionInitialization.hh
│   ├── PrimaryGeneratorAction.hh
│   └── SteppingAction.hh
│   ├── neutronsGlobals.hh
│   ├── globals.hh
│   ├── RunAction.hh
├── src/
│   ├── DetectorConstruction.cc
│   ├── ActionInitialization.cc
│   ├── PrimaryGeneratorAction.cc
│   ├── RunAction.cc
│   ├── neutronGlobals.cc
│   ├── globals.cc
│   ├── main.cc
│   └── SteppingAction.cc
└── neutron_output.root  # output file will be saved in your home directory
```

---

## Build Instructions

```bash
mkdir build && cd build
cmake ..
make -j4
./neutronSim ../vis.mac
```

---

## Data Analysis (ROOT)

The analyze file is provided in `analyz_neutron_data.c`:

### Example Usage
```bash
root your/file/directory/neutronSimulation/analyz/analyz_neutron_data.c
```

---

## Objective

This experiment is planned to be performed during the CERN Beamline for Schools (BL4S) 2024 program by PhysiCAL team, aiming to observe neutron production via spallation.

---

## Authors

> This project was developed for the CERN Beamline for Schools (BL4S) competition. All rights reserved.

Contact: [musluoglu.mert10@gmail.com]

