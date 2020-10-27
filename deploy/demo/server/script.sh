#!/bin/bash

# get htdoc position
HDOC=$1;
echo $HDOC

# go to script position
cd $(dirname $0)/../../../system;
DIR=$(pwd); # system directory

# confirm process
read -p "are you sure setting server in directory '$HDOC' [Y/N] ?" confirm_var
if [[ $confirm_var != 'Y' ]]
then
  echo "Discard process";
fi

# copy USTHServer to HDOC
sudo cp -r $DIR/USTHserver $HDOC;

# copy Generatedb to HDOC
sudo cp $DIR/database/generatedb.php $HDOC;

# create database
cd $DIR/database;
./script;

# generate data in database
echo "process finished !!!";
echo "please run generatedb.php in '$HDOC' to generate db";
echo "after that, you can delete that file !!!";
