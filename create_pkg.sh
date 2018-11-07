if [ $# -ne 1 ]
then
  echo "Usage: $0 <pkg_name>"
  exit $E_BADARGS
fi

mkdir -p $1/include/$1
mkdir -p $1/src
cp _CMakeLists.txt $1/CMakeLists.txt
cp _package.xml $1/package.xml
echo Succesfully created packge $1
echo Please modify package.xml and CMakeLists.txt manually
