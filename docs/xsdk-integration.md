# xSDK integration plan (Stage 5)

## Selected SDK

This project targets **xenosworks/xsdk**, the open-source Xbox 360 homebrew SDK, not Microsoft's proprietary Xbox 360 XDK. Upstream: https://github.com/xenosworks/xsdk (MIT license; check upstream notices before redistributing a built title).

xSDK's upstream guide documents a powerpc-xsdk-elf toolchain, an XEX packer, file I/O, GPU initialization, presentation buffers and GPU resolves. Its documented build environment currently requires Windows 10/11 with WSL 2, around 10 GB free for WSL, and a toolchain build. This conflicts with this project's preferred browser-only/no-PC-install workflow, so we should first investigate a GitHub Actions build rather than claim a build already exists.

## Critical distinction: rendering is not gameplay capture

xSDK can initialize the GPU for a title and let that title render and resolve its own frames. That is not proof that a separate homebrew launched from Aurora can read the final framebuffer of a different running game. The documented presentation APIs describe buffers owned by the current title; they are not a general-purpose cross-title capture API.

Therefore, the project must not label its own menu or test pattern as gameplay capture. Before implementing a gameplay frame source, a hardware experiment or explicit upstream-supported API must establish that cross-title access is possible.

## Implementation sequence

1. **Build proof:** use upstream xSDK's template and toolchain in a GitHub Actions runner; record exact upstream commit, build logs and generated artifact hashes. Do not check in a purported XEX unless the build really produces it.
2. **Console smoke test:** launch the minimal unsigned XEX from Aurora on the RGH console; record the SDK commit, console/dashboard details, log and pass/fail outcome. CI alone cannot prove hardware compatibility.
3. **Frame acquisition probe:** investigate documented GPU/resolve APIs and test whether a title can access only its own render target. Do not read arbitrary memory or assume another title's backbuffer is exposed.
4. **USB write probe:** independently test creating, writing, flushing and closing a file on a USB mass-storage device using APIs supported by this xSDK revision. Verify the resulting bytes on a PC.
5. **Only after both probes pass:** connect the real source to the existing RGBA frame contract and 640x480 scaler. Video encoding/container support is a separate stage.

## Current result

This document records the selected SDK and a testable plan. No xSDK submodule, SDK-specific source adapter, console build, USB recording, video encoder, or working XEX is claimed by this commit.
