# unitask

An interesting task

## Build requirements

- CMake >= 3.24
- C++17 compatible compiler

## Compilation

Clone the repo

```bash
git clone https://github.com/ivan-volnov/unitask.git
```

Build

```bash
mkdir build; cd build/
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j4
```

To build tests add this to cmake call

```bash
-DUNI_TEST=ON
```

## Run

Run the app

```bash
./unitask
```

Run unit tests

```bash
./test/test_unitask
```
