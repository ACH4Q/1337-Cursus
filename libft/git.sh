#!/bin/bash

if git diff --quiet && git diff --cached --quiet; then
    echo "No changes to push."
    exit 0
fi

COMMIT_MSG=${1:-"Auto commit on $(date)"}

git add .
git commit -m "Add new function in Libft"
git push origin main  
echo "Changes have been pushed to the repository!"
