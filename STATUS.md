# X360 Capture — Stage 4 status
- [x] Portable recorder state machine
- [x] RGBA buffer-size validation
- [x] Validated RGBA frame contract
- [x] Abstract source/sink interfaces
- [x] Portable 640x480 RGBA resize utility (nearest-neighbor)
- [x] CI tests for core, frame contract, and 480p resize
- [ ] Xbox 360 SDK/toolchain integration
- [ ] Real gameplay framebuffer acquisition (not implemented)
- [ ] Video encoder/container (not implemented)
- [ ] Real USB file output (not implemented)
- [ ] Build/test on Xbox 360 RGH/Aurora (not performed)
- [ ] Working `.xex` (not produced)

Test sinks are test doubles only. Passing portable tests do not prove gameplay capture, encoding, USB writing, or console compatibility.
