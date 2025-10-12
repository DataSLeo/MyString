# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [1.1.0] - 2025-10-11
### Added
- New function `remasp_string` to remove all spaces from a string.
- Unit test `test/bop/testRemoveAllSpacesString` to validate the `remasp_string` function.
- Example `example/example06_removing_spaces` demonstrating the `remasp_string` function.

## [1.0.0] - 2025-10-11
### Added
- Main struct `MyString`.
- Enum `ErrorMyString` for error handling.
- Basic functions:
  - `init_string()` and `del_string()` (initialization and memory release)
  - `initwp_string()` (initialize with a phrase)
  - `concat_string()` (concatenate two strings)
  - `assign_string()` (assign a new phrase)
  - `equals_string()` (compare two strings)
  - `counter_string()` (manually calculate the length)
- Directories and modular organization (`build`, `example`, `include`, `src`, `test`).
- Unit tests for all functions (using Criterion).
- Doxygen configuration (Doxyfile) for generating documentation.

---

**First note:**  
This is the first registered version of this project **MyString**, representing the official start of versioning. Previous versions were not documented.
