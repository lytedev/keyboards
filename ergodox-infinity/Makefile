QMK_REPO_DIR ?= ${HOME}/.local/share/qmk_firmware
KB_DIR ?= ${QMK_REPO_DIR}/keyboards/ergodox_infinity/keymaps/lytedev

default: flash-left-then-right

${QMK_REPO_DIR}:
	@git clone https://github.com/lytedev/qmk_firmware.git "${QMK_REPO_DIR}"
	@cd "${QMK_REPO_DIR}" && make git-submodule

repo_keymap_files:
	@rm -rf "${KB_DIR}"
	@mkdir -p "${KB_DIR}"
	@cp keymap.c "${KB_DIR}/"

flash-left: ${QMK_REPO_DIR} repo_keymap_files
	@cd "${QMK_REPO_DIR}" && sudo make ergodox_infinity:lytedev:dfu-util

flash-right: ${QMK_REPO_DIR} repo_keymap_files
	@cd "${QMK_REPO_DIR}" && sudo make ergodox_infinity:lytedev:dfu-util MASTER=right

build-and-flash-left: ${QMK_REPO_DIR} repo_keymap_files
	@cd "${QMK_REPO_DIR}" && sudo make ergodox_infinity:lytedev

build-and-flash-right: ${QMK_REPO_DIR} repo_keymap_files
	@cd "${QMK_REPO_DIR}" && sudo make ergodox_infinity:lytedev MASTER=right

flash-left-then-right: flash-left flash-right

build-left: ${QMK_REPO_DIR} repo_keymap_files
	@docker run -e keymap=lytedev -e keyboard=ergodox_infinity --rm -v "${QMK_REPO_DIR}":/qmk:rw edasque/qmk_firmware

build-right: ${QMK_REPO_DIR} repo_keymap_files
	@docker run -e keymap=lytedev -e MASTER=right -e keyboard=ergodox_infinity --rm -v "${QMK_REPO_DIR}":/qmk:rw edasque/qmk_firmware
