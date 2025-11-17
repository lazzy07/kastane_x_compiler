# Kastane X Compiler

This project is a compiler for Kastane-X planner problem files. You can compile `.sabre` files written in `Sabre` logic language with this compiler.

## Grammar Generator

This project uses `antlr4` compiler generator to write the Grammar required. You can go check out more about [ANTLR]("https://www.antlr.org/") for more information. Specifically this project is using `Antlr v4 (antlr4)` compiler generator.

## Project Structure

This project is designed to be highly portable, if you don't need `Data Structures` created, you can turn it off.

## Testing

To test this project, you need to have `Sabre Benchmark Problem Files`, you can get them from the original [Sabre-Benchmarks Repository](https://github.com/sgware/sabre-benchmarks/tree/main/problems)

## Network Connection

This project will download some vendor libraries from `Github`, so to build this project, active internet connection is required!.

## Other Requirements

This project requires `Java JDK`, `Git`, `CMake` and a `C++ compiler` to be installed in order to build from the source.

## Set the compiler version

Compiler version is set by `git tags`, so make sure that you use proper git tags for correct versioning.

```bash
git init
git add .
git commit -m "Initial commit"
git tag -a v1.0.0 -m "Version 1.0.0"
```


## Compiling and running the project

This project uses CMake. To build the project,

```bash
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build build -j
```
```
```
```

