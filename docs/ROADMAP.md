# Cryostasis360 roadmap

## v0.1b — project foundation
- [x] Project goals and honest implementation status.
- [x] Minimal C entry point and preliminary Makefile.
- [x] Source-validation workflow added.

## v0.2b — startup diagnostics
- [x] Add a platform boundary in C.
- [x] Add a diagnostic-only startup/shutdown path.
- [ ] Inspect the GitHub Actions result.
- [ ] Verify the actual Free60/libXenon compiler and target runtime.
- [ ] Record a reproducible Xbox 360 build log.

## v0.3b — bounded resource file layer
- [x] Add a bounded binary file-read API.
- [x] Handle missing files, empty files, invalid arguments, and maximum-size rejection.
- [x] Add host-side tests for the resource API.
- [x] Extend the validation workflow to compile and run those tests.
- [ ] Confirm the GitHub Actions run passes.
- [ ] Verify file API compatibility and behavior in the actual Xbox 360 runtime.

## v0.4b — CPU renderer prototype
- [x] Add camera-space point projection with a configurable focal length and near plane.
- [x] Add a fixed diagnostic triangle in camera-space.
- [x] Add tests for center projection, offset projection, near-plane rejection, invalid parameters, and null output.
- [x] Add renderer unit tests to the host validation workflow.
- [ ] Implement and validate a real Xbox 360 graphics API backend.
- [ ] Render the diagnostic triangle on the target or supported emulator.

The v0.4b code is CPU-side projection math only. It is not a GPU renderer, does not load Cryostasis assets, and does not prove Xenon compilation.

## Later milestones
- Controller input and camera test.
- Resource conversion and asset loading.
- Renderer features, audio, physics, gameplay integration.
- Performance profiling and target testing.

A milestone is complete only when its acceptance checks pass. Host compilation is not an Xbox 360 build, and planned work is not counted as implemented functionality.
