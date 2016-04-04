# Planck
This contains my `qmk_firmware`-compatible Planck keymap.

## Flashing

* Clone and setup the repository at https://github.com/jackhumbert/qmk_firmware.git - pay special attention to the dependencies
* Copy the `lytedev.c` file in this directory of this repo to `qmk_firmware/keyboard/planck/lytedev.c`
* From `qmk_firmware/keyboard/planck`, run `make KEYMAP=lytedev` to generate your firmware
* Press the flash button on the Planck keyboard
* From `qmk_firmware/keyboard/planck` (same as last terminal command directory), run `make dfu` as root (`sudo make dfu`)

That should be it! Your Planck keyboard should now be flashed with this layout.
