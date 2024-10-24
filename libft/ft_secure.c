/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:54:46 by machaq            #+#    #+#             */
/*   Updated: 2024/10/24 09:54:50 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// Securely clear the buffer using volatile to avoid optimization.
void secure_memset(void *ptr, int value, size_t len) {
    volatile char *p = (volatile char *)ptr;  // Use volatile
    while (len--) {
        *p++ = value;
    }
}

// Regular memset without volatile (could be optimized away).
void non_secure_memset(void *ptr, int value, size_t len) {
    char *p = (char *)ptr;  // No volatile
    while (len--) {
        *p++ = value;
    }
}

int main() {
    char sensitive_data[] = "SECRET_PASSWORD";  // Data to be cleared
    char buffer[sizeof(sensitive_data)];

    // Test 1: Using non-secure memset (may get optimized away)
    strcpy(buffer, sensitive_data);  // Copy sensitive data to buffer
    printf("Before non-secure memset: %s\n", buffer);
    non_secure_memset(buffer, 0, sizeof(buffer));
    printf("After non-secure memset: %s\n", buffer);  // May still print garbage

    // Test 2: Using secure memset with volatile (will not be optimized away)
    strcpy(buffer, sensitive_data);  // Reset the buffer
    printf("\nBefore secure memset: %s\n", buffer);
    secure_memset(buffer, 0, sizeof(buffer));
    printf("After secure memset: %s\n", buffer);  // Should print an empty string

    return 0;
}
