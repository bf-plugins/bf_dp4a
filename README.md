## add_stuff

A simple example plugin for bifrost

Author: Danny Price

### Compiling your plugin

To build your plugin:

0) Setup your build environment (on topaz, run `source setup_env.sh`).
1) Add your source code to `src/`. Names must be `add_stuff.h` and `add_stuff.cu`.
2) compile with meson by running:

```
meson setup build
cd build
meson compile
```

### Using your plugin

```python
from build import add_stuff_generated as _bf
_bf.init()
_bf.execute(data_in.as_BFarray(), data_out.as_BFarray())
```