# Ergodox Infinity
==================

This contains my `qmk_firmware`-compatible Infinity Ergodox keymap.

## Dependencies
===============

* Docker
* `arm-none-eabi-gcc` and `arm-none-eabi-newlib`
* See the `qmk_firmware` repo for details.

## Flashing
===========

Run `make flash-left` to build the firmware and flash the left hand.
`s/left/right` for the right hand.

**Note**: You may need to run the commands as root.

**Tip**: If you don't have an extra keyboard to send the command, just prepend
`sleep 10 &&` to it to give yourself 10 seconds to hit the flash button.

That should be it! Your Ergodox Infinity keyboard should now be flashed with
this layout.

## Modifying
============

Just modify `keymap.c` and repeat the steps above for flashing! Easy.
