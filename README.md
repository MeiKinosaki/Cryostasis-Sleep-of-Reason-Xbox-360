# Cryostasis: Sleep of Reason — Xbox 360

**Project codename:** Cryostasis360  
**Target:** Xbox 360 RGH / Xenon PowerPC  
**Current milestone:** v0.4b — CPU renderer prototype  
**Status:** early porting scaffold; no playable port or verified `default.xex` yet.

## Goal

Investigate a native port of the Windows PC game *Cryostasis: Sleep of Reason* to Xbox 360. This is a substantial engine-porting project, not a direct conversion of the Windows executable. The original engine, graphics API, physics, audio, asset formats, and memory/performance assumptions need to be evaluated and adapted independently.

## Current implementation

- C startup/diagnostic entry point and platform boundary.
- Bounded binary file reader with size-limit and error handling.
- CPU-side camera-space point projection and fixed diagnostic triangle geometry.
- Host-side unit tests and GitHub Actions source-validation workflow.

The projection module is **not** an Xbox 360 GPU backend. It does not render to screen, load Cryostasis assets, or establish target compatibility.

## Current implementation status

| Area | Status |
|---|---|
| Project scaffold and diagnostics | Implemented as host-testable C |
| Bounded resource file API | Implemented; host tests available |
| CPU projection math | Implemented; unit test passes locally |
| Xbox 360 graphics backend | Not implemented |
| Original game asset loading | Not implemented |
| Physics/audio integration | Not implemented |
| Xenon toolchain and target build | Not verified |
| ELF/XEX output | Not built or verified |
| Playable game | Not available |

## Sequential milestones

- `v0.1b`: project foundation and technical audit.
- `v0.2b`: platform startup diagnostics.
- `v0.3b`: bounded resource file layer.
- `v0.4b`: CPU renderer math prototype and tests.
- `v0.5b`: input abstraction and camera/controller diagnostics.
- Later: verified Xbox 360 graphics backend, asset conversion/loading, audio, physics, gameplay integration, profiling, and target tests.

Milestones advance sequentially; a milestone is complete only after its acceptance checks pass. Version numbers do not imply a percentage of the original game is ported.

## Build

The Makefile is a starting point for a compatible Free60/libXenon environment. A successful host-side test is **not** proof that an Xbox 360 executable was produced. The exact compiler, libraries, linker, and XEX packaging tools must be confirmed in build logs before reporting a target artifact.

## Legal and asset policy

This repository contains original porting scaffolding only. Do not commit proprietary game data, copied game assets, or the original Windows executable. Users must supply game files they are legally entitled to use.
