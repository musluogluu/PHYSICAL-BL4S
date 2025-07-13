# neutronSim

A simple Geant4 simulation project for neutron production and detection

## Build Instructions

**Note:** Make sure your Geant4 environment is properly set before building.
This typically means sourcing the `geant4.sh`, `geant4.csh`, or `geant4.zsh` file, depending on your shell:

```bash
source /path/to/geant4-install/bin/geant4.sh
       /geant4_install/geant4-v11.3.0-install/bin/geant4.sh
       
mkdir build && cd build
cmake ../
make 
```

## Run Instructions
```bash 
./neutronSim ../vis.mac
```
