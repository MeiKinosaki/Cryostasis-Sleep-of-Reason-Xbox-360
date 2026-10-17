# Cryostasis: Sleep of Reason — Xbox 360

**Project codename:** Cryostasis360  
**Target:** Xbox 360 RGH / Xenon PowerPC  
**Current milestone:** v0.5b — input and camera core  
**Status:** early porting scaffold; no playable port or verified `default.xex` yet.

## Implemented scaffold

- Startup diagnostics and a platform abstraction boundary.
- Bounded binary resource-file reader with explicit error handling.
- CPU-side perspective projection and diagnostic triangle data.
- Normalized input-axis processing.
- Camera forward/strafe movement and yaw/pitch updates.
- Host-side unit tests and GitHub Actions source-validation workflow.

## Important limitations

The input API currently accepts normalized values; it does not yet poll a physical Xbox 360 controller. Camera state is CPU-side only and is not connected to a GPU backend. The project does not yet load Cryostasis assets, implement the original engine, or produce a verified Xbox 360 ELF/XEX.

## Milestones

- `v0.1b`: project foundation.
- `v0.2b`: startup diagnostics.
- `v0.3b`: bounded resource layer.
- `v0.4b`: CPU projection prototype.
- `v0.5b`: normalized input and camera core.
- Next: target controller integration, graphics backend, resource inspection, then audio/physics/gameplay systems.

Milestones advance one at a time. A version number is not a percentage of the original game ported.

## Build and validation

The Makefile is intended for a compatible Free60/libXenon environment. GitHub Actions performs host-side source checks and tests; that is not proof of Xenon compilation or console execution. Only report a target artifact after verifying the actual compiler, linker, packaging tools, logs, and runtime test.

## Asset policy

Only original porting scaffolding belongs in this repository. Do not commit proprietary game data or the original Windows executable. Use only game files you are legally entitled to access.
