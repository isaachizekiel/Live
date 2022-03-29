BUILD_DIR=$PWD/build
CLEAN=$1
INSTALL_DIR=/home/izak/install/linux-x86_64

if [ ! -d "$BUILD_DIR" ]; then
    mkdir $BUILD_DIR
fi

cd $BUILD_DIR

if [ ! -z "$CLEAN" ]; then
    if [ $CLEAN == "clean" ]; then
	rm -rf *
    else
	echo "..."
    fi    
fi

# help cmake find pkgconfig
export PKG_CONFIG_PATH=$INSTALL_DIR/lib/pkgconfig
echo $INSTALL_DIR/lib/pkgconfig
cmake -G Ninja -S .. -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR
cmake --build .
