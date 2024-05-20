# setup_qmk.sh
#!/bin/bash

# Set the QMK home path relative to the script location
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
QMK_HOME="$SCRIPT_DIR/qmk_firmware"

# Run QMK setup if needed
qmk setup -y -H $QMK_HOME

# Set global userspace path
qmk config user.overlay_dir="$(realpath .)"

# Print config
qmk config
