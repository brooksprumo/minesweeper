project(
    'minesweeper',
    'cpp',
    default_options: [
        'cpp_std=c++17',
    ],
)

catch2_dep = declare_dependency(
    include_directories: 'external'/'catch2',
)

clara_dep = declare_dependency(
    include_directories: 'external'/'clara',
)

minesweeper_lib = library(
    'minesweeper library',
    sources: [
      'minesweeper'/'grid.cpp',
      'minesweeper'/'space.cpp',
    ],
)

minesweeper_exe = executable(
    'minesweeper',
    sources: 'minesweeper'/'main.cpp',
    link_with: minesweeper_lib,
    dependencies: clara_dep,
)

minesweeper_tests = executable(
    'test_minesweeper',
    sources: ['test'/'test_main.cpp', 'test'/'test_grid.cpp'],
    link_with: minesweeper_lib,
    dependencies: catch2_dep,
)

test(
    'tests for minesweeper library',
    minesweeper_tests,
)
