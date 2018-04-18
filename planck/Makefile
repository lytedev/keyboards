QMK_REPO_DIR ?= ${HOME}/.local/share/qmk_firmware
KB_DIR ?= ${QMK_REPO_DIR}/keyboards/planck/keymaps/lytedev

default: build-and-flash

${QMK_REPO_DIR}:
	@git clone https://github.com/lytedev/qmk_firmware.git "${QMK_REPO_DIR}"
	@cd "${QMK_REPO_DIR}" && make git-submodule

repo_keymap_files:
	@rm -rf "${KB_DIR}"
	@mkdir -p "${KB_DIR}"
	@cp keymap.c "${KB_DIR}/"
	@cp keymap.mk "${KB_DIR}/Makefile"

build-and-flash: ${QMK_REPO_DIR} repo_keymap_files
	@cd "${QMK_REPO_DIR}" && sudo make planck:lytedev:dfu

build: ${QMK_REPO_DIR} repo_keymap_files
	@docker run -e keymap=lytedev -e keyboard=planck --rm -v "${QMK_REPO_DIR}":/qmk:rw edasque/qmk_firmware
