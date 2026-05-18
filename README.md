<!-- README.md -->
# DFSPH Viewer

Standalone DFSPH playback viewer using `ds-vk`, fetched by CMake from `git@github.com:Daniel-Sinkin/ds-vk.git` and pinned to commit `c8fd46f192aefbdd06572e93f9228e9b5f40c374`.

Simulation caches and HDRIs are intentionally local-only under `local/assets` so the repo can stay clean for GitHub. This migration copied the current local data there on this machine. A fresh clone should provide compatible data under:

- `local/assets/dfsph/...`
- `local/assets/hdri/polyhaven/qwantani_puresky_1k.hdr`

```sh
cmake -S . -B build
cmake --build build --target dfsph_viewer -j
./build/dfsph_viewer --smoke-frames 1 --hide-ui
```
