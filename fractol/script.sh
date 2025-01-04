#!/bin/bash
# Check if there are changes to commit
if git diff --quiet && git diff --cached --quiet; then
    echo "No changes to push."
    exit 0
fi
# Default commit message if not provided as an argument
COMMIT_MSG=${1:-"Auto commit on $(date)"}
# Git commands
git add .
git commit -m "Update Fractol"
git push origin main  # Change 'main' if your branch name is different
# Confirm success
echo "Changes have been pushed to the repository!"