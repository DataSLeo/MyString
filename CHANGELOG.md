# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [1.1.2] - 2025-10-13
### Changed
- Renamed enum constant `MYSTRING_PHRASE_CANNOT_BE_REALLOC` → `MYSTRING_PHRASE_CANNOT_BE_RELOCATED`.
- Renamed enum constant `MYSTRING_STRING_ALREADY_FREE` → `MYSTRING_PHRASE_ALREADY_RELEASED`.
- Renamed enum constant `MYSTRING_PHRASE_NOT_INITIALIZATED` → `MYSTRING_PHRASE_NOT_INITIALIZED`.
- Updated the `init_string` function to properly add a null terminator at the end of the allocated string.
- Refactored the following test files to remove the `main` function and adopt the standard `criterion/criterion.h` boilerplate:
    - `testInitializeAString.c`
    - `testFreeAString.c`
    - `testAssignString.c`
    - `testCounterString.c` 
    - `testEqualString.c`
    - `testInitializeStringWithPhrase.c`
- Updated `README.md` with a function `remasp_string`.

### Fixed
- Fixed the `assign_string` function: previously returned `MYSTRING_PHRASE_NOT_INITIALIZATED`, now correctly returns `MYSTRING_PHRASE_CANNOT_BE_REALLOC`.

## [1.1.1] - 2025-10-11
### Fixed
- Minor corrections and improvements in `README.md` documentation.

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
