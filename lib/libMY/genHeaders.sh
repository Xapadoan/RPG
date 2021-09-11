#!/bin/bash
DIR=$1
FILE=$2
DEF=$3
#SAVE_IFS=$IFS
#IFS=$'\n'
HEADERS=($(ls $1/includes))

echo "#ifndef DEF_$DEF" > $FILE;
echo "#define DEF_$DEF" >> $FILE;
echo "" >> $FILE;
for HEADER in "${HEADERS[@]}";do
	echo "#include \"$DIR/includes/$HEADER\"" >> $FILE;
done;
echo $'\n'#endif >> $FILE;

#IFS=$SAVE_IFS
exit 0
