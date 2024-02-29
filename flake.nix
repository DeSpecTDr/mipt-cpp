{
  inputs.nixpkgs.url = "nixpkgs/nixpkgs-unstable";

  outputs = inputs @ {flake-parts, ...}:
    flake-parts.lib.mkFlake {inherit inputs;} {
      systems = ["x86_64-linux"];
      perSystem = {pkgs, ...}: {
        devShells.default = with pkgs;
          mkShell.override {
            # use profile guided gcc with mold linker
            stdenv = stdenvAdapters.useMoldLinker fastStdenv;
          } {
            nativeBuildInputs = let
              # llvm = llvmPackages_latest;
              mymake = pkgs.writeShellScriptBin "mk" ''
                if [ -f "$1.c" ]; then
                  i="$1.c"
                  c=$CC
                else
                  i="$1.cpp"
                  c=$CXX
                fi
                o="build/$1"
                shift
                $c -ggdb $i -o $o -lm -Wall -Wextra -Wpedantic -std=c++20 -O2 $@
                ./$o
              '';
              py = pkgs.python311.withPackages (ps:
                with ps; [
                  jupyter
                  ipykernel

                  matplotlib
                  numpy
                  scipy
                ]);
            in [
              mymake

              cppcheck
              valgrind

              gdb

              pkg-config
              meson
              ninja
              cmake

              clang-tools_17
              # llvm.clang
              # llvm.libcxxClang
              # llvm.libcxx
              # llvm.libllvm

              py
            ];

            buildInputs = with pkgs; [
              # boost184
              # nlohmann_json
            ];
          };
      };
    };
}
