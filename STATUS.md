# X360 Capture — Stage 6 status

- [x] Portable recorder state machine
- [x] RGBA buffer-size validation
- [x] Validated RGBA frame contract
- [x] Abstract frame source/sink interfaces
- [x] Portable 640x480 RGBA resize utility
- [x] CI tests for core, frame contract, and 480p resize
- [x] Selected upstream SDK target: xenosworks/xsdk (MIT)
- [x] Pinned xSDK upstream revision for build probe
- [x] Minimal xSDK smoke title source and CMake target
- [x] Cloud workflow configured to build and upload an XEX artifact
- [ ] First xSDK build workflow run succeeds (in progress at commit time)
- [ ] Inspect generated XEX and SHA-256 artifact
- [ ] Launch smoke XEX from Aurora on Xbox 360 RGH (not tested)
- [ ] Verify launch-folder file round-trip on hardware
- [ ] Verify USB device discovery and file output (not implemented)
- [ ] Prove whether cross-title gameplay framebuffer acquisition is possible
- [ ] Video encoder/container (not implemented)
- [ ] End-to-end gameplay recording (not implemented)

The smoke title tests file I/O in the launch folder only. Portable tests and a successful XEX build do not prove USB output, cross-title capture, or console compatibility.
