# Cargo
Cargo is a simplified key/value (document style) storage engine that is flexible and easy to customize using storage drivers that follow the Cargo storage driver protocol.

# Setup
To use Cargo, just copy the project file and link against libCargo.a, then include <Cargo/Cargo.h> in your files.

## Storage Driver
Cargo has made it easy to create custom storage drivers, iCloud and Dropbox are included as well as one for NSUserdefaults in the CargoExample project.

## Code
``
This is code
``