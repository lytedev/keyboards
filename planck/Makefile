ifndef QMK_DIR
	$(error QMK_DIR is not defined)
endif

MY_KEYMAP_DIR = "${QMK_DIR}/keyboards/planck/keymaps/lytedev"

all:
	@rm -rf "${MY_KEYMAP_DIR}"
	@mkdir -p "${MY_KEYMAP_DIR}"
	@cp keymap.mk "${MY_KEYMAP_DIR}/Makefile"
	@cp keymap.c "${MY_KEYMAP_DIR}/keymap.c"
	@make -C "${MY_KEYMAP_DIR}"

dfu:
	@make -C "${MY_KEYMAP_DIR}" dfu

