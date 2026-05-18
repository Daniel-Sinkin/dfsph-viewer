# DFSPH Viewer

Standalone DFSPH playback viewer using `ds-vk` as a git submodule in `external/ds-vk`.

Simulation caches and HDRIs are intentionally local-only under `local/assets` so the repo can stay clean for GitHub. This migration copied the current local data there on this machine. A fresh clone should provide compatible data under:

- `local/assets/dfsph/...`
- `local/assets/hdri/polyhaven/qwantani_puresky_1k.hdr`

```sh
git submodule update --init --recursive
cmake -S . -B build
cmake --build build --target dfsph_viewer -j
./build/dfsph_viewer --smoke-frames 1 --hide-ui
```
