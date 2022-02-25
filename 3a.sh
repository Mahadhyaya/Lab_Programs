<<com

Create a script file called file properties that reads a filename entered and outputs it
properties..

com

if [ -e $1 ]
then
set -- `ls -ld $1`
echo "Permission are: $1"
echo "File link counts: $2"
echo "User: $3"
echo "Group User:$4"
echo "File Modification is done on $5 $6 $7 at $8"
echo "File name: $9"
else
echo "File does not exits"
fi
