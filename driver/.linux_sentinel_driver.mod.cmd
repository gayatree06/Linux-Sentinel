savedcmd_linux_sentinel_driver.mod := printf '%s\n'   linux_sentinel_driver.o | awk '!x[$$0]++ { print("./"$$0) }' > linux_sentinel_driver.mod
