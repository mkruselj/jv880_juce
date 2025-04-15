ROOT=$(cd "$(dirname "$0")/.."; pwd)

"$ROOT/build/bin/JUCE/Projucer" --resave "$ROOT/jv880.jucer"

cd "$ROOT/Builds/LinuxMakefile"
make CONFIG=Release
