project(
    'minesweeper',
    'cpp',
    default_options: [
        'cpp_std=c++17',
        'warning_level=3',
    ],
)

fmt_proj = subproject('fmt')
fmt_dep = fmt_proj.get_variable('fmt_dep')

catch2_proj = subproject('catch2')
catch2_dep = catch2_proj.get_variable('catch2_dep')

clara_proj = subproject('catchorg-clara')
clara_dep = clara_proj.get_variable('catchorg_clara_dep')

minesweeper_lib = library(
    'minesweeper library',
    sources: [
        'minesweeper'/'minesweeper.cpp',
        'minesweeper'/'grid.cpp',
        'minesweeper'/'space.cpp',
    ],
)

minesweeper_exe = executable(
    'minesweeper',
    sources: 'minesweeper'/'main.cpp',
    link_with: minesweeper_lib,
    dependencies: [fmt_dep, clara_dep],
)

minesweeper_test = executable(
    'test_minesweeper',
    sources: [
        'test'/'test_main.cpp',
        'test'/'test_minesweeper.cpp',
        'test'/'test_grid.cpp',
        'test'/'test_space.cpp',
    ],
    link_with: minesweeper_lib,
    dependencies: catch2_dep,
)

test(
    'tests for minesweeper library',
    minesweeper_test,
)
