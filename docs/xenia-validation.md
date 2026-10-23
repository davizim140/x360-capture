# Xenia validation plan for X360 Capture

## Safety boundary

The user's requirement is zero risk of a permanent brick. Therefore, do not launch this probe on the physical Xbox 360 while that requirement remains. No emulator result can prove zero risk on real hardware.

## What Xenia can and cannot validate

Xenia may help detect whether a built XEX starts and whether basic title code behaves as expected. Results depend on Xenia version, host GPU/backend, and support for the xSDK title. A failed launch may be an emulator compatibility issue; a successful launch is not proof that Xbox 360 hardware behavior is safe.

Xenia is not a reliable substitute for verifying real GPU framebuffer/readback behavior. This probe renders and reads back only its own title's frame; it does not capture another game's framebuffer or record gameplay.

## Safe validation sequence

1. Run the repository's portable C++ tests in GitHub Actions.
2. Build the GPU probe XEX in the pinned xSDK workflow and retain the build log, artifact name, and SHA-256.
3. In a separate Windows CI job, obtain a pinned Xenia Canary release and attempt to launch the XEX only if the runner supports the required graphics backend. Capture stdout/stderr and exit status; do not interpret a launch failure as a hardware defect.
4. Keep emulator testing non-blocking until repeatable, documented results exist.
5. Never write to NAND, flash, kernel memory, or undocumented physical addresses as part of testing.

## Current status

- xSDK smoke XEX build: previously passed in GitHub Actions.
- Portable core tests: previously passed in GitHub Actions.
- Xenia execution: not yet run; no result is claimed here.
- Physical console GPU test: intentionally deferred because it cannot meet a strict zero-risk requirement.
- Gameplay capture/encoding: not implemented.
