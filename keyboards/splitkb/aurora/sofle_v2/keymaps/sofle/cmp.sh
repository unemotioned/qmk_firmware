#!/usr/bin/env bash
set -euo pipefail

qmk="$HOME/qmk_firmware"
firmware="$qmk/splitkb_aurora_sofle_v2_rev1_sofle.uf2"

keyboard='splitkb/aurora/sofle_v2/rev1'
keymap='sofle'

rm -f "$firmware"

for _ in 1 2; do
    # compile and flash automatically when keyboard is in bootloader mode
    qmk flash -kb "$keyboard" -km "$keymap"
done
