# Check that given variables are set and all have non-empty values,
# die with an error otherwise.
#
# Params:
#   1. Variable name(s) to test.
#   2. (optional) Error message to print.
check_defined = \
    $(strip $(foreach 1,$1, \
        $(call __check_defined,$1,$(strip $(value 2)))))
__check_defined = \
    $(if $(value $1),, \
      $(error Undefined $1$(if $2, ($2))))

$(call check_defined, QMK_DIR)

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

