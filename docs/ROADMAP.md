# Cryostasis360 roadmap

## v0.1b — project foundation
- [x] Record project goals and honest implementation status.
- [x] Add a minimal C entry point and preliminary Makefile.
- [ ] Verify compiler, linker, libraries, and target runtime in a real build environment.
- [ ] Record a reproducible build log.

## v0.2b — platform startup
- Initialize the selected Xbox 360 homebrew runtime.
- Add diagnostic logging and safe shutdown.
- Acceptance: compile with the documented toolchain and run the diagnostic program on a supported target/emulator.

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

A milestone is complete only when its acceptance checks pass. Planned work is not counted as implemented functionality.
