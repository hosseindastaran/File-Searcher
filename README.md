# DS — File Search Tool

**DS** is a command-line file search tool written in C. It is being developed to make searching for text in files simple, practical, and convenient from the terminal.

The goal is to build a lightweight command-line utility that brings different search operations together under one consistent interface.

> 🚧 **Status: Under Development**
>
> DS is an ongoing project. Features and command-line options may change as development progresses.

## ✨ Current Features

- Search for text inside a file.
- Display the line number where a match is found.
- Count matching occurrences on each matching line.
- Support substring matching by default.
- Support whole-word matching with the `-w` option.
- Support space-bounded matching with the `-s` option.
- Display the byte offset of each match within the file.
- Report when the search term is not found.
- Handle file-opening errors and invalid command-line options.
- Handle empty search terms.
- Dynamically allocate memory to store match offsets.

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

For example, a whole-word search for `hello` matches `hello!`, but not `helloworld` or `hello123`.

### 3. Space-Bounded Search

Use `-s` to match a search term bounded by spaces or the beginning or end of a line:

```bash
./ds -s notes.txt hello
```

Unlike whole-word matching, punctuation alone does not count as a valid boundary. For example, `hello!` does not match when searching for `hello` with `-s`.

### 4. Byte Offset Reporting

DS displays the byte offset of each match relative to the beginning of the file. Offsets are zero-based.

Example output:

```text
Line 1:2 matches | hello hello
  Match 1: Byte Offset 0
  Match 2: Byte Offset 6
```

Byte offsets indicate positions within the file's contents, not physical addresses on a storage device.

## 🛠️ Built With

- **C** — Core programming language
- **GCC** — Compiler
- **Linux** — Development environment
- **Git** — Version control
- **GitHub** — Source code hosting

## 🗺️ Roadmap

The project is being developed incrementally, with an emphasis on understanding the implementation, improving code structure, and expanding functionality.

- [x] Basic text search
- [x] Line number reporting
- [x] Match counting per line
- [x] Whole-word search (`-w`)
- [x] Space-bounded search (`-s`)
- [x] Byte offset reporting
- [x] Basic command-line argument validation
- [ ] Improve handling of long lines
- [ ] Refactor and improve code structure
- [ ] Expand file and directory name search
- [ ] Add recursive directory search
- [ ] Add full-search functionality
- [ ] Add `--help` and `--version`
- [ ] Improve error handling and edge-case coverage
- [ ] Add comprehensive tests
- [ ] Add a Makefile and installation instructions
- [ ] Explore Bash tab completion and Linux package distribution

*The roadmap may change as the project evolves.*

## 🎯 Project Goals

DS aims to become a practical, lightweight, and easy-to-use command-line search utility.

Long-term goals include:

- A consistent interface for different search modes.
- Clear and predictable search behavior.
- Modular and maintainable C code.
- Efficient memory management.
- Reliable error handling.
- Useful documentation and installation support.
- A convenient experience for everyday terminal use.

## 📚 Development

DS is actively being developed. The code and documentation will evolve as new features are added and existing implementations are reviewed and improved.

Contributions, suggestions, and constructive feedback are welcome.

## 📄 License

A license has not been selected yet.