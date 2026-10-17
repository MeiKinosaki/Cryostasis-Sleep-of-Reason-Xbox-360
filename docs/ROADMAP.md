# Cryostasis360 roadmap

## v0.1b — project foundation
- [x] Project goals and honest implementation status.
- [x] Minimal C entry point and preliminary Makefile.
- [x] Source-validation workflow added.

## v0.2b — startup diagnostics
- [x] Add a platform boundary in C.
- [x] Add a diagnostic-only startup/shutdown path.
- [ ] Run and inspect the GitHub Actions result.
- [ ] Verify the actual Free60/libXenon compiler and target runtime.
- [ ] Record a reproducible Xbox 360 build log.

## v0.3b — file and resource layer
- Add bounded file reads and resource path abstraction.
- Add tests for missing, empty, and malformed files.
- Do not include proprietary game data in this repository.

## v0.4b — renderer prototype
- Confirm available graphics APIs and runtime libraries first.
- Draw a simple test scene before attempting original game assets.

## Later milestones
- Controller input and camera test.
- Resource conversion and asset loading.
- Renderer features, audio, physics, gameplay integration.
- Performance profiling and target testing.

A milestone is complete only when its acceptance checks pass. Host compilation is not an Xbox 360 build, and planned work is not counted as implemented functionality.
