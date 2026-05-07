# Troublehooting

## Missing Submodule

### Error Message

```sh
platforms/chibios/platform.mk:102: lib/chibios-contrib/os/common/startup/ARMCMx/compilers/GCC/mk/startup_rp2040.mk: No such file or directory
make: *** No rule to make target 'lib/chibios-contrib/os/common/startup/ARMCMx/compilers/GCC/mk/startup_rp2040.mk'.  Stop.
```

### Symptom

QMK depends on external libraries (ChibiOS, etc.) as git submodules. Cloning the
repo with `git clone` (without `--recurse-submodules`) leaves these directories
empty, causing the build to fail when it can't find expected files.

### Fix

Get the submodule

```sh
git -C "$HOME"/qmk_firmware submodule update --init --recursive
```

---

## Sync with Upstream

Syncing my current repo with original repo I forked from.

```sh
git fetch upstream
git merge upstream/master
```

Update submodules.

```sh
git submodule sync --init --recursive
git submodule update --init --recursive
```
