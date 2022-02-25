<<com

Write a shell script that accepts two filenames as arguments, checks if the permissions for
these files are identical and if the permissions are identical, output common permissions
otherwise output each filename followed by its permissions.

com

if [ -e $1 ] && [ -e $2 ]
then
set -- `ls -ld $file1`
file1perm=$1
set -- `ls -ld $file2`
file2perm=$1
if [ "$file1perm" = "$file2perm" ]
then
echo "File Permission are identical"
echo "Permission is $file1perm"
else
echo "File Permission are not identical"
echo "$file1 Permission is $file1perm"
echo "$file2 Permission is $file2perm"
fi
fi
