# Framebuffer feasibility investigation

Date: 2026-10-22

## Finding

The current xSDK revision pinned by this project is `57b02f1e60667e37d22c3aa613d23d2486514ff8`.

Its public GPU API exposes:
- `xsdk_gpu_set_target()` and `xsdk_gpu_resolve()` for a render target owned by the current homebrew title;
- `xsdk_present_begin()`, `xsdk_present_pixels()` and `xsdk_present_buffer_address()` for the current title's own presentation buffers;
- `xsdk_texture_download_rows()` for textures created and managed through the SDK.

These APIs establish a way to read back a frame rendered by this XEX. They do **not** document an API for reading the final framebuffer of a different game running under Aurora's retail kernel.

The xSDK guide also notes that XAM may draw its Guide surface between a title's frames, and that this can replace the visible surface while the Guide is open. That is not a general-purpose gameplay capture interface.

References:
- xSDK GPU API at the pinned revision: https://github.com/xenosworks/xsdk/blob/57b02f1e60667e37d22c3aa613d23d2486514ff8/include/xsdk/gpu.h
- xSDK presentation API: https://github.com/xenosworks/xsdk/blob/57b02f1e60667e37d22c3aa613d23d2486514ff8/include/xsdk/present.h
- xSDK task guide: https://github.com/xenosworks/xsdk/blob/57b02f1e60667e37d22c3aa613d23d2486514ff8/docs/GUIDE.md

## Safety boundary

Do not probe undocumented GPU registers, halt the command processor, patch kernel/D3D state, or read guessed physical addresses on the user's console. The upstream hardware notes describe GPU-register experiments that hung the GPU and required a cold boot. The current USB file test does not need any such access.

## Next experiment

Build a separate, explicitly labelled **own-title GPU readback probe**:
1. Initialise the GPU using documented xSDK calls.
2. Render a known colour pattern into a render target owned by the probe XEX.
3. Resolve/download the probe's own pixels and compare them with expected values.
4. Write a small PASS/FAIL report to the launch folder and USB, then exit cleanly.

This experiment validates only the SDK's render-target readback path. It does not claim access to another game's framebuffer. Only after it passes on the real RGH console should we decide whether there is a documented, safe route to a gameplay frame source.

## Current project status

- Portable frame contract and 640x480 resize tests: implemented.
- USB file write/read-back on the user's console: confirmed by user.
- xSDK XEX build: CI succeeded.
- Own-title GPU readback: not yet implemented or tested on hardware.
- Cross-title gameplay framebuffer access: unproven.
- Video encoding and playable recording file: not implemented.
