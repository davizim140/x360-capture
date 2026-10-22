# X360 Capture — Stage 7 status

- [x] Portable recorder state machine
- [x] RGBA buffer-size validation
- [x] Validated RGBA frame contract
- [x] Abstract frame source/sink interfaces
- [x] Portable 640x480 RGBA resize utility
- [x] CI tests for core, frame contract, and 480p resize
- [x] Selected upstream SDK target: xenosworks/xsdk (MIT)
- [x] Pinned xSDK revision and successful cloud XEX build
- [x] XEX artifact uploaded and verified by CI
- [x] Smoke XEX launched from Aurora on Xbox 360 RGH
- [x] Launch-folder test file created and expected marker verified by user
- [x] Added USB mount probe for Usb0: through Usb3: (new build; console test pending)
- [ ] Confirm USB probe marker exists on pendrive
- [ ] Prove whether cross-title gameplay framebuffer acquisition is possible
- [ ] Video encoder/container (not implemented)
- [ ] End-to-end gameplay recording (not implemented)

The current USB probe attempts create/write/flush/close/read-back at the standard Usb0: through Usb3: mount paths. A successful XEX build does not prove USB output, cross-title capture, or gameplay recording until the new build is tested on hardware.
