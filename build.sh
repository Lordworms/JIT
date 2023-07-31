usage(){
cat <<EOF
Usage $0 [-t debug | release]
      Or
      $0 [-h | --help]
-t    Build type choose debug or release, like "build.sh -t debug/release"
EOF
}

parse_options(){
    while test $# -gt 0 # 
    do 
        case "$1" in
        -h | --help)
            usage
            exit 0;;
        -t)
            shift
            build_type="$1";;
        esac
        shift
    done
}

parse_options "$@"
echo "build_type is: $build_type"

if [ x"$build_type" = x"debug" ]; then # x is a character to make sure the compared strings are not empty
  build_type="Debug"
  fdebug=1
elif [ x"$build_type" = x"release" ]; then
  build_type="release"
  fdebug=1
else 
  echo "Build type should be debug or release"
  exit 1
fi

echo "build_type is: $build_type"

