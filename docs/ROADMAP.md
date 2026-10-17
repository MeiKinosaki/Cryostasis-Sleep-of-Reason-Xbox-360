# Cryostasis360 roadmap

## v0.1b — project foundation
- [x] Establish project goals, source layout, and validation workflow.

## v0.2b — startup diagnostics
- [x] Platform boundary and diagnostic startup/shutdown path.
- [ ] Verify Free60/libXenon compiler and target runtime.
- [ ] Record a reproducible Xbox 360 build log.

## v0.3b — bounded resource layer
- [x] Binary file reads with size limit and explicit error statuses.
- [x] Tests for normal, empty, missing, oversized, and invalid-argument cases.

## v0.4b — CPU renderer prototype
- [x] Perspective projection math, near-plane rejection, diagnostic triangle.
- [x] Unit tests for valid and invalid inputs.
- [ ] Implement an actual Xbox 360 graphics API backend.
- [ ] Render on target or supported emulator.

## v0.5b — input and camera core
- [x] Normalized input axes with non-finite values rejected to neutral.
- [x] Camera forward/strafe movement and yaw/pitch updates.
- [x] Delta-time and speed validation; pitch limit to avoid singular vertical view.
- [x] Host-side tests for input normalization and camera updates.
- [ ] Bind normalized input to a verified Xbox 360 controller API.
- [ ] Integrate camera matrices with the GPU renderer.

## Next milestones
- v0.6b: confirm target runtime and controller backend; diagnostic input display.
- v0.7b: connect camera transforms to a real graphics backend.
- v0.8b: resource manifest and metadata inspection for user-supplied game files.
- Later: graphics features, asset conversion/loading, audio, physics, gameplay integration, profiling and target testing.

A milestone is complete only when its acceptance checks pass. Host compilation is not an Xbox 360 build. The CPU projection and camera state are not a GPU renderer or playable game.
