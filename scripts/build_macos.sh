#!/bin/bash
echo -e "\033[0;32mHow many CPU cores do you want to be used in compiling process? (Default is 1. Press enter for default.)\033[0m"
read -e CPU_CORES
if [ -z "$CPU_CORES" ]
then
	CPU_CORES=1
fi

# Clone MCPC code from deviant official Github repository
	git clone https://github.com/Deviantcoin/Wallet-4.1.x deviant

# Entering deviant directory
	cd deviant


# Compile dependencies
	cd depends
	make -j$(echo $CPU_CORES) HOST=x86_64-apple-darwin17
	cd ..

# Compile deviant components eg daemon, cli, tx & qt
	./autogen.sh
	./configure --prefix=$(pwd)/depends/x86_64-apple-darwin17 --enable-cxx --enable-static --disable-shared --disable-debug --disable-tests --disable-bench
	make -j$(echo $CPU_CORES) HOST=x86_64-apple-darwin17
	make deploy
	cd ..

# Create zip file of binaries
cp deviant/src/deviantd.dmg deviant/src/deviant-cli.dmg deviant/src/deviant-tx.dmg deviant/src/qt/deviant-qt.dmg .
zip deviant-Linux.zip deviantd.dmg deviant-cli.dmg deviant-tx.dmg deviant-qt.dmg
rm -f deviantd.dmg deviant-cli.dmg deviant-tx.dmg deviant-qt.dmg
