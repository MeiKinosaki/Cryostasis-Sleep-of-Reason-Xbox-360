# Cryostasis: Sleep of Reason — Xbox 360

**Project codename:** Cryostasis360  
**Target:** Xbox 360 RGH / Xenon PowerPC  
**Current milestone:** v0.1b — project foundation  
**Status:** early research and scaffold; no playable port or verified `default.xex` yet.

## Goal

Investigate a native port of the Windows PC game *Cryostasis: Sleep of Reason* to Xbox 360. This is a substantial engine-porting project, not a direct conversion of the Windows executable. The original engine, graphics API, physics, audio, asset formats, and memory/performance assumptions need to be evaluated and adapted independently.

## v0.1b scope

- Establish repository structure and milestone tracking.
- Define a Xenon/libXenon build entry point without claiming the toolchain is installed or the target has compiled.
- Keep platform-specific code isolated from future renderer, input, audio, physics, and asset-loading modules.
- Require build logs and target/emulator tests before marking artifacts as verified.

## Current implementation status

| Area | Status |
|---|---|
| Project documentation and layout | In progress |
| Xenon toolchain availability | Not verified |
| Xbox 360 renderer | Not implemented |
| Game asset loading | Not implemented |
| Physics/audio integration | Not implemented |
| ELF/XEX output | Not built or verified |
| Playable game | Not available |

## Planned milestones

- `v0.1b`: project skeleton, build prerequisites, technical audit.
- `v0.2b`: platform startup and minimal diagnostic output.
- `v0.3b`: file-system abstraction and resource discovery.
- `v0.4b`: first renderer prototype.
- `v0.5b`: controller input and basic player/camera test.
- Later milestones: asset conversion, renderer features, audio, physics, gameplay systems, integration, and performance work.

Milestones advance one at a time; a milestone is complete only after its acceptance checks pass. Version numbers do not imply a percentage of the original game is ported.

## Build

The Makefile is a starting point for a compatible Free60/libXenon environment. A successful host-side workflow check is **not** proof that an Xbox 360 executable was produced. The exact compiler, libraries, linker, and XEX packaging tools must be confirmed in build logs before reporting a target artifact.

## Legal and asset policy

This repository contains original porting scaffolding only. Do not commit proprietary game data, copied game assets, or the original Windows executable. Users must supply game files they are legally entitled to use.
