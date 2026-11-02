# DS — File Search Tool

**DS** is a command-line file search tool written in C. It is being developed to make searching for text in files simple, practical, and convenient from the Linux terminal.

The goal is to build a lightweight command-line utility that brings different search operations together under one consistent interface.

> 🚧 **Status: Under Development**
>
> DS is an ongoing project. Features and command-line options may change as development progresses.

## ✨ Current Features

- Search for text inside a file.
- Display the line number where a match is found.
- Count matching occurrences on each matching line.
- Support whole-word matching with the `-w` option.
- Report when the search term is not found.
- Handle file-opening errors.

## 🚀 Usage

### 1. Basic Search

Search for a text fragment inside a file:

```bash
./ds notes.txt hello
```

### 2. Whole-Word Search

Use `-w` to match a complete word rather than a substring:

```bash
./ds -w notes.txt hello
```

For example, a whole-word search for `hello` should match `hello!`, but not `helloworld` or `hello123`.

## 🛠️ Built With

- **C** — Core programming language
- **GCC** — Compiler
- **Linux** — Development environment
- **Git** — Version control

## 🗺️ Roadmap

The project is being developed incrementally, with an emphasis on improving its structure before expanding its functionality.

- [x] Basic text search
- [x] Line number reporting
- [x] Match counting per line
- [x] Whole-word search (`-w`)
- [ ] Refactor repeated code into reusable functions
- [ ] Add space-bounded matching (`-s`)
- [ ] Expand file and directory name search
- [ ] Add full-search functionality
- [ ] Improve command-line argument validation and error handling
- [ ] Add `--help` and `--version`
- [ ] Write documentation and usage examples
- [ ] Add a Makefile and installation instructions
- [ ] Explore Bash tab completion and Linux package distribution

*The roadmap may change as the project evolves.*

## 🎯 Project Goals

DS aims to become a practical, lightweight, and easy-to-use command-line search utility.

The long-term goals include:

- A consistent interface for different search modes.
- Clear and predictable search behavior.
- Modular, maintainable C code.
- Useful documentation and installation support.
- A convenient experience for everyday terminal use.

## 📚 Development

DS is currently in active development. The implementation and documentation will evolve as new features are added and existing code is improved.

Contributions, suggestions, and constructive feedback are welcome.

## 📄 License

A license has not been selected yet.
