# Infinity Ergodox

This contains my `qmk_firmware`-compatible Infinity Ergodox keymap.


## Flashing

* Clone and setup the repository at
	https://github.com/jackhumbert/qmk_firmware.git - pay special attention to the
	dependencies (for arch users, `pacman -S avr-libc avr-gcc` and `dfu-programmer`
	in the AUR)

* Run the following command, setting `QMK_DIR` to the directory of the repo you
	cloned in the last step:

		export QMK_DIR="$HOME/qmk_firmware"
		make left

* Put the **left** hand of the ErgoDox in flashing mode
* In the same terminal (so that `QMK_DIR` is set) run:

		make dfu-left

* Repeat the previous commands replacing "`left`" with "`right`"

**Note**: You may need to run the `make dfu-left` and `make dfu-right` commands
as root. In this case, use `sudo -E make dfu-{left,right}` so that you preserve
the `QMK_DIR` environment variable.

**Tip**: If you don't have an extra keyboard to send the `make dfu` command,
just prepend `sleep 10 &&` to it to give yourself 10 seconds to hit the flash
button.

That should be it! Your Planck keyboard should now be flashed with this layout.


## Modifying

Just modify `keymap.c` and repeat the steps above for flashing! Easy.


[ergodox_configurator]: https://input.club/configurator-ergodox
