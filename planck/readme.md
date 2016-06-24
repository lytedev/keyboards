# Planck
This contains my `qmk_firmware`-compatible Planck keymap.

## Flashing

* Clone and setup the repository at https://github.com/jackhumbert/qmk_firmware.git - pay special attention to the dependencies (for arch users, `pacman -S avr-libc avr-gcc` and `dfu-programmer` in the AUR)
* Copy (or symlink if you plan on changing often) the `lytedev` folder in this directory of this repo to `qmk_firmware/keyboard/planck/keymaps/lytedev/`
* From `qmk_firmware/keyboard/planck/keymaps/lytedev/`, run `make` to generate your firmware
* Press the flash button on the Planck keyboard
* From `qmk_firmware/keyboard/planck/keymaps/lytedev/` (same as last terminal command directory), run `make dfu` as root (`sudo make dfu`)

**Tip**: If you don't have an extra keyboard to send the `make dfu` command, just prepend `sleep 10 &&` to it to give yourself 10 seconds to hit the flash button.

That should be it! Your Planck keyboard should now be flashed with this layout.

## Modifying
Just modify `lytedev/keymap.c` and repeat the steps above for flashing! Easy.

