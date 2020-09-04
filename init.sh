#!/bin/sh

echo "Project name: $1"

if [ $# -ne 1 ]
then
    echo "You call this script wtth wrong arguments."
    echo "Example for start script:"
    echo "./init.sh MyCmakeProject"
    exit 1
fi

REPLACESTRING="s+RENAME_ME+$1+g"
echo $REPLACESTRING

find . -type f -exec sed -i $REPLACESTRING {} +
find . -type f -exec sed -i $REPLACESTRING {} +
#find . -type f -exec sed -i 's+http://example.com+https://example.com+g' {} +

set -e

git config -f .gitmodules --get-regexp '^submodule\..*\.path$' |
    while read path_key path
    do
        url_key=$(echo $path_key | sed 's/\.path/.url/')
        url=$(git config -f .gitmodules --get "$url_key")
        git submodule add $url $path
    done



