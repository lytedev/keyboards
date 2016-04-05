# Infinity Ergodox
This contains my kiibohd controller compatible Infinity Ergodox keymap.

Everything in the `src` folder in this directory is unzipped output from [the ergodox configurator][ergodox_configurator].

## Flashing

* Disconnect your ergodox from your flashing PC
* Connect ONE side of the ergodox, noting which side and press it's flash button (orange LED should be on, LCD should be red)
* Open a terminal in the `src` directory and run `dfu-util -D <left|right>_kiibohd.dfu.bin` (depending on which half of the keyboard you plugged in
* Repeat last three steps for other side

## Modifying

* Go to [the ergodox configurator][ergodox_configurator]
* Click "import map"
* Paste the keymap JSON (`src/MDErgo1-Default.json`) into the textarea and import
* Modify as needed
* Click "download firmware" and unzip here, commit, push

## To Do

* Programmatic configurator?
* Learn KLL?

[ergodox_configurator]: https://input.club/configurator-ergodox
