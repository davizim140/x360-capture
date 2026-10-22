# X360 Capture — Stage 5 status

- [x] Portable recorder state machine
- [x] RGBA buffer-size validation
- [x] Validated RGBA frame contract
- [x] Abstract frame source/sink interfaces
- [x] Portable 640x480 RGBA resize utility
- [x] CI tests for core, frame contract, and 480p resize
- [x] Selected upstream SDK target: xenosworks/xsdk (MIT)
- [x] Documented SDK integration and capture feasibility gates
- [ ] GitHub Actions build using a pinned xSDK revision
- [ ] SDK-specific minimal XEX build (not produced)
- [ ] Launch minimal XEX on Xbox 360 RGH/Aurora (not tested)
- [ ] Prove whether cross-title gameplay framebuffer acquisition is possible
- [ ] Verified USB create/write/flush/close test on console
- [ ] Video encoder/container (not implemented)
- [ ] End-to-end gameplay recording (not implemented)

Portable tests passing does not prove SDK integration, gameplay capture, USB output, or console compatibility.
