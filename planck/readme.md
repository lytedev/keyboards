# Planck

This contains my `qmk_firmware`-compatible Planck keymap.


## Flashing

* Clone and setup the repository at https://github.com/jackhumbert/qmk_firmware.git - pay special attention to the dependencies (for arch users, `pacman -S avr-libc avr-gcc` and `dfu-programmer` in the AUR)
* Run the following command, setting `QMK_DIR` to the directory of the repo you cloned in the last step:

		QMK_DIR="$HOME/qmk_firmware" make

* And then flash your keyboard by pressing the reset button in the bottom of it (or the `RESET` key if you have it programmed in) and run (don't forget to set `QMK_DIR` to the directory of the repo we cloned in the first step!):

		QMK_DIR="$HOME/qmk_firmware" sudo make dfu

**Tip**: If you don't have an extra keyboard to send the `make dfu` command, just prepend `sleep 10 &&` to it to give yourself 10 seconds to hit the flash button.

That should be it! Your Planck keyboard should now be flashed with this layout.


## Modifying

Just modify `keymap.c` and repeat the steps above for flashing! Easy.

