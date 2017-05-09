ifndef QMK_DIR
	$(error QMK_DIR is not defined)
endif

KEYMAP_NAME = "lytedev"
ERGODOX_DIR = "${QMK_DIR}/keyboards/ergodox"
MY_KEYMAP_DIR = "${ERGODOX_DIR}/keymaps/${KEYMAP_NAME}"
MAKE_DIR = "${ERGODOX_DIR}"

left: prep
	@make -C "${MAKE_DIR}" infinity-"${KEYMAP_NAME}"

right: prep
	@make -C "${MAKE_DIR}" infinity-"${KEYMAP_NAME}" MASTER=right

dfu-left:
	@make -C "${MAKE_DIR}" infinity-"${KEYMAP_NAME}"-dfu-util

dfu-right:
	@make -C "${MAKE_DIR}" infinity-"${KEYMAP_NAME}"-dfu-util MASTER=right

prep:
	@rm -rf "${MY_KEYMAP_DIR}"
	@mkdir -p "${MY_KEYMAP_DIR}"
	@cp keymap.c "${MY_KEYMAP_DIR}/keymap.c"

