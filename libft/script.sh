# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machaq <machaq@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 18:09:35 by machaq            #+#    #+#              #
#    Updated: 2024/11/02 17:37:55 by machaq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if git diff --quiet && git diff --cached --quiet; then
    echo "No changes to push."
    exit 0
fi

COMMIT_MSG=${1:-"Auto commit on $(date)"}

git add .
git commit -m "Update libft"
git push origin main  
echo "Changes have been pushed to the repository!"

